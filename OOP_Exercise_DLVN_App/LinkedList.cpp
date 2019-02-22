#include "LinkedList.h"

// Node define
template<class T>
inline CNode<T>::CNode()
{
	m_pNext = NULL;
}

template<class T>
inline void CNode<T>::SetNext(CNode *newNode)
{
	m_pNext = newNode;
}

template<class T>
inline void CNode<T>::SetData(T data)
{
	m_Tdata = data;
}

template<class T>
inline T CNode<T>::GetData()
{
	return m_Tdata;
}

template<class T>
inline CNode<T> * CNode<T>::GetNext()
{
	return m_pNext;
}

// List Define
template<class T>
inline C_LinkedList<T>::C_LinkedList()
{
	m_pHead = NULL;
	m_uiNumberOfNode = 0;
}

template<class T>
C_LinkedList<T>::~C_LinkedList()
{
	CNode<T> *p_currentNode = m_pHead;
	CNode<T> *p_nextNode = NULL;
	for (unsigned int i = 0; i < m_uiNumberOfNode; i++)
	{
		p_nextNode = p_currentNode->GetNext();
		delete p_currentNode;
		p_currentNode = p_nextNode;
	}
}

template<class T>
inline void C_LinkedList<T>::insert(T newData)
{
	CNode<T> *p_newNode = new CNode<T>;
	p_newNode->SetData(newData);
	p_newNode->SetNext(m_pHead);
	m_pHead = p_newNode;
	m_uiNumberOfNode++;
}

template<class T>
inline void C_LinkedList<T>::erase(T SearchingData)
{
	if (!m_pHead)
	{
		cout << "The List is currently empty" << endl;
	}
	else
	{
		CNode<T> *p_currentNode = m_pHead;
		CNode<T> *p_previousNode = NULL;
		for (unsigned int i = 0; i < m_uiNumberOfNode; i++)
		{
			if (p_currentNode->GetData() == SearchingData)
			{
				p_previousNode->SetNext(p_currentNode->GetNext());
				delete p_currentNode;
				m_uiNumberOfNode--;
				return;
			}
			else
			{
				p_previousNode = p_currentNode;
				p_currentNode = p_currentNode->GetNext();
			}
		}
		cout << "The object you want to remove doesn't exist in List" << endl;
	}
}

template<class T>
inline T C_LinkedList<T>::at(unsigned int position)
{
	if (position >= m_uiNumberOfNode)
	{
		cout << "The List has only " << m_uiNumberOfNode << "elements" << endl;
	}
	else
	{
		CNode<T> *p_currentNode = m_pHead;
		for (unsigned int i = m_uiNumberOfNode; i > 0; i--)
		{
			if ((i - 1) == position)
				return p_currentNode->GetData();
			else
			{
				p_currentNode = p_currentNode->GetNext();
			}
		}
	}
}

template<class T>
inline unsigned int C_LinkedList<T>::size()
{
	return m_uiNumberOfNode;
}

