#include "calendarwidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>


calendarwidget::calendarwidget(QWidget *parent) : QWidget(parent)
{
    qDebug() << "constructor";
    setWindowTitle("Work Timetable");
    addData();
    paint_calendar();
}

void calendarwidget::addData()
{
    qDebug() << "add Data";
    gridLayout = new QGridLayout ();
    label_year= new QLabel();
    label_fio = new QLabel();
    list = new QList<QCalendarWidget*>();
    list_lable = new QList<QLabel*>();

    QHBoxLayout *fio_layout = new QHBoxLayout;
    fio_layout->addWidget(label_fio);
    fio_layout->addStretch();
    fio_layout->addStretch();

    QHBoxLayout *year_layout = new QHBoxLayout;
    year_layout->addStretch();
    year_layout->addWidget(label_year);
    year_layout->addStretch();

    QVBoxLayout *main_layout = new QVBoxLayout;
    main_layout->addLayout(fio_layout);
    main_layout->addLayout(year_layout);
    main_layout->addLayout(gridLayout);

    setLayout(main_layout);
}

void calendarwidget::drowCalendar(int year, int month)
{
    qDebug() << "drowCalendar";
    int tmp_month = month;
    flag = true;                          //true-work, false-free
    for (int y = year;  y < year + 1; y++)
    {
        for (int m = 0; m < 12; m++)
        {
            if(tmp_month == 12)
            {
                tmp_month = 1;
            }
            list->at(tmp_month-1)->setCurrentPage(y, m + 1);
            list->at(tmp_month-1)->setSelectionMode(QCalendarWidget::NoSelection);
            tmp_month++;
        }
        for (int i = 0; i < 12; i++)
        {
            chooseDate(shift, list->at(i));  //function for drowing sheldue on the calendar
        }
    }
}

void calendarwidget::chooseDate(work_shift shift, QCalendarWidget *calendar)
{
    qDebug() << "choose Data";
    int year = calendar->yearShown();
    int month = calendar->monthShown();
    int days;
    QTextCharFormat format;
    QTextCharFormat format2;

    switch(month)
    {
    case 2:
        if(((year % 4 == 0)&(year % 100 != 0))||(year % 400 == 0))
        {
            days = 29;
        }
        else
        {
            days = 28;
        }
        break;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        days=31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        days = 30;
        break;
    }

    format.setBackground(Qt::lightGray);
    format2.setBackground(Qt::white);

    for (int i = 1; i < days + 1;)
    {
        calendar->setDateTextFormat({year,month,i},format2);
        if (flag == true)
        {
            if (work == shift.work)
            {
                work = 0;
                flag = false;
            }
            else
            {
              /*  if (backgr == 1)
                {
                    if (work == 0)
                    {
                        format.setBackground(QColor(255,241,64,150));
                    }
                    if (work == 1)
                    {
                        format.setBackground(QColor(70,113,213,170));

                        */
                calendar->setDateTextFormat({year,month,i},format);
                work++;
                if (work == shift.work)
                {
                    work=0;
                    flag=false;
                }
                i++;
            }
        }
        else if (flag == false)
        {
            free++;
            if (free == shift.free)
            {
                free = 0;
                flag = true;
            }
            i++;
        }
    }
}

void calendarwidget::paint_calendar()
{
    qDebug() << "paint calendar";
    QCalendarWidget *calendar_1 = new QCalendarWidget;
    QCalendarWidget *calendar_2 = new QCalendarWidget;
    QCalendarWidget *calendar_3 = new QCalendarWidget;
    QCalendarWidget *calendar_4 = new QCalendarWidget;
    QCalendarWidget *calendar_5 = new QCalendarWidget;
    QCalendarWidget *calendar_6 = new QCalendarWidget;
    QCalendarWidget *calendar_7 = new QCalendarWidget;
    QCalendarWidget *calendar_8 = new QCalendarWidget;
    QCalendarWidget *calendar_9 = new QCalendarWidget;
    QCalendarWidget *calendar_10 = new QCalendarWidget;
    QCalendarWidget *calendar_11 = new QCalendarWidget;
    QCalendarWidget *calendar_12 = new QCalendarWidget;
    list->append(calendar_1);
    list->append(calendar_2);
    list->append(calendar_3);
    list->append(calendar_4);
    list->append(calendar_5);
    list->append(calendar_6);
    list->append(calendar_7);
    list->append(calendar_8);
    list->append(calendar_9);
    list->append(calendar_10);
    list->append(calendar_11);
    list->append(calendar_12);
    for (int i = 0; i < 12; i++)
    {
        list->at(i)->setNavigationBarVisible(false);
        list->at(i)->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
    }
    QLabel *label_1 = new QLabel(calendar_1);
    QLabel *label_2 = new QLabel(calendar_2);
    QLabel *label_3 = new QLabel(calendar_3);
    QLabel *label_4 = new QLabel(calendar_4);
    QLabel *label_5 = new QLabel(calendar_5);
    QLabel *label_6 = new QLabel(calendar_6);
    QLabel *label_7 = new QLabel(calendar_7);
    QLabel *label_8 = new QLabel(calendar_8);
    QLabel *label_9 = new QLabel(calendar_9);
    QLabel *label_10 = new QLabel(calendar_10);
    QLabel *label_11 = new QLabel(calendar_11);
    QLabel *label_12 = new QLabel(calendar_12);
    label_1->setText("Январь");
    label_2->setText("Февраль");
    label_3->setText("Март");
    label_4->setText("Апрель");
    label_5->setText("Май");
    label_6->setText("Июнь");
    label_7->setText("Июль");
    label_8->setText("Август");
    label_9->setText("Сентябрь");
    label_10->setText("Октябрь");
    label_11->setText("Ноябрь");
    label_12->setText("Декабрь");

    list_lable->append(label_1);
    list_lable->append(label_2);
    list_lable->append(label_3);
    list_lable->append(label_4);
    list_lable->append(label_5);
    list_lable->append(label_6);
    list_lable->append(label_7);
    list_lable->append(label_8);
    list_lable->append(label_9);
    list_lable->append(label_10);
    list_lable->append(label_11);
    list_lable->append(label_12);
}

void calendarwidget::clear_widget()
{
    qDebug() << "clear_widget";
    for(int i = 0; i < list->size(); i++){
        gridLayout->removeWidget(list->at(i));
    }
    for(int i = 0; i < list_lable->size(); i++){
        gridLayout->removeWidget(list_lable->at(i));
    }
    this->resize(0,0);
}

void calendarwidget::orient_port()
{
    qDebug() << "porto";
    this->resize(400, 600);
    this->updateGeometry();
    int m = 0;
    int l = 0;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 3; j++){
            if (i%2 == 0){
                gridLayout->addWidget(list_lable->at(l), i,j, Qt::AlignCenter);
                list_lable->at(l)->setContentsMargins(0, 20, 0 ,0);
                l++;
            }
            else {
                gridLayout->addWidget(list->at(m), i, j,  Qt::AlignJustify);
                list->at(m)->setContentsMargins(10, 0, 10, 0);
                m++;
            }
        }
    }
    gridLayout->setContentsMargins(0, 10,0,20);
    this->setMaximumWidth(400);
    this->resize(400, 600);
    label_year->setGeometry(300, 10, 30, 20);
}

void calendarwidget::orient_album()
{
    qDebug() << "album";
    this->resize(600, 400);
    this->resize(0,0);
    int m = 0;
    int l = 0;
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 4; j++){
            if (i%2 == 0){
                gridLayout->addWidget(list_lable->at(l), i,j, Qt::AlignCenter);
                list_lable->at(l)->setContentsMargins(0, 20, 10 ,10);
                l++;
            }
            else {
                gridLayout->addWidget(list->at(m), i, j,  Qt::AlignJustify);
                list->at(m)->setContentsMargins(10, 0, 10, 0);
                m++;

            }
        }
    }
    gridLayout->setContentsMargins(10, 20,10,20);
    this->setMaximumHeight(400);
    this->resize(gridLayout->sizeHint().width(), 10);
    label_year->setGeometry(400, 10, 30, 20);
}

QPixmap calendarwidget::get_print()
{
    qDebug() << "print";
    QPixmap snapShot;
    snapShot=QWidget::grab();
    //snapShot.save("snapshot.png");
    return snapShot;
}

void calendarwidget::set_Data(QString fio, int day, int month, int year, int current_orient)
{
    qDebug() << "set Data";
    orientOfCalendar = current_orient;
    start_day = day;
    start_month = month;
    start_year = year;
    label_fio->setText(fio);
    if (month != 1)
    {
        label_year->setText(QString::number(start_year) + "/" + QString::number(start_year + 1));
    }
    else
    {
        label_year->setText(QString::number(start_year));
    }

}

void calendarwidget::wheelEvent(QWheelEvent *event)
{
    qDebug() << "wheel Event";
    event->ignore();
}

calendarwidget::~calendarwidget()
{
    delete gridLayout;
    delete list;
    delete list_lable;
    delete label_year;
}

