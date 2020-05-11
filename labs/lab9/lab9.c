#include <stdio.h>
#include <stdlib.h>

struct node{
   int val;
   struct node * next;
};
struct stack{
   struct node * head;
   struct node * tail;
};

void init(struct stack *);
void push(struct stack *, int);
int pop(struct stack *);

int main(){
   
   return 0;
}

void init(struct stack * s){
   s->head=NULL;
   s->tail=NULL;
}
void push(struct stack * s, int n){
   struct node * temp;
   temp->val=n;
   temp->next=NULL;
   if (s->head==NULL){
      s->head=temp;
      s->tail=temp;
   }
   else{
     s->tail->next=temp;
     s->tail=temp;
   }
}
int pop(struct stack * s){

}
