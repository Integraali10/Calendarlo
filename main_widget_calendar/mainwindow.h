#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QDateEdit>
#include <QGroupBox>
#include <QDate>
#include <QLineEdit>
#include "calendarwidget.h"


class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void save_Calendar();
    void print_Calendar();
    void open_Data();
    void show_Calendar();
    void changeDay();
    void changeMonth();
    void changeYear();
    void changeGraphic();
    void changeOrientation();
    void changeFromVocation();
    void changeToVocation();
    void changeChange();
    void on_about();
    void workSlot(QDate value);
    void vocSlot(QDate value);


private:
    void createWindow();
    void addData();
    QDate countVocation();
    void getVersion();

    calendarwidget *calendar;
    CursorWidget *cursor;

    QString currentYear;

    QPushButton *open;
    QPushButton *save;
    QPushButton *print;
    QPushButton *view;
    QPushButton *about;

    QGroupBox *fioGroupBox;
    QLineEdit *fioLineEdit;

    QLabel *day_label;
    QLabel *month_label;
    QLabel *year_label;
    QComboBox *dayComboBox;
    QComboBox *monthComboBox;
    QComboBox *yearComboBox;

    QLabel *change_label;
    QLabel *orient_label;
    QLabel *graphic_label;
    QComboBox *changeComboBox;
    QComboBox *orientComboBox;
    QComboBox *graphicComboBox;

    QGroupBox *vocationGroupBox;
    QLabel *from_label;
    QLabel *to_label;
    QDateEdit *from;
    QDateEdit *to;
    QLabel *voc_quantity;

    QString version;
    int choosen_day;
    int choosen_month;
    int choosen_year;
};

#endif // MAINWINDOW_H
