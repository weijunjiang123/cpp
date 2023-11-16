#pragma once
#include "listNode.h"
#include <iostream>

template <typename T>
class List
{
private:
	Rank _size;
	ListNodePosi<T> header, trailer;

protected:
	void init();
	Rank clear();
	void copyNode(ListNodePosi<T> p, Rank n);

public:
	List() { init(); }
	List(List<T> const &L);
	~List();
	ListNodePosi<T> first() const
	{
		return header->succ;
	}
	ListNodePosi<T> last() const
	{
		return trailer->pred;
	}
	Rank size() const
	{
		return _size;
	}

	T remove(List<T> L, Rank a);

	T removeNode(ListNodePosi<T> p);
	ListNodePosi<T> insert(ListNodePosi<T> p, T const &e);
	ListNodePosi<T> insert(T const &e, ListNodePosi<T> p);

	ListNodePosi<T> insertAsFirst(T const &e)
	{
		_size++;
		return header->insertAsSucc(e);
	}
	ListNodePosi<T> inertAsLast(T const &e)
	{
		_size++;
		return trailer->insertAsPred(e);
	}
	void printList();
};

template <typename T>
inline void List<T>::init()
{
	header = new ListNode<T>;
	trailer = new ListNode<T>;
	header->succ = trailer;
	trailer->pred = header;
	header->pred = nullptr;
	trailer->succ = nullptr;
	_size = 0;
}

template <typename T>
inline Rank List<T>::clear()
{
	Rank oldSize = _size;
	while (0 < _size)
		removeNode(header->succ);
	return oldSize;
}

template <typename T>
inline void List<T>::copyNode(ListNodePosi<T> p, Rank n)
{
	init();
	while (n--)
	{
		insertAsLast(p->data);
		p = p->succ;
	}
}

template <typename T>
inline List<T>::List(List<T> const &L)
{
	copyNode(L.first(), L._size);
}

template <typename T>
inline List<T>::~List()
{
	clear();
	delete header;
	delete trailer;
}

template <typename T>
inline T List<T>::remove(List<T> L, Rank a)
{
	ListNodePosi<T> start = L.first();
	for (Rank n = 0; n < a; n++)
	{
		start = start->succ;
	}
	T data = removeNode(start);
	return data;
}

template <typename T>
inline T List<T>::removeNode(ListNodePosi<T> p)
{
	T e = p->data;
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	delete p;
	_size--;
	return e;
}

template <typename T>
inline ListNodePosi<T> List<T>::insert(ListNodePosi<T> p, T const &e)
{
	_size++;
	return p->insertAsSucc(e);
}

template <typename T>
inline ListNodePosi<T> List<T>::insert(T const &e, ListNodePosi<T> p)
{
	_size++;
	return p->insertAsPred(e);
}

template <typename T>
inline void List<T>::printList()
{
	ListNodePosi<T> p = header->succ;
	while (true)
	{
		T Nodedata = p->data;
		std::cout << Nodedata;
		if (p->succ == trailer)
		{
			std::cout << std::endl;
			break;
		}
		else
		{
			std::cout << "->"; // print the list (with "->" between each node
		}
		p = p->succ;
	}
}