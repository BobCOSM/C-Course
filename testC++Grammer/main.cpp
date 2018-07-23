#include <iostream>
using namespace std;
class A
{
private:
    int data;
public:
    A()
    {
        ;
    }
    A(int data);
    A(const A&);
    int get_data()
    {
        return data;
    }
    bool equal(A det){
        //cout << "this " << &this <<endl;
        cout << "det " << &det <<endl;
        return data == det.get_data();
    }
};

A::A(int data)
{
    this->data = data;
}
A::A(const A &det)
{
    data = 200;
}
class B
{
private:
    A data;
public:
    B(const A data);
    A get_data()
    {
        return data;
    }
    bool equal(B det)
    {
        return data.equal(det.get_data());
    }
};

B::B(const A data)
{
    this->data = data;
}

template<typename T>
bool fun(T a,T b)
{
    return a.equal(b);
}

int sum(int a,int b)
{
    cout << "use first sum " <<endl;
    return a + b;
}

int sum(double a,int b)
{
    cout << "use second sum " <<endl;
    return a + b;
}

int main()
{
    int _sum = sum(10.0,20);
    A a0 = A(100);
    A a1 = A(200);
    bool res0 = a0.equal(a1);

    cout << a0.get_data() <<endl;
    cout << a1.get_data() <<endl;
    if(res0)
    {
        cout << "a0 == a1" <<endl;
    }
    else
    {
        cout << "a0 != a1" <<endl;
    }

    B b0 = B(a0);
    B b1 = B(a1);
    B b2 = B(a0);

    cout << "second " << endl;
    cout << a0.get_data() <<endl;
    cout << a1.get_data() <<endl;
    bool res1 = b1.equal(b0);

    if(res1)
    {
        cout << "b0 == b1" <<endl;
    }
    else
    {
        cout << "b0 != b1" <<endl;
    }

    bool res2 = b2.equal(b0);
    if(res2)
    {
        cout << "b0 == b2" <<endl;
    }
    else
    {
        cout << "b0 != b2" <<endl;
    }

    

    cout << _sum << endl;
    return 0;
}
