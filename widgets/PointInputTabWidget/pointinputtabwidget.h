//
// Created by User on 11.04.2024.
//

#ifndef GRAPHPLOTTER_POINTINPUTTABWIDGET_H
#define GRAPHPLOTTER_POINTINPUTTABWIDGET_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class PointInputTabWidget; }
QT_END_NAMESPACE

class PointInputTabWidget : public QWidget {
Q_OBJECT

public:
    explicit PointInputTabWidget(QWidget *parent = nullptr);

    ~PointInputTabWidget() override;

private:
    Ui::PointInputTabWidget *ui;
};


#endif //GRAPHPLOTTER_POINTINPUTTABWIDGET_H
