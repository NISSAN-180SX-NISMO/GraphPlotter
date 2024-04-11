//
// Created by User on 10.04.2024.
//

#ifndef GRAPHPLOTTER_MAINWINDOW_H
#define GRAPHPLOTTER_MAINWINDOW_H

#include <QMainWindow>
#include <QCustomPlot.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
};


#endif //GRAPHPLOTTER_MAINWINDOW_H
