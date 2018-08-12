#ifndef GLOBALAPPLICATION_H
#define GLOBALAPPLICATION_H
#include<QApplication>
#include<QVector>

class GlobalApplication : public QApplication
{
public:
    GlobalApplication(int&argc,char **argv);
    ~GlobalApplication();

    bool notify(QObject*, QEvent *);
    void setWindowInstance(QWidget*wnd);
    void clearKeys(){
        pressedKeys.clear();
    }
    //获得一个最新的山下左右键
    int getOneKey()
    {
       int pressedMovekey=Qt::Key_unknown;
        while(!pressedKeys.empty()&&
              Qt::Key_Left!=pressedKeys.front()&&
              Qt::Key_Right!=pressedKeys.front()&&
              Qt::Key_Up!=pressedKeys.front()&&
              Qt::Key_Down!=pressedKeys.front()&&
              Qt::Key_Space!=pressedKeys.front()){

        }
        if(!pressedKeys.empty()){
            pressedMovekey=pressedKeys.front();
            pressedKeys.clear();
        }

        return pressedMovekey;
    }
private:
    QWidget *widget;
    QVector<int> pressedKeys;


};

#endif // GLOBALAPPLICATION_H
