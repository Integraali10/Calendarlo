#include "calendarwidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>


calendarwidget::calendarwidget(QWidget *parent) : QWidget(parent)
{
    //qDebug() << "constructor";
    setWindowTitle("Work Timetable");
    cursorFlag=0;
    indexMonth=0;
    addData();
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

    QHBoxLayout *year_layout = new QHBoxLayout;
    year_layout->addStretch();
    year_layout->addWidget(label_year);
    year_layout->addStretch();

    QVBoxLayout *main_layout = new QVBoxLayout;
    main_layout->addLayout(fio_layout);
    main_layout->addLayout(year_layout);
    main_layout->addLayout(gridLayout);

    nameOfMonth.insert(1, "Январь");
    nameOfMonth.insert(2, "Февраль");
    nameOfMonth.insert(3, "Март");
    nameOfMonth.insert(4, "Апрель");
    nameOfMonth.insert(5, "Май");
    nameOfMonth.insert(6, "Июнь");
    nameOfMonth.insert(7, "Июль");
    nameOfMonth.insert(8, "Август");
    nameOfMonth.insert(9, "Сентябрь");
    nameOfMonth.insert(10, "Октябрь");
    nameOfMonth.insert(11, "Ноябрь");
    nameOfMonth.insert(12, "Декабрь");

    holidays.append({0, 1, 2, 3, 4, 5, 6, 7, 8 });
    holidays.append({1, 23 });
    holidays.append({2, 8 });
    holidays.append({4, 1 ,9});
    holidays.append({5, 12});
    holidays.append({10, 4});

    setLayout(main_layout);

    shift.work = 1;
    shift.free = 1;
    change = 0;

    orientOfCalendar = 0;
    flag = true;
}

void calendarwidget::changeFormat(QDate value)
{

    if(cursorFlag==2)
    {
        emit workSignal(value);
        return;
    }
    if(cursorFlag==1)
    {
        emit vocSignal(value);
        return;
    }

}
void calendarwidget::drowCalendar(int year, int month)
{
    qDebug() << "drowCalendar";
    int tmp_month = month;

    int tmp = 0;
    for (int y = year;  y < year + 1; y++)
    {
        for (int m = start_month - 1; tmp < 12; m++)
        {
            if (m == 12)
            {
                m = 0;
                y++;
            }
            list->at(m)->setCurrentPage(y, m + 1);
            chooseDate(shift, list->at(m));

            tmp_month++;
            tmp++;
        }
    }
    drowHol();
    drowVoc(begin_voc, end_voc);

}

void calendarwidget::drowVoc(QDate begin_voc, QDate end_voc)
{
    qDebug() << "drowVoc";
    QTextCharFormat format;
    format.setBackground(QColor(255,241,64,150));
    int days;
    int month = begin_voc.month();
    int year = begin_voc.year();
    days = retDaysInMonth(month, year);
    //qDebug() << begin_voc;
    QCalendarWidget *calendar = list->at(begin_voc.month() - 1);
    if(begin_voc.month()!=end_voc.month())
    {
        for (int i = begin_voc.day(); i < days + 1; i++)
        {
            QTextCharFormat tmpFormat =calendar->dateTextFormat({year,month,i});
            format.setForeground(tmpFormat.foreground());
            calendar->setDateTextFormat({year,month,i},format);
        }
        //qDebug() << end_voc.month()-1;
        calendar = list->at(end_voc.month()- 1);
        month = end_voc.month();
        year = end_voc.year();
        for (int i = 1; i < end_voc.day() + 1; i++)
        {
            QTextCharFormat tmpFormat =calendar->dateTextFormat({year,month,i});
            format.setForeground(tmpFormat.foreground());
            calendar->setDateTextFormat({year,month,i},format);
        }
    }
    else
    {
        for (int i = begin_voc.day(); i<end_voc.day() + 1; i++)
        {
            //qDebug() << i;
            QTextCharFormat tmpFormat =calendar->dateTextFormat({year,month,i});
            format.setForeground(tmpFormat.foreground());
            calendar->setDateTextFormat({year,month,i},format);
        }
    }
}

void calendarwidget::drowHol()
{
    qDebug() << "drow Hol";
    QTextCharFormat format,formatwh;
    format.setBackground(Qt::white);
    format.setForeground(Qt::red);
    formatwh.setBackground(QColor(100,200,64,150));
    formatwh.setForeground(Qt::red);

    for (int i =0; i<holidays.size(); i++)
    {
        QList<int> tmp = holidays[i];
        QCalendarWidget *calendar = list->at(tmp[0]);
        int year = calendar->yearShown();
        int month = calendar->monthShown();
        for(int j = 1; j<tmp.size(); j++)
        {
           QTextCharFormat tmpFormat =calendar->dateTextFormat({year,month,tmp[j]});
           if (tmpFormat.background().color() != QColor(255, 255, 255, 255))
               calendar->setDateTextFormat({year,month,tmp[j]},formatwh);
           else calendar->setDateTextFormat({year,month,tmp[j]},format);
        }
    }

}

int calendarwidget::retDaysInMonth(int month, int year)
{
    int days = 0;
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

    return days;
}

void calendarwidget::chooseDate(work_shift shift, QCalendarWidget *calendar)
{
    qDebug() << "choose Data ";
    int year = calendar->yearShown();
    int month = calendar->monthShown();
    int days;
    QTextCharFormat format;
    QTextCharFormat format2;
    QTextCharFormat formatwh;
    calendar->setCurrentPage(year, month);
    calendar->setMinimumDate(QDate(year,month,1));
    days = retDaysInMonth(month, year);
    calendar->setMaximumDate(QDate(year,month,days));
    format.setBackground(QColor(70,113,213,170));
    format2.setBackground(Qt::white);
    formatwh.setBackground(QColor(100,200,64,150));
    formatwh.setForeground(Qt::red);
    int day_st = 1;
    if(month == start_month)
    {
        if(change == 1)
        {
            day_st = start_day + shift.free;
            calendar->setDateTextFormat({year,month,start_day},format2);
            work = 0;
            free = shift.free;
            flag = false;
        }
        else
        {
            day_st = start_day;
            work = shift.work;
            free = shift.free;
            flag = true;
        }
    }
    for (int i = 1; i < days + 1;i++)
    {
        calendar->setDateTextFormat({year,month,i},format2);
    }
    for (int i = day_st; i < days + 1;)
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
                if (QDate(year,month,i).dayOfWeek()==6||QDate(year,month,i).dayOfWeek()==7)
                {
                    calendar->setDateTextFormat({year,month,i},formatwh);
                }
                else calendar->setDateTextFormat({year,month,i},format);
                work++;
                i++;
                if (work==shift.work)
                {
                    work=0;
                    flag=false;
                }

            }
        }
        else
        {
             if (free==shift.free)
             {
                 free=0;
                 flag=true;
             }
             else
             {
                 free++;
                 i++;
             }
        }
    }
}

void calendarwidget::paint_calendar()
{
    qDebug() << "paint calendar";
    for (int i = 0; i < 12; i++)
    {
        QCalendarWidget *calendar = new QCalendarWidget;
        calendar->setSelectionMode(QCalendarWidget::SingleSelection);
        calendar->setGridVisible(true);
        calendar->setNavigationBarVisible(false);
        calendar->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        connect(calendar,&QCalendarWidget::clicked,this,&calendarwidget::changeFormat);
        list->append(calendar);
    }

    int i = start_month;
    int tmp = 0;
    while(tmp < 12)
    {
        if(i == 13)
        {
            i = 1;
        }
        QLabel *label = new QLabel(list->at(i-1));
        label->setText(nameOfMonth[i]);
        list_lable->append(label);
        tmp++;
        i++;
    }
    drowCalendar(start_year, start_month);
}

void calendarwidget::clear_widget()
{
    qDebug() << "clear_widget";
    for(int i = 0; i < list->size(); i++){
        gridLayout->removeWidget(list->at(i));
    }
    for(int i = 0; i < list_lable->size(); i++){
        list_lable->at(i)->hide();
    }
    list_lable->clear();
}

void calendarwidget::orient_port()
{
    qDebug() << "porto";
    this->resize(400, 600);
    this->updateGeometry();
    int m = start_month-1;
    int l = 0;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 3; j++){
            if (i%2 == 0){
                gridLayout->addWidget(list_lable->at(l), i,j, Qt::AlignCenter);
                list_lable->at(l)->setContentsMargins(0, 20, 0 ,0);
                l++;
            }
            else {
                if (m == 12)
                {
                    m = 0;
                }
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
    int m = start_month-1;
    int l = 0;
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 4; j++){
            if (i%2 == 0){
                gridLayout->addWidget(list_lable->at(l), i,j, Qt::AlignCenter);
                list_lable->at(l)->setContentsMargins(0, 20, 10 ,10);
                l++;
            }
            else {
                if (m == 12)
                {
                    m = 0;
                }
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

    qDebug() << "get print";
    QPixmap snapShot;
    snapShot=QWidget::grab();
    snapShot.save("snapshot.png");
    return snapShot;
}

void calendarwidget::set_Data(QString fio, int day, int month, int year, int current_orient)
{
    qDebug() << "set Data";
    clear_widget();
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
    paint_calendar();
    switch (orientOfCalendar) {
    case 0:
        orient_album();
        break;
    default:
        orient_port();
        break;
    }
}

void calendarwidget::set_Voc(QDate begin, QDate end)
{
    begin_voc = begin;
    end_voc = end;
}


void calendarwidget::closeEvent(QCloseEvent *event)
{
    qDebug() << "close Event";

    clear_widget();
    event->accept();
}


void calendarwidget::setCursorFlag(int value)
{
    cursorFlag = value;
}

calendarwidget::~calendarwidget()
{
    delete list;
    delete list_lable;
    delete label_year;
    delete gridLayout;
}


CursorWidget::CursorWidget(QWidget *parent): QWidget(parent)
{
     setWindowTitle("Cursor");
     gridLayout = new QGridLayout;
     coursorBox = setCursorDefinition();
     gridLayout->addWidget(coursorBox, 0, 0);
     setLayout(gridLayout);
     resize(300, 100);

     connect(radioN, &QRadioButton::clicked, this,&CursorWidget::changeDef);
     connect(radioV, &QRadioButton::clicked, this,&CursorWidget::changeDef);
     connect(radioW, &QRadioButton::clicked, this,&CursorWidget::changeDef);
}

QGroupBox *CursorWidget::setCursorDefinition()
{
    QGroupBox *groupBox = new QGroupBox(tr("Курсор выбирает: "));

    radioN = new QRadioButton(tr("Ничего"));
    radioV = new QRadioButton(tr("Отпуск"));
    radioW = new QRadioButton(tr("Первый рабочий день"));
    radioN->setChecked(true);
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(radioN);
    vbox->addWidget(radioV);
    vbox->addWidget(radioW);
    vbox->addStretch(1);
    groupBox->setLayout(vbox);
    return groupBox;
}

void CursorWidget::changeDef(bool)
{
    qDebug()<<"changeDef";
    if(radioN->isChecked())
        emit Def(0);
    if(radioV->isChecked())
        emit Def(1);
    if(radioW->isChecked())
        emit Def(2);
}
void CursorWidget::closeEvent(QCloseEvent *event)
{
    qDebug() << "close Event Curr";
    emit Def(0);
    event->accept();
}

CursorWidget::~CursorWidget()
{}
