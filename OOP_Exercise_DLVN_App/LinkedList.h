#pragma once
#ifndef _LinkedList_H
#define _LinkedList_H
#include <iostream>

using namespace std;

template<class T>
class CNode
{
private:
	T m_Tdata;
	CNode<T> *m_pNext;
public:
	CNode();
	void SetData(T data);
	T GetData();
	void SetNext(CNode<T> *);
	CNode<T>* GetNext(void);
};

template<class T>
class C_LinkedList
{
private:
	CNode<T> *m_pHead;
	unsigned int m_uiNumberOfNode;
public:
	C_LinkedList();
	~C_LinkedList();
	void insert(T);
	void erase(T);
	T at(unsigned int);
	unsigned int size();
};
#endif // !LinkedList



