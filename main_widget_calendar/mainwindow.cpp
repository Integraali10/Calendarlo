#include "mainwindow.h"
//#include "calendarwidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QDebug>
#include <QTextStream>
#include <QMessageBox>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>


#define VOCATION_DAYS 30

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    setStyleSheet("background-color: #C8D3D3;");
    setFixedSize(450,390);
    setWindowTitle("Calendar");

    createWindow();
    addData();

    connect(open, SIGNAL(clicked(bool)),this, SLOT(open_Data()));
    connect(save, SIGNAL(clicked(bool)),this, SLOT(save_Calendar()));
    connect(print, SIGNAL(clicked(bool)),this, SLOT(print_Calendar()));
    connect(view, SIGNAL(clicked(bool)),this, SLOT(show_Calendar()));
    connect(about,SIGNAL(clicked(bool)),this,SLOT(on_about()));
    connect(monthComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeMonth()));
    connect(yearComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeYear()));
    connect(from,SIGNAL(dateChanged(QDate)),this,SLOT(changeVocation()));
    connect(graphicComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeGraphic()));
    connect(orientComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeOrientation()));
    connect(changeComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeChange()));
}

void MainWindow::createWindow()
{
    open = new QPushButton("Открыть");
    open->setStyleSheet("background-color: #E9EDED; border-radius: 10px; border-style: outset; border: 2px solid #F0F0F0;");
    open->setFixedSize(115,32);
    save = new QPushButton("Сохранить");
    save->setStyleSheet("background-color: #E9EDED; border-radius: 10px; border-style: outset; border: 2px solid #F0F0F0;");
    save->setFixedSize(115,32);
    print = new QPushButton("Печать");
    print->setStyleSheet("background-color: #E9EDED; border-radius: 10px; border-style: outset; border: 2px solid #F0F0F0;");
    print->setFixedSize(115,32);
    view = new QPushButton("Показать");
    view -> setStyleSheet("background-color: #E9EDED; border-radius: 10px; border-style: outset; border: 2px solid #F0F0F0;");
    view -> setFixedSize(115,32);
    about = new QPushButton("About");
    about->setStyleSheet("background-color: #C8D3D3; border-radius: 10px; border-style: outset; border: 1px solid #F0F0F0;");
    about -> setFixedSize(64,20);

    QHBoxLayout *about_layout = new QHBoxLayout;
    about_layout->addWidget(about);
    about_layout->addStretch();
    about_layout->addStretch();

    QHBoxLayout *botton_layout = new QHBoxLayout;
    botton_layout->addWidget(open);
    botton_layout->addWidget(save);
    botton_layout->addWidget(print);

    fioGroupBox = new QGroupBox(tr("ФИО"));

    fioLineEdit = new QLineEdit;
    fioLineEdit->setFixedSize(300, 26);
    fioLineEdit->setStyleSheet("background-color: #E9EDED;");

    QHBoxLayout *fio_layout = new QHBoxLayout;
    fio_layout->addStretch();
    fio_layout->addWidget(fioLineEdit);
    fio_layout->addStretch();
    fioGroupBox->setLayout(fio_layout);

    day_label = new QLabel("День");
    day_label->setFixedSize(111,26);
    month_label = new QLabel("Месяц");
    month_label->setFixedSize(111,26);
    year_label = new QLabel("Год");
    year_label->setFixedSize(111,26);

    dayComboBox = new QComboBox;
    dayComboBox->setFixedSize(111,26);
    dayComboBox->setStyleSheet("background-color: #E9EDED;");
    monthComboBox = new QComboBox;
    monthComboBox->setFixedSize(111,26);
    monthComboBox->setStyleSheet("background-color: #E9EDED;");
    yearComboBox = new QComboBox;
    yearComboBox->setFixedSize(111,26);
    yearComboBox->setStyleSheet("background-color: #E9EDED;");

    QVBoxLayout *day_layout = new QVBoxLayout;
    day_layout->addWidget(day_label);
    day_layout->addWidget(dayComboBox);
    QVBoxLayout *month_layout = new QVBoxLayout;
    month_layout->addWidget(month_label);
    month_layout->addWidget(monthComboBox);
    QVBoxLayout *year_layout = new QVBoxLayout;
    year_layout->addWidget(year_label);
    year_layout->addWidget(yearComboBox);

    QHBoxLayout *main_data_layout = new QHBoxLayout;
    main_data_layout->addLayout(day_layout);
    main_data_layout->addLayout(month_layout);
    main_data_layout->addLayout(year_layout);

    change_label= new QLabel("Смена");
    change_label->setFixedSize(111,26);
    orient_label = new QLabel("Ориентация");
    orient_label->setFixedSize(111,26);
    graphic_label = new QLabel("График");
    graphic_label->setFixedSize(111,26);


    changeComboBox = new QComboBox;
    changeComboBox->setFixedSize(111,26);
    changeComboBox->setStyleSheet("background-color: #E9EDED;");
    orientComboBox = new QComboBox;
    orientComboBox->setFixedSize(111,26);
    orientComboBox->setStyleSheet("background-color: #E9EDED;");
    graphicComboBox = new QComboBox;
    graphicComboBox->setFixedSize(111,26);
    graphicComboBox->setStyleSheet("background-color: #E9EDED;");

    QVBoxLayout *graphic_layout = new QVBoxLayout;
    graphic_layout->addWidget(graphic_label);
    graphic_layout->addWidget(graphicComboBox);

    QVBoxLayout *change_layout = new QVBoxLayout;
    change_layout->addWidget(change_label);
    change_layout->addWidget(changeComboBox);

    QVBoxLayout *orient_layout = new QVBoxLayout;
    orient_layout->addWidget(orient_label);
    orient_layout->addWidget(orientComboBox);

    QHBoxLayout *set_layout = new QHBoxLayout;
    set_layout->addLayout(graphic_layout);
    set_layout->addLayout(change_layout);
    set_layout->addLayout(orient_layout);

    vocationGroupBox = new QGroupBox(tr("Отпуск"));
    from_label = new QLabel("c");
    from_label->setFixedSize(26,26);
    to_label = new QLabel("до");
    to_label->setFixedSize(26,26);

    from = new QDateEdit;
    from->setFixedSize(90,26);
    from->setStyleSheet("background-color: #E9EDED;");
    to = new QDateEdit;
    to->setFixedSize(90,26);
    to->setStyleSheet("background-color: #E9EDED;");

    QHBoxLayout *vocation_layout = new QHBoxLayout;
    vocation_layout->addWidget(from_label);
    vocation_layout->addWidget(from);
    vocation_layout->addWidget(to_label);
    vocation_layout->addWidget(to);
    vocationGroupBox->setLayout(vocation_layout);

    QHBoxLayout *view_layout = new QHBoxLayout();
    view_layout->addStretch();
    view_layout->addWidget(view);
    view_layout->addStretch();

    QVBoxLayout *main_layout = new QVBoxLayout;
    main_layout->addLayout(about_layout);
    main_layout->addLayout(botton_layout);
    main_layout->addWidget(fioGroupBox);
    main_layout->addLayout(main_data_layout);
    main_layout->addLayout(set_layout);
    main_layout->addWidget(vocationGroupBox);
    main_layout->addLayout(view_layout);

    calendar =  new calendarwidget();

    setLayout(main_layout);
}

void MainWindow::getVersion()
{
    QFile fileVersion("version.txt");
    if (!fileVersion.open(QFile::ReadOnly | QFile::Text))
    {
        return;
    }
    QTextStream in(&fileVersion);
    version = in.readLine();
}

void MainWindow::addData()
{
    getVersion();
    QDate data;
    data = QDate :: currentDate();
    choosen_day = data.day();
    choosen_month = data.month();
    choosen_year = data.year();

    monthComboBox->insertItem(0, "Январь");
    monthComboBox->insertItem(1, "Февраль");
    monthComboBox->insertItem(2, "Март");
    monthComboBox->insertItem(3, "Апрель");
    monthComboBox->insertItem(4, "Май");
    monthComboBox->insertItem(5, "Июнь");
    monthComboBox->insertItem(6, "Июль");
    monthComboBox->insertItem(7, "Август");
    monthComboBox->insertItem(8, "Сентябрь");
    monthComboBox->insertItem(9, "Октябрь");
    monthComboBox->insertItem(10, "Ноябрь");
    monthComboBox->insertItem(11, "Декабрь");
    monthComboBox->setCurrentIndex(choosen_month-1);

    int MAX_DAY;
    switch(choosen_month)
    {
    case 2:
        if(((choosen_year%4==0)&(choosen_year%100!=0))||(choosen_year%400==0))
        {
            MAX_DAY = 29;
        }
        else
        {
            MAX_DAY = 28;
        }
        break;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        MAX_DAY=31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        MAX_DAY = 30;
        break;
    }

    int year = choosen_year;
    for(int i = 0; i < 10; i++)
    {
        yearComboBox->insertItem(i,QString::number(year));
        year++;
    }

    int it = 1;
    for(int i = 0; i < MAX_DAY; i++)
    {
        dayComboBox->insertItem(i,QString::number(it));
        it++;
    }
    dayComboBox->setCurrentIndex(choosen_day-1);

    changeComboBox->insertItem(0, "1");
    changeComboBox->insertItem(1,"2");
    graphicComboBox->insertItem(0, "1/1");
    graphicComboBox->insertItem(1, "1/2");;
    graphicComboBox->insertItem(2, "2/1");
    graphicComboBox->insertItem(3, "2/2");
    orientComboBox->insertItem(0, "Альбомная");
    orientComboBox->insertItem(1, "Портрет");

    from->setDate(data);
    to->setDate(countVocation());
}

QDate MainWindow::countVocation()
{
    QDate data = from->date();
    int day = data.day();
    int month = data.month();
    int year = data.year();

    switch(month)
    {
    case 2:
        if(year%2==0 && year%4==0)
        {
            day = day + VOCATION_DAYS - 30; // +30 days of vocation
            month += 1;
        }
        else
        {
            day = day + VOCATION_DAYS - 29;
            month += 1;
        }
        break;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
        day = day + VOCATION_DAYS - 32;
        month += 1;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        day = day + VOCATION_DAYS - 31;
        month += 1;
        break;
    case 12:
        day = day + VOCATION_DAYS - 31;
        month = 1;
        year += 1;
        break;
    }
    QDate new_data(year, month, day);
    return new_data;
}

void MainWindow::changeGraphic()
{
    int index = graphicComboBox->currentIndex();
    switch(index)
    {
    case 0:
        calendar->shift.work=1;
        calendar->shift.free=1;
        calendar->drowCalendar(choosen_year, choosen_month);
        break;
    case 1:
        calendar->shift.work=1;
        calendar->shift.free=2;
        calendar->drowCalendar(choosen_year, choosen_month);
        break;
    case 2:
        calendar->shift.work=2;
        calendar->shift.free=1;
        calendar->drowCalendar(choosen_year, choosen_month);
        break;
    case 3:
        calendar->shift.work=2;
        calendar->shift.free=2;
        calendar->drowCalendar(choosen_year, choosen_month);
        break;
    default:
        break;
    }
}

void MainWindow::changeOrientation()
{
    int index = orientComboBox->currentIndex();
    switch(index)
    {
    case 0:
        calendar->clear_widget();
        calendar->orient_album();
        break;
    case 1:
        calendar->clear_widget();
        calendar->orient_port();
        break;
    default:
        break;
    }
}

void MainWindow::changeChange()
{
    int index = changeComboBox->currentIndex();
    switch (index)
    {
    case 0:
        calendar->change=0;
        calendar->drowCalendar(choosen_year, choosen_month);
        break;
    case 1:
        calendar->change = calendar->shift.free;
        calendar->drowCalendar(choosen_year, choosen_month);
    default:
        break;
    }
}

void MainWindow::changeVocation()
{
    to->setDate(countVocation());
    to->setEnabled(false);
}

void MainWindow::open_Data()
{
    QString strFile = QFileDialog::getOpenFileName(this,tr("Open File"),tr("*.txt"));
    QFile fileIn(strFile);
    if (!fileIn.open(QFile::ReadOnly | QFile::Text))
    {
       return;
    }
    QTextStream in(&fileIn);
    while (!in.atEnd())
    {
        dayComboBox->setCurrentIndex(in.readLine().toInt());
        monthComboBox->setCurrentIndex(in.readLine().toInt());
        yearComboBox->setCurrentIndex(in.readLine().toInt());
        changeComboBox->setCurrentIndex(in.readLine().toInt());
        orientComboBox->setCurrentIndex(in.readLine().toInt());
        graphicComboBox->setCurrentIndex(in.readLine().toInt());
        QDate data_from(in.readLine().toInt(), in.readLine().toInt(), in.readLine().toInt());
        from->setDate(data_from);
        QDate data_to(in.readLine().toInt(), in.readLine().toInt(), in.readLine().toInt());
        to->setDate(data_to);
    }
    fileIn.close();
}

void MainWindow::save_Calendar()
{
    QString fio = fioLineEdit->text() + ".txt";
    qDebug() << fio;
    QString strFile = QFileDialog::getSaveFileName(this,tr("Save File"),fio);
    QFile fileOut(strFile);
    if (!fileOut.open(QFile::WriteOnly | QFile::Text))
    {
       return;
    }
    QTextStream stream(&fileOut);
    stream << dayComboBox->currentIndex() << endl;
    stream << monthComboBox->currentIndex() << endl;
    stream << yearComboBox->currentIndex() << endl;
    stream << changeComboBox->currentIndex() << endl;
    stream << orientComboBox->currentIndex() << endl;
    stream << graphicComboBox->currentIndex() << endl;

    stream << from->date().day() << endl;
    stream << from->date().month() << endl;
    stream << from->date().year() << endl;

    stream << to->date().day() << endl;
    stream << to->date().month() << endl;
    stream << to->date().year() << endl;

    fileOut.close();
}

void MainWindow::print_Calendar()
{
    QPixmap pic = calendar->get_print();
    QPrinter printer;
    QPrintDialog printDialog(&printer, this);

    /*if (printDialog.exec())
    {
      //QTextDocument textDocument;
      //textDocument.setHtml(html);
      //textDocument.setDefaultFont(QFont("Times", 10, QFont::Bold));
      //textDocument.print(&printer);
        qDebug() << "print";
    }*/

}

void MainWindow::show_Calendar()
{

    calendar->set_Data(fioLineEdit->text(), choosen_day, choosen_month, choosen_year, orientComboBox->currentIndex());
    calendar->show();
    calendar->update();
}

void MainWindow::on_about()
{
    QMessageBox *aboutMsgBox = new QMessageBox();
    aboutMsgBox->setStyleSheet("background-color: #E9EDED");
    aboutMsgBox->setText("Version 1." + version);
    aboutMsgBox->setWindowTitle("About");
    aboutMsgBox->setFixedSize(200,100);
    aboutMsgBox->setIcon(QMessageBox::Information);
    aboutMsgBox->setStandardButtons(QMessageBox::Ok);
    aboutMsgBox->setStandardButtons(QMessageBox::Ok);
    aboutMsgBox->setAttribute(Qt::WA_DeleteOnClose, true);
    aboutMsgBox->show();
}

void MainWindow::changeMonth()
{
    choosen_month = monthComboBox->currentIndex() + 1;
    int y = yearComboBox->currentText().toInt();
    int MAX_DAY;
    switch (choosen_month)
    {
    case 2:
        if(((y % 4 == 0)&(y % 100 != 0))||(y % 400 == 0))
        {
            MAX_DAY = 29;
        }
        else
        {
            MAX_DAY = 28;
        }
        break;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        MAX_DAY=31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        MAX_DAY = 30;
        break;
    }
    int maxCount = dayComboBox->maxCount();
    dayComboBox->setMaxCount(MAX_DAY);
    if (maxCount < MAX_DAY)
    {
        int count = maxCount+1;
        for(int i = maxCount; i<MAX_DAY; i++)
        {
            dayComboBox->insertItem(i,QString::number(count));
            count++;
        }
    }

}

void MainWindow::changeYear()
{
    QString tmpYear = yearComboBox->currentText();
    choosen_year = tmpYear.toInt();
    int m = monthComboBox->currentIndex() + 1;
    int MAX_DAY;
    if(m == 2)
    {
        if(((choosen_year % 4 == 0)&(choosen_year % 100 != 0))||(choosen_year % 400 == 0))
        {
            MAX_DAY = 29;
        }
        else
        {
            MAX_DAY = 28;
        }
        int maxCount = dayComboBox->maxCount();
        dayComboBox->setMaxCount(MAX_DAY);
        if (maxCount < MAX_DAY)
        {
            int count = maxCount + 1;
            for(int i = maxCount; i < MAX_DAY; i++)
            {
                dayComboBox->insertItem(i,QString::number(count));
                count++;
            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete open;
    delete save;
    delete print;
    delete view;

    delete day_label;
    delete month_label;
    delete year_label;
    delete dayComboBox;
    delete monthComboBox;
    delete yearComboBox;

    delete change_label;
    delete orient_label;
    delete changeComboBox;
    delete orientComboBox;

    delete graphic_label;
    delete graphicComboBox;

    delete vocationGroupBox;
    delete from_label;
    delete to_label;
    delete from;
    delete to;

    delete fioGroupBox;
    delete fioLineEdit;
}
