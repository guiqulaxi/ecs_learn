#ifndef SIZE_H
#define SIZE_H
template<typename T>
class Size
{
public:


    //! default constructor
    Size():width(0),height(0){} //数据成员都是0
    Size(T _width, T _height):width(_width),height(_height){}

    Size(const Size& r)     //拷贝构造
    {
        width=r.width;
        height=r.height;
    }

    Size& operator = ( const Size& p ){
        width=p.width;
        height=p.height;
    }

    //! true if empty
    bool empty() const{
        return (0==width&&0==height);

    }



    T width;
    T height;

};

typedef Size<int> Size2i;
typedef Size<float> Size2f;
typedef Size<double> Size2d;
#endif // SIZE_H
