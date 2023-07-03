#include <QtWidgets>
#include <iostream>

class MainWindow:public QMainWindow{
    public:
        MainWindow();
        void startButtonClick();
        QString str;
        QString str1;
        int x, y, x1, y1, width, heigth, width1, heigth1, shadow, distance;
        int N;
    private:
        QLabel *textLabel;
        QLineEdit *LineN;
        bool buttonState;
        QPushButton *startButton;
    protected:
        void paintEvent(QPaintEvent *event);
};   

MainWindow::MainWindow(){
    QFont labelFont("Courier",23,QFont::Bold);
    QFont buttonFont("Times",18,QFont::Bold);      //buttonState???
    resize(900,500);
    textLabel = new QLabel(this);
    textLabel->setGeometry(50,50,350,70);
    textLabel->setFont(labelFont);

    startButton = new QPushButton("Draw", this);
    startButton->setGeometry(10,130,70,30);
    N=5;
    connect(startButton, &QPushButton::clicked, this, &MainWindow::startButtonClick);
    LineN = new QLineEdit(this);
    LineN->setGeometry(100,100,100,30);
}

void MainWindow::startButtonClick(){
    textLabel->setText("Start");
    str=LineN->text();
    N=str.toInt();
    textLabel->setText("Cout: " + str);
    update();
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter (this);
    x=100;
    y=350;
    width=120;
    heigth=60;
    shadow=120;
    distance=30;
    for (int i =1; i <= N; i++){
        painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
        x1=x+15;
        y1=y+15;
        painter.drawRect(x1,y1,shadow,heigth);
        painter.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
        painter.drawRect(x,y,width,heigth);
        x=i*(width+distance)+100;
        //update;
    }
}

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    MainWindow mainwin;
    mainwin.show();
    return app.exec();
}
