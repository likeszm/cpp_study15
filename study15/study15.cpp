/*
* 名称: 多态测试
* 
* 收获:
* 1、多态简单的说就是派生类对基类的函数进行重载，但是这个重载参数是相同的!
*   既然参数相同，如何区分呢？是通过对象类型，这里经常用到基类的指针指向派生类对象
*   指向哪个类的对象，就调用哪个类重载过的函数。
*   （前提是基类的这个函数有virtual关键字，告诉编译器，用户调用的函数，不一定是我哦，
*   然后编译器就会动态编译，匹配对象）
* 2、纯虚函数的使用
* 3、数据抽象: 
*   这是一个很重要的思想,简单来说,就是任何一个函数或者库,作为使用者只需要知道用就好了
*   （知道输入什么和输出什么就够了）,而具体的实现细节就有库的作者来完成,用户关注于应用层,
*   而库的开发人员潜心钻研怎么让某个函数效率更高、更加安全之类的。
*   这样子分工明确,提高效率
* 4、访问标签: 
*   私有标签（就是private）可以让部分代码隐藏起来,不被使用者看到,这样使用者就不会不小心修改了
*   公共标签（就是proteced\private）就不会隐藏
* 5、程序就是函数加上数据，封装就是把数据和函数捆绑到一起，就是类嘛。也是为了防止用户不小心更改。
*    所以，为了封装性，一般所有的变量都是私有的，函数能私有就私有。
*    注意: 纯虚函数可以设计成私有的，不过这样不允许在本类之外的非友元函数中直接调用它，
*    子类中只有覆盖这种纯虚函数的义务，却没有调用它的权利。
*6、有纯虚函数的类就是抽象类，因为这种类是不能用来创建对象的，
*    而要继承下去，派生出来的类称为具体类，再由具体类来创建对象。
*    也就是说，抽象类是给具体类一个大的指导方向，再让各个具体类在它的基础上自由的发展。
*    比如想创建一个图形化界面的框架，我们可以写一个抽象类，
*    成员有名字name、图片素材image，成员函数（都是纯虚函数）有点击Click()、长按Press()。
*    然后派生出具体类有按钮类Buttom、滚动条类Scroll bar等。
*/

#include <iostream>

class Shape_class
{
private:
    double length, width;
public:
    Shape_class(double len = 0, double wid = 0) : length(len), width(wid) {}
    double get_length(void) { return length; }
    double get_width(void) { return width; }
    void set_length(double len) { length = len; }
    void set_width(double wid) { width = wid; }

/*  非纯虚的情况
// 有无virtual是两种结果
    virtual void report(void) { std::cout << "Shape_area = " << get_length() * get_width() << std::endl; }
*/
    virtual void report(void) = 0;
};

class Rectangle_class : public Shape_class
{
public:
    Rectangle_class(double len = 0, double wid = 0) : Shape_class(len,wid) {}
    void report(void) { std::cout << "Rectangle_area = " << get_length() * get_width() << std::endl; }
};

class Triangle_class : public Shape_class
{
public:
    Triangle_class(double len = 0, double wid = 0) : Shape_class(len, wid) {}
    void report(void) { std::cout << "Triangle_area = " << get_length() * get_width()/2 << std::endl; }
};

void Polymorphism_test(void);

int main()
{
    //Polymorphism_test();

    std::cout << "\n测试完成\n";
    return 0;
}

void Polymorphism_test(void)
{
    std::cout << "尝试创建基类指针和派生类对象: " << std::endl;

    Shape_class* p_shape;
    //Shape_class shape(10, 20);    //非纯虚的时候才可以用
    Rectangle_class rectangle(5, 5);
    Triangle_class triangle(6, 6);

    p_shape = &rectangle;
    std::cout << "指向矩形对象测试: p->report(): " << std::endl;
    p_shape->report();

    p_shape = &triangle;
    std::cout << "指向三角对象测试: p->report(): " << std::endl;
    p_shape->report();

    //非纯虚的时候才可以
    //p_shape = &shape;
    //std::cout << "指向基类对象测试: p->report(): " << std::endl;
    //p_shape->report();

}
