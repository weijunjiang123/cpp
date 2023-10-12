#include <iostream>
#include <cstdint>

typedef struct 
{
  char num[20];
  char name[50];
  float price;
}Book;

typedef struct LNode
{
  Book data;
  struct LNode *next;
}LNode, *LinkList;

int InitNode (LinkList &L){
  L = new LNode;
  L -> next = NULL;
  return 1;
}

int GetData(LinkList L, int i, Book &e){
  
}
