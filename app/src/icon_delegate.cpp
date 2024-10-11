#include "app/icon_delegate.h"

// DELETE
//#include <QDebug>
//#include <QUrl>
//#include <QIcon>
//#include <QString>

void gnc::IconDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    QString iconPath = index.data(Qt::UserRole).toString();

    iconPath = "qrc:/png/countries/AD.png";

    /*if (!iconPath.isEmpty()) {
        // Загружаем иконку из ресурса
        QIcon icon(iconPath);

        // Если иконка пустая, выводим сообщение
        if (icon.isNull()) {
            qDebug() << "Icon not found at path:" << iconPath;
        }
        else {
            // Если иконка найдена, рисуем ее
            QRect iconRect = option.rect;
            iconRect.setWidth(16);
            icon.paint(painter, iconRect, Qt::AlignLeft | Qt::AlignVCenter);
        }
    }*/

    // Рисуем текст с применением пользовательских стилей
    QString text = index.data(Qt::DisplayRole).toString();  // Получаем текст элемента
    QRect textRect = option.rect;
    textRect.setLeft(option.rect.left() + 16 + 5);  // Сдвигаем текст вправо, чтобы не накладывался на иконку

    // Устанавливаем шрифт
    QFont font = option.font;
    font.setBold(true);  // Жирный текст
    font.setPointSize(10);  // Размер шрифта
    painter->setFont(font);

    // Устанавливаем цвет текста
    painter->setPen(QPen(Qt::blue));  // Цвет текста (синий)

    // Рисуем текст
    painter->drawText(textRect, Qt::AlignVCenter | Qt::AlignLeft, text);
}

/*QSize gnc::IconDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QSize(32, 32);
}*/
