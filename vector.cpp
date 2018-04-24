#include <iostream>
#include <algorithm>
#define DEFAULT_CAPACITY 3
using namespace std;
typedef int Rank;
template <typename T> class Vector	{
	protected:
		Rank _size;int _capacity; T* _elem;			//类的成员属性 
		void copyFrom(T const* A,Rank lo,Rank hi);
		void expand();
		void shrink();
		bool bubble(Rank lo,Rank hi);
		void bubbleSort(Rank lo,Rank hi);
		Rank max(Rank lo,Rank hi);
		void selectionSort(Rank lo,Rank hi);
		void merge(Rank lo,Rank hi);
		void mergeSort(Rank lo,Rank hi);
	public:
		Vector(int c=DEFAULT_CAPACITY,int s=0,T v=0)	{
			_elem=new T[_capacity=c];
			for (_size=0;_size<s;_elem[_size++]=v);
		}
		Vector(T const* A,Rank n)	{copyFrom(A,0,n);}
		Vector(T const* A,Rank lo,Rank hi)	{copyFrom(A,lo,hi);}
		Vector(Vector<T> const& V)	{copyFrom(V._elem,0,0,V.size);}
		Vector(Vector<T> const& V,Rank lo,Rank hi)	{copyFrom(V._elem,lo,hi);}
		~Vector()	{delete []_elem;}
		Rank size() const{return _size;}
		bool empty() const{return !_size;}
		int disordered() const;
		Rank find(T const& e)	const {return find(e,0,_size);}
		Rank find(T const& e,Rank lo,Rank hi)	const;
		Rank search(T const& e)	const{return (0>=_size)?-1:search(e,0,_size);}
		Rank search(T const& e,Rank lo,Rank hi)const;
		T& operator[](Rank r)	const;
		Vector<T> & operator= (Vector<T>const&);
		T remove (Rank r);
		int remove(Rank lo,Rank hi);
		Rank insert(T const& e) {return insert(_size,e);}
		void sort(Rank lo,Rank hi);
		void sort() {sort(0,_size);}
		void unsort(Rank lo,Rank hi);
		void unsort()	{unsort(0,_size);}
		int deduplicate();
		int uniquify();
		void traverse(void(*)(T&));
		template <typename VST> void traverse (VST&);
};
template <typename T> void Vector<T>::copyFrom(T const* A,Rank lo,Rank hi) {
	_elem=new T[2*(hi-lo)];_size=0;
	while (lo<hi)	_elem[size++]=A[lo++];
}
template <typename T> Vector<T>& Vector<T>::operator= (Vector<T> const& V)	{
	if (_elem)	delete []_elem;
	copyFrom(V.elem,0,V.size());
	return *this;
}
template <typename T> void Vector<T>::expand() {
	if (_size<_capacity)	return;
	if (_capacity<DEFAULT_CAPACITY)	_capacity=DEFAULT_CAPACITY;
	T* oldElem=_elem;_elem=new T[_capacity<<1];
	for (int i=0;i<_elem;i++)	_elem[i]=oldElem[i];
	delete []oldElem;
}
template <typename T> void Vector<T>::shrink() {
	if (_capacity<DEFAULT_CAPACITY<<1)	return;
	if (_size<<2>_capacity)	return;		//以25%为界 
	T *oldElem=_elem;_elem=new T[_capacity>>1];
	for (int i=0;i<_size;i++)	_elem[i]=oldElem[i];
	delete []oldElem;
}
template <typename T> void permute(Vector<T>& v)	{		//这是对类的置乱函数，不是成员函数 
	for (int i=v._size;i>0;i--)	swap(v[i-1],v[rand()%i]);
}
template <typename T> void Vector<T>::unsort(Rank lo,Rank hi)	{		//这个是对类置乱的成员函数 
	T* v=_elem+lo;
	for (int i=hi-lo;i>0;i--)	swap(v[i-1],v[rand()%i]);
}
template <typename T> T& Vector<T>::operator [] (Rank i) const {return _elem[i];}
int main()	{
	
	return 0;
} 




