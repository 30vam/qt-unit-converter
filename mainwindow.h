#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    int indexOfItemInParent;
    int indexOfParent;

private slots:
    void on_conversionTypeTreeWidget_itemSelectionChanged();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
