#include "app/operator_model_tree.h"
#include "app/icon_delegate.h"

gnc::OperatorModelTree::OperatorModelTree(QWidget* parent) :
    QTreeWidget(parent)
{
    // TODO
    m_db = std::make_shared<DBConnector>("OM system.db");

    IconDelegate* iconDelegate = new IconDelegate(this);
    this->setItemDelegateForColumn(0, iconDelegate);
}

void gnc::OperatorModelTree::loadData()
{
    std::string query = R"(
            SELECT
            countries.mcc,
            countries.mnc_length,
            countries.code,
            countries.name,
            operators.mnc,
            operators.name
            FROM countries
            LEFT JOIN operators
            ON countries.mcc = operators.mcc;
        )";

    gnc::type::QueryResult queries = m_db->selectQuery(query);

    for (const auto& query : queries) {
        uint16_t mcc = static_cast<uint16_t>(std::stoi(query[0]));
        uint16_t mncLength = static_cast<uint16_t>(std::stoi(query[1]));
        std::string code = query[2];
        std::string countryName = query[3];

        if (!m_countriesMobile.contains(code)) {
            gnc::CountryMobile country{mcc, mncLength, countryName, {}};
            m_countriesMobile[code] = country;
        }

        if (!query[4].empty()) {
            uint16_t mnc = static_cast<uint16_t>(std::stoi(query[4]));
            std::string operatorName = query[5];
            m_countriesMobile[code].operators.emplace_back(mnc, operatorName);
        }
    }
}

void gnc::OperatorModelTree::showTree()
{
    setHeaderLabel("Network Codes");

    for(const auto& countryMobile : m_countriesMobile)
    {
        QTreeWidgetItem* countryItem = new QTreeWidgetItem(this);
        std::string countryItemText = countryMobile.second.name + " (" + countryMobile.first + ")";
        std::string countryItemIcon = ":/icons/png/countries/" + countryMobile.first + ".png";

        countryItem->setText(0, QString::fromStdString(countryItemText));
        countryItem->setData(0, Qt::UserRole, QString::fromStdString(countryItemIcon));

        /*for(const auto& oper : countryMobile.second.operators)
        {
            QTreeWidgetItem* operatorItem = new QTreeWidgetItem(countryItem);
            std::string operatorItemText = oper.name + " (" +
                                            std::to_string(countryMobile.second.mcc) + "-" +
                                            std::to_string(oper.mnc) + ")";

            std::string operatorItemIcon = std::string(":/icons/") + oper.name

            operatorItem->setText(0, operatorItemText.c_str());
            operatorItem->setData(0, Qt::UserRole, operatorItemIcon);
        }*/
    }

    expandAll();
}
