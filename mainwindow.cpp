#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QListWidget>
#include <QListWidgetItem>
#include<QStringList>
#include<QMessageBox>
#include<QDir>
#include<QDebug>
#include<QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget->setViewMode(QListView::IconMode);
    QObject::connect(ui->addCityButton,SIGNAL(clicked()),this,SLOT(addCitySlot()));
    QObject::connect(ui->cityNameEdit,SIGNAL(returnPressed()),this,SLOT(addCitySlot()));
    QObject::connect(ui->delCityButton,SIGNAL(clicked()),this,SLOT(delCitySlot()));
    QObject::connect(ui->delAllButton,SIGNAL(clicked()),this,SLOT(delAllSlot()));
    QObject::connect(ui->showAllButton,SIGNAL(clicked()),this,SLOT(showFileSlot()));
    QObject::connect(ui->listWidget,SIGNAL(itemClicked(QListWidgetItem *)),this,SLOT(singleClickedSlot(QListWidgetItem *)));
    QObject::connect(ui->listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem *)),this,SLOT(doubleClickedSlot(QListWidgetItem *)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//添加城市
void MainWindow::addCitySlot()
{
    QString cityName = ui->cityNameEdit->text().trimmed();
    QListWidgetItem *item=new QListWidgetItem;
    item->setText(cityName);
    ui->listWidget->addItem(item);
    ui->cityNameEdit->clear();
}

//删除一个选中城市
void MainWindow::delCitySlot()
{
    QListWidgetItem *item = ui->listWidget->takeItem(ui->listWidget->currentRow());
    delete item;
}

//删除所有
void MainWindow::delAllSlot()
{
    int counts=ui->listWidget->count();
    for(int index=0;index<counts;index++)
    {
        QListWidgetItem *item = ui->listWidget->takeItem(ui->listWidget->currentRow());
        delete item;
    }
}

//显示文件
void MainWindow::showFileSlot()
{
    QDir dir=QDir::currentPath();
    QStringList fileNames=dir.entryList();
    if(fileNames.size()==0)
    {
        QMessageBox::information(this,"error:","have no file here!");
        return ;
    }
    for(int index=0;index<fileNames.size();index++)
    {
        if(fileNames.at(index)=="."||fileNames.at(index)=="..")
            continue;
        QListWidgetItem *item=new QListWidgetItem;
        item->setText(fileNames.at(index));
        ui->listWidget->addItem(item);
    }
}

void MainWindow::singleClickedSlot(QListWidgetItem *item)
{
    QMessageBox::information(this,"提示:","文件夹"+item->text()+"被单击!");
}

void MainWindow::doubleClickedSlot(QListWidgetItem *item)
{
    QMessageBox::information(this,"提示:","文件夹"+item->text()+"被双击!");
}
