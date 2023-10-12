/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> void List<T>::init() { //�б���ʼ�����ڴ����б�����ʱͳһ����
   header = new ListNode<T>;
   trailer = new ListNode<T>; //����ͷ��β�ڱ��ڵ�
   header->succ = trailer;
   header->pred = NULL; //��ǰ����
   trailer->pred = header;
   trailer->succ = NULL; //�������
   _size = 0; //��¼��ģ
}