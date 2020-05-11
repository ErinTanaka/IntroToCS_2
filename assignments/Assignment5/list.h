/**********************************************
 * Program Filename: list.h
 * Author: Erin Tanaka
 * Date: May 26, 2016
 * Description: struct and function declarations for double linked list
 * *******************************************/
#ifndef LIST_H
#define LIST_H
struct node{
   int val;
   struct node * next;
   struct node * prev;
};

struct list{
   struct node * head;
   struct node * tail;
};

int length (struct list); //return number of nodes in the list
void print(struct list); //print values in list
void push_front(struct list *, int); //push to front of list
void push_back(struct list *, int); //push to end of list

void clear(struct list *); //remove all nodes from list
void remove_val(struct list *, int); //remove all nodes with int as value
void sort_ascending(struct list *);
void sort_descending(struct list *);

//insert into a location in the list, start at 0 for front
void insert(struct list *, int, int);
#endif
