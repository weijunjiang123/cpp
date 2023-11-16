#pragma once
#include <cstddef>

using Rank = int;
template <typename T>
struct ListNode;
template <typename T>
using ListNodePosi = ListNode<T> *;
template <typename T>
struct ListNode
{
	T data;
	ListNodePosi<T> pred, succ;
	ListNode() {}
	ListNode(T e, ListNodePosi<T> p = NULL, ListNodePosi<T> s = NULL)
		: data(e), pred(p), succ(s) {}
	ListNodePosi<T> insertAsPred(T const &e);
	ListNodePosi<T> insertAsSucc(T const &e);
};

template <typename T> // 将e紧靠当前节点之前插入于当前节点所属列表（设有哨兵头节点header）
inline ListNodePosi<T> ListNode<T>::insertAsPred(T const &e)
{
	ListNodePosi<T> x = new ListNode(e, pred, this); // 创建新节点
	pred->succ = x;
	pred = x; // 设置正向链接
	return x; // 返回新节点的位置
}

template <typename T>
inline ListNodePosi<T> ListNode<T>::insertAsSucc(T const &e)
{
	ListNodePosi<T> x = new ListNode(e, this, succ);
	succ->pred = x;
	succ = x;
	return x;
}
