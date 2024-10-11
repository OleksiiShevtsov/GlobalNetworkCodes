#pragma once

#include <QStyledItemDelegate>
#include <QPainter>
#include <QIcon>
#include <QPixmap>

namespace gnc
{
    class IconDelegate : public QStyledItemDelegate
    {
    public:
        IconDelegate(QObject* parent = nullptr) : QStyledItemDelegate(parent) {}

        void paint(QPainter* painter, const QStyleOptionViewItem& option,
                   const QModelIndex& index) const override;

        //QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    };
}
