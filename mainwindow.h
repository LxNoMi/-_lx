#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma execution_character_set("utf-8")

#include <QMainWindow>
#include<QListWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
private slots:
    void addCitySlot();
    void delCitySlot();
    void delAllSlot();
    void showFileSlot();
    void singleClickedSlot(QListWidgetItem *);
    void doubleClickedSlot(QListWidgetItem *);
};

#endif // MAINWINDOW_H
