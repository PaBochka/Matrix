#pragma once
#include<iostream>
#include"E:\Visual Studio 2013\Projects\Vectors\Vectors\Tvector.h"
using namespace std;
template <class type>
class TMatrix : public TVector<TVector<type>>
{
public:
	TMatrix(int s = 10);
	TMatrix(const TMatrix &mt); // копирование 
	TMatrix(const TVector<TVector<type> > &mt);// преобразование типа 
	int operator==(const TMatrix &mt);// сравнение
	TMatrix& operator= (const TMatrix&mt); // присваивание
	TMatrix operator+ (const TMatrix &mt); // сложение
	TMatrix operator- (const TMatrix &mt); // вычитание 
	TMatrix operator* (const TMatrix &mt); // умножение 
	type determinant();
	// ввод / вывод 
	friend istream& operator>>(istream &in, TMatrix &mt)
	{
		for (int i = 0; i < mt.Size; i++)
			in >> mt.pVector[i];
		return in;
	}
	friend ostream& operator<<(ostream &out, const TMatrix<type> &mt)
	{
		for (int i = 0; i < mt.Size; i++)
			out << mt.pVector[i] << endl;
		return out;
	}
};
template <class type>
TMatrix<type>::TMatrix(int s) :TVector<TVector<type>>(s)
{
	int c = 0;
	for (int i = 0; i < s; i++){
		c = s - i;
		pVector[i] = TVector<type>(c, i);
	}
}
template <class type>
TMatrix<type>::TMatrix<type>(const TMatrix &mt) : TVector<TVector<type>>(mt){}
template <class type>
TMatrix<type>::TMatrix(const TVector<TVector<type> > &mt) : TVector<TVector<type>>(mt){}
template <class type>
int TMatrix<type>:: operator==(const TMatrix<type> &mt)
{
	return TVector<TVector<type>> ::operator==(mt);
}
template <class type>
TMatrix<type>& TMatrix<type>:: operator=(const TMatrix<type>&mt)
{
	if (this != &mt)
	{
		if (Size != mt.Size)
		{
			delete[]pVector;
			pVector = new TVector<type>[mt.Size];
		}
		Size = mt.Size;
		Startindex = mt.Startindex;
		for (int i = 0; i < Size; i++)
			pVector[i] = mt.pVector[i];
	}
	return *this;
}
template <class type>
TMatrix<type> TMatrix<type>::operator*(const TMatrix<type> &mt)
{
	TMatrix<type> res(Size);
	type k;
	for (int i = 0; i < (Size); i++)
	{
		for (int l = i; l < (Size); l++)
		{
			k = 0;
			for (int j = i; (j < (Size)) && (j <= l); j++)
			{
				k = k + (pVector[i][j] * mt.pVector[j][l]);
			}
			res[i][l] = k;
		}
	}
	return res;
}
template <class type>
TMatrix<type> TMatrix<type>:: operator+(const TMatrix<type> &mt)
{
	return TVector<TVector<type>> ::operator+(mt);
}
template <class type>
TMatrix<type> TMatrix<type>:: operator-(const TMatrix<type> &mt)
{
	return TVector<TVector<type>> ::operator-(mt);
}
template <class type>
type TMatrix<type>::determinant(void)
{
	type temp = 1;
	int i = 0; int j = 0;
	while ((i < Size) && (j < Size))
	{
		temp = temp*pVector[i][j];
		i++; j++;
	}
	return temp;
}