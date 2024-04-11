//
// Created by User on 11.04.2024.
//

#ifndef GRAPHPLOTTER_CREATEPOINTSTABDIALOG_H
#define GRAPHPLOTTER_CREATEPOINTSTABDIALOG_H

#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class CreatePointsTabDialog; }
QT_END_NAMESPACE

class CreatePointsTabDialog : public QDialog {
Q_OBJECT

public:
    explicit CreatePointsTabDialog(QWidget *parent = nullptr);

    ~CreatePointsTabDialog() override;

private:
    Ui::CreatePointsTabDialog *ui;
};


#endif //GRAPHPLOTTER_CREATEPOINTSTABDIALOG_H
