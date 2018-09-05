#pragma once
#include<iostream>
#include"TMatrix.h"
using namespace std;
template <class type>
TMatrix<type>::TMatrix(int s) :Tvector<Tvector<type>>(s)
{
	int c = 0;
	cout << "Matrix " << " Size= " << size << endl;
	for (int i = 0; i < s; i++){
		cout << "peredal v constr vectora" << endl;
		c = s - i;
		coord[i] = Tvector<type>(c, i);
	}
}
template <class type>
TMatrix<type>::TMatrix(const TMatrix &mt) : Tvector<Tvector<type>>(mt){}
template <class type>
TMatrix<type>::TMatrix(const Tvector<Tvector<type> > &mt) : Tvector<Tvector<type>>(mt){}
template <class type>
int TMatrix<type>:: operator==(const TMatrix<type> &mt)
{
	return Tvector<Tvector<type>> ::operator==(mt);
}
template <class type>
TMatrix<type>& TMatrix<type>:: operator= (const TMatrix<type>&mt)
{
	if (this != &mt)
	{
		if (size != mt.size)
		{
			delete[]coord;
			coord = new Tvector<type>[mt.size];
		}
		size = mt.size;
		startindex = mt.startindex;
		for (int i = 0; i < size; i++)
			coord[i] = mt.coord[i];
	}
	return *this;
}
template <class type>
istream& operator>>(istream &in, TMatrix<type> &mt)
{
	for (int i = 0; i < mt.size; i++)
		in >> mt.coord[i];
	return in;
}
template <class type>
ostream& operator<<(ostream &out, const TMatrix<type> &mt)
{
	cout << "Matrix size" << mt.size << endl;
	for (int i = 0; i < mt.size; i++)
		out << mt.coord[i] << endl;
	return out;
}