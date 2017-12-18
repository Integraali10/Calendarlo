#ifndef CALENDARWIDGET_H
#define CALENDARWIDGET_H

#include <QWidget>
#include <QCalendarWidget>
#include <QGridLayout>
#include <QListWidget>
#include <QLabel>
#include <QTextCharFormat>
#include <QWheelEvent>
#include <QMap>
#include <QDate>
#include <QRadioButton>
#include <QGroupBox>
#include <QMouseEvent>
struct work_shift{
    int work;
    int free;
};

class calendarwidget : public QWidget
{

    Q_OBJECT
public:
    explicit calendarwidget(QWidget *parent = 0);
    ~calendarwidget();

    void chooseDate(work_shift shift, QCalendarWidget *calendar);
    void drowCalendar(int, int);
    void drowVoc(QDate, QDate);
    void drowHol();
    void paint_calendar();
    void clear_widget();
    void orient_album();
    void orient_port();
    //void mousePressEvent(QMouseEvent *event);
    void set_Data(QString fio, int current_orient, int day, int month, int year);
    void set_Voc(QDate begin, QDate end);
    void addData();
    int retDaysInMonth(int month, int year);
    QPixmap get_print();
    work_shift shift;
    int change, free, work;
    bool flag;
signals:
    void workSignal(QDate);
    void vocSignal(QDate);
public slots:
    void changeFormat(QDate value);
    void setCursorFlag(int value);
private:
    int cursorFlag;
    QGridLayout *gridLayout;
    QList<QCalendarWidget*> *list;
    QList<QLabel*> *list_lable;
    QLabel *label_year;
    QLabel *label_fio;
    int orientOfCalendar = 0;
    int start_day;
    int start_month;
    int start_year;
    QMap <int, QString> nameOfMonth;
    QList <QList<int>> holidays;
    QDate begin_voc;
    QDate end_voc;
    void closeEvent(QCloseEvent *event);
};

class CursorWidget: public QWidget
{
     Q_OBJECT
public:
    explicit CursorWidget(QWidget *parent = 0);
    ~CursorWidget();
public slots:
    void changeDef(bool);
signals:
    void Def(int);
private:
    QGridLayout *gridLayout;
    QGroupBox *coursorBox;
    QGroupBox *setCursorDefinition();
    QRadioButton *radioN;
    QRadioButton *radioV;
    QRadioButton *radioW;
    void closeEvent(QCloseEvent *event);
};
#endif // CALENDARWIDGET_H


