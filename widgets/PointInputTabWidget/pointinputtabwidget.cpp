//
// Created by User on 11.04.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_PointInputTabWidget.h" resolved

#include "pointinputtabwidget.h"
#include "ui_PointInputTabWidget.h"


PointInputTabWidget::PointInputTabWidget(QWidget *parent) :
        QWidget(parent), ui(new Ui::PointInputTabWidget) {
    ui->setupUi(this);
}

PointInputTabWidget::~PointInputTabWidget() {
    delete ui;
}
