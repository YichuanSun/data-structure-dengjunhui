#include <cstdio>           //半成品，我只写了几个成员函数而已
#include <iostream>
#include <algorithm>
#include <cstdlib>
#define _CAPACITY 3
using namespace std;
typedef int Rank;
typedef int T;
template <typename T> class Vector {
protected:
    Rank _size;int _capacity; T* _elem;         //_size is the current length,_capacity is the max length,and the _elem is the head address of the Vector
public:
    Vector(int c=_CAPACITY,int s=0,T vec=0)    {        //create a new Vector
        _elem=new T[_capacity=_CAPACITY];
        for (_size=0;_size<s;_size++)   {_elem[_size]=vec;}
    }
    ~Vector()   {delete []_elem;}           //destroy a Vector
    void expand();                          //expand the capacity
    void Insert(Rank i,T vec);              //insert a value
    T Delete(Rank i);                       //delete a value
};

template <typename T> void Vector<T>::Insert(Rank i,T vec)   {
    if (_size+1>_capacity)  expand();
    for (int ite=_size-1;ite>=i;ite--)  _elem[ite+1]=_elem[ite];
    _elem[i]=vec;
}

template <typename T> void Vector<T>::expand()  {       //when first write,I did not think that if the capacity is enough,the function should return.
    T* backups=_elem;
    T* newVector=new T[_capacity<<1];
    for (int i=0;i<_size;i++)   newVector[i]=_elem[i];
    _elem=newVector;
    delete []backups;
}
template <typename T> T Vector<T>::Delete(Rank i) {
    return i;
}
int main()  {
    return 0;
}
