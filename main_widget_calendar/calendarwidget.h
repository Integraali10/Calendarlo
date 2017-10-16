#ifndef CALENDARWIDGET_H
#define CALENDARWIDGET_H

#include <QWidget>
#include <QCalendarWidget>
#include <QGridLayout>
#include <QListWidget>
#include <QLabel>
#include <QTextCharFormat>
#include <QWheelEvent>

struct work_shift{
    int work=1;
    int free=1;
};

class calendarwidget : public QWidget
{
public:
    explicit calendarwidget(QWidget *parent = 0);
    ~calendarwidget();

    void chooseDate(work_shift shift, QCalendarWidget *calendar);
    void drowCalendar(int, int);
    void paint_calendar();
    void clear_widget();
    void orient_album();
    void orient_port();
    void set_Data(QString fio, int current_orient, int day, int month, int year);
    void addData();
    QPixmap get_print();
    work_shift shift;
    int change = 0, free = 0, work = 0, orient = 0;

private:
    bool flag;
    QGridLayout *gridLayout;
    QList<QCalendarWidget*> *list;
    QList<QLabel*> *list_lable;
    QLabel *label_year;
    QLabel *label_fio;
    int orientOfCalendar;
    int start_day;
    int start_month;
    int start_year;
    void wheelEvent(QWheelEvent *event);


};

#endif // CALENDARWIDGET_H
