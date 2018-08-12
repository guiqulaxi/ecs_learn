#ifndef RECT_H
#define RECT_H
template<typename T> class Rect
{
public:


    //! default constructor
    Rect(); //数据成员都是0
    Rect(T _x, T _y, T _width, T _height);      //x列   y行 heigh
    Rect(const Rect& r)     //拷贝构造
    {
        x=r.x;
        y=r.y;
        width=r.width;
        height=r.height;
    }

    Rect& operator = ( const Rect& r );

    //! true if empty
    bool empty() const{
        return (0==x&&0==y&&0==width&&0==height);

    }


    //! checks whether the rectangle contains the point
    bool overlap(const Rect<T>& rect) const         //一个坐标是否在矩形内
    {
        if (rc1.x + rc1.width  > rc2.x &&
                rc2.x + rc2.width  > rc1.x &&
                rc1.y + rc1.height > rc2.y &&
                rc2.y + rc2.height > rc1.y
               )
                return true;
            else
                return false;
    }

    T x; //!< x coordinate of the top-left corner
    T y; //!< y coordinate of the top-left corner
    T width; //!< width of the rectangle
    T height; //!< height of the rectangle
};

typedef Rect<int> Rect2i;
typedef Rect<float> Rect2f;
typedef Rect<double> Rect2d;
typedef Rect2i Rect;
#endif
