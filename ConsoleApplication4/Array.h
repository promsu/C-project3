#pragma once
#ifndef ARRAY_H_
#define ARRAY_H_
#include "stdafx.h"
#include <cassert>

template<typename T>
class Array {
private:
	T* list;
	int size;
public:
	Array(int sz = 50);
	Array(const Array<T>& a);
	~Array();
	Array<T>& operator =(const Array<T>& rhs);
	T& operator [](int i);
	const T& operator [](int i)const;
	operator T*();
	operator const T*()const;
	int getsize()const;
	void resize(int sz);
};
template<typename T> Array<T>::Array(int sz) {
	assert(sz >= 0);
	size = sz;
	list = new T[size];
}
template<typename T> Array<T>::Array(const Array<T>& a) :size(a.size) {
	list = new a.list;
	for (int i = 0; i <= size; i++)
		list[i] = a.list[i];
}
template<typename T> Array<T>::~Array() {
	delete[] list;
}
template<typename T>
Array<T>& Array<T>::operator =(const Array<T>& rhs) {
	if (&rhs != this) {
		if (size != rhs.size) {
			delete[] list;
			size = rhs.size;
			list = new T[size];
		}
		for (int i = 0; i < size; i++)
			list[i] = rhs.list[i];
	}
	return *this;
}
template<typename T>
//重载下标运算符
T& Array<T>::operator [](int n) {
	assert(n >= 0 && n < size);
	return list[n];
}
template<class T>
const T& Array<T>::operator [](int n)const {
	assert(n >= 0 && n < size);
	return list[n];
}
//重载指针转换运算符,语法要求不指定返回值类型
template<typename T>
Array<T>::operator T*() {
	return list;
}
template<typename T>
Array<T>::operator const T*()const {
	return list;
}
template<typename T>
int Array<T>::getsize()const {
	return size;
}
template<class T>
void Array<T>::resize(int sz) {
	assert(sz >= 0);
	if (sz == size)
		return;
	T* newlist = new T[sz];
	int n = (sz < size) ? sz : size;
	for (int i = 0; i < n; i++)
		newlist[i] = list[i];
	delete[] list;
	list = newlist;
	size = sz;
}
#endif
