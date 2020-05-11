/***********************************************
 * Program Filename: list.c
 * Author: Erin Tanaka
 * Date: May 26, 2016
 * Description: function implementation for double linked list
 * ********************************************/
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
/**********************************************
 * Function: length
 * Description: iterates through list and increments counter once for each node
 * Parameters: object list
 * Preconditions: none
 * Postconditions: integer returned regarding how many objects are in the list
 * *******************************************/
int length (struct list l){
   int n=0;
   struct node * tracker=NULL;
   tracker=l.head;
   while(tracker!=NULL){ //iterate through list
      n++; //increment count
      tracker=tracker->next; //next node
   }
   return n;
}
/**********************************************
 * Function: print
 * Description: iterates through prints value members of each node in list
 * Parameters: object list
 * Preconditions: none
 * Postconditions: integers in list printed to screen
 * *******************************************/
void print(struct list l){
   struct node * temp=NULL;
   temp=l.head;
   while(temp->next!=NULL){ //iterate
      printf("%d ", temp->val); //print
      temp=temp->next; //next node
   } 
   printf("%d \n", temp->val);
}
/**********************************************
 * Function: push_front
 * Description: adds a node to the beginning of the list, node's value set to passed parameter
 * Parameters: pointer to list object, number to go in new node
 * Preconditions: none
 * Postconditions: one item added to beginning of list
 * *******************************************/
void push_front(struct list * l, int n){
   struct node *temp;
   temp=(struct node *) malloc(sizeof(struct node));
   temp->val=n;

   if (l->head==NULL){ //nothing in list
      l->head=temp;
      l->tail=temp;
      temp->next=NULL;
      temp->prev=NULL;
   }
   else{ //at least one element in list
      temp->next=l->head;
      temp->prev=NULL;
      l->head->next->prev=temp;
      l->head=temp;
   }
}
/**********************************************
 * Function: push_back
 * Description: adds a node to the end of the list, node's value set to passed parameter
 * Parameters: pointer to list object, number to go in new node
 * Preconditions: none
 * Postconditions: new node with passed value added to end of list
 * *******************************************/
void push_back(struct list * l, int n){
   struct node *temp; //making new node
   temp=(struct node *) malloc(sizeof(struct node));
   temp->val=n;
   temp->next=NULL;

   if (l->tail==NULL){ //nothing in list
      l->head=temp;
      l->tail=temp;
      temp->prev=NULL;
   }
   else{ //at least one element in list
      l->tail->next=temp;
      temp->prev=l->tail;
      l->tail=temp;
   }
}

/**********************************************
 * Function: clear
 * Description: frees all node in list
 * Parameters: pointer to list object
 * Preconditions: none
 * Postconditions: all nodes in list freed
 * *******************************************/
void clear(struct list * l){
   struct node * temp;
   temp=l->head->next;
   while(temp!=NULL){ //iterate through list
      free(l->head);
      l->head=temp;
      temp=temp->next;
   }
   free(l->tail);
}
/**********************************************
 * Function: remove_val
 * Description: removes all accounts of value passed into function
 * Parameters: pointer to list, value to be removed
 * Preconditions: at least three members in list
 * Postconditions: nodes with passed parameter are removed and freed from list
 * *******************************************/
void remove_val(struct list * l, int n){
   struct node * tmp1, * tmp2, *tmp3;
   tmp1=l->head;
   tmp2=l->head->next;
   tmp3=tmp2->next;
   while(tmp3!=NULL){ //iterate though list
         if(tmp1->prev==NULL && tmp1->val==n){ //first member needs to be removed
	    tmp2->prev=NULL;
	    free(tmp1);
	    l->head=tmp2;
	    tmp1=tmp2;
	    tmp2=tmp3;
	    tmp3=tmp3->next;
	 }
	 else if(tmp2->val==n){ //number that needs to be removed is not first or last
	    tmp1->next=tmp3;
	    tmp3->prev=tmp1;
	    free(tmp2);
	    if (tmp3->next==NULL){ //2nd to last member
	       tmp2=tmp1;
	       tmp1=tmp2->prev;
	    }
	    else{ //any thing else
	       tmp2=tmp3;
	       tmp3=tmp3->next;
	    }
	 }
	 else if(tmp3->next==NULL && tmp3->val==n) { // last member to be removed
	    l->tail=tmp2;
	    tmp2->next=NULL;
	    free(tmp3);
	    tmp3=NULL;
	 }
         else{ //number doesn't need to be removed
            tmp1=tmp2;
	    tmp2=tmp3;
	    tmp3=tmp3->next;
         }
   }
}
/**********************************************
 * Function: sort_ascending
 * Description: sorts members of list 
 * Parameters: pointer to list object
 * Preconditions: list contains nodes
 * Postconditions: node are sorted in order by member val from least to greatest
 * *******************************************/
void sort_ascending(struct list * l){
   int i=0, n=0, t;
   struct node * tmp1=NULL, * tmp2=NULL, * count=NULL;
   count=l->head;
   while(count!=NULL){ //get count of members in list
      n++;
      count=count->next;
   }
   tmp1=l->head;
   tmp2=l->head->next;
   while(i<n+1){ //iterate through list
      while (tmp2!=NULL){ //iterate through list
	 if(tmp1->val > tmp2->val){ //make comparison
	    t=tmp1->val;
	    tmp1->val=tmp2->val;
	    tmp2->val=t;
	 }
	 tmp1=tmp2; //move iterators
	 tmp2=tmp2->next;   
      }
      tmp1=l->head; //reset iterator
      tmp2=tmp1->next;
      i++;
   }
}
/**********************************************
 * Function: sort_descending
 * Description: sorts members of list
 * Parameters: pointer to list object
 * Preconditions: list contains nodes
 * Postconditions: nodes are sorted in order by member val from greatest to least
 * *******************************************/
void sort_descending(struct list * l){
   int i=0, n=0, t;
   struct node * tmp1=NULL, * tmp2=NULL, * count=NULL;
   count=l->head;
   while(count!=NULL){ //count number of members in list
      n++;
      count=count->next;
   }
   tmp1=l->head;
   tmp2=l->head->next;
   while(i<n+1){ //iterate through list
      while (tmp2!=NULL){ //iterate through list
	 if(tmp1->val < tmp2->val){ //make comparison
	    t=tmp1->val;
	    tmp1->val=tmp2->val;
	    tmp2->val=t;
	 }
	 tmp1=tmp2; //move iterator
	 tmp2=tmp2->next;   
      }
      tmp1=l->head; //reset iterator
      tmp2=tmp1->next;
      i++;
   }
}
/**********************************************
 * Function: insert
 * Description: inserts number passed as parameter into location passed in as parameter
 * Parameters: pointer to list object, number to be added, location to put added number
 * Preconditions: at least one object in list
 * Postconditions: new node containing value passed as parameter added to list at location passed as parameter
 * *******************************************/
void insert(struct list * l, int n, int loc){
   struct node *temp, *track;
   temp=(struct node *) malloc(sizeof(struct node));
   temp->val=n;
   int count=1;
   track=l->head;
   if(loc==0){ //put new node at beginning of list
      l->head->prev=temp;
      temp->next=l->head;
      temp->prev=NULL;
      l->head=temp;
   }
   else{
      while(count<loc){ //iterate through list
         track=track->next;
	 count++;
      }
      if(track->next==NULL){ //inserting at end 
         temp->next=NULL;
	 temp->prev=track;
	 track->next=temp;
	 l->tail=temp;
      }
      else{ //anywhere else
         temp->next=track->next;
	 temp->prev=track;
	 track->next->prev=temp;
	 track->next=temp;
      }
   }
}
