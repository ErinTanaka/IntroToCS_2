#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct stack{
   int *contents;
   int top;
};

void init(struct stack *); //initialize stack members
void push(struct stack *, int); //grow contents to store int
int pop(struct stack *); //shrink contents and return top int
int peek(struct stack);
void destroy(struct stack *);
bool empty(struct stack);
int size(struct stack);

int main(){
   struct stack s;
   int i; //for loop variable
   int sz; //num elements in array 
   int p; //peek at top
   bool e; //empty array
   init(&s);

   e=empty(s);
   printf("contents empty? %d\n", e);
   
   push(&s, 5);
   p=peek(s);
   sz=size(s);
   printf("top element after 1st push: %d, size %d\n" , p, sz);
   
   push(&s, 4);
   p=peek(s);
   sz=size(s);
   printf("top element after 2nd push: %d, size %d\n" , p, sz);
   
   e=empty(s);
   printf("contents empty?  %d\n", e);
    
   pop(&s);
   p=peek(s);
   sz=size(s);
   printf("top element after pop: %d, size %d\n" , p, sz);

   destroy(&s);
   return 0;
}

void init(struct stack * s){
   s->contents=NULL;
   s->top=-1;
}
void push(struct stack * s, int n){
   int* temp;
   int i;
   s->top++;
   if(s->top==-1){
      s->contents=malloc(sizeof(int));
      s->contents[s->top]=n;
   }
   else{
      temp= (int*) malloc(sizeof(int)* s->top+1);
   
      for (i=0; i<s->top; i++){
         temp[i]=s->contents[i];
      }
      temp[s->top]=n;
      free (s->contents);
      s->contents=temp;
   }
}
int pop(struct stack * s){
   int* temp;
   int i;
   s->top;
   printf("in pop\n");
   if (s->top-1==-1){
      //printf ("contents will be set to null\n");
      free(s->contents);
      s->contents=NULL;
   }
   else{
     // printf("allocating temp\n");
      temp= (int*) malloc(sizeof(int)* (s->top-1));
      //printf("stuff allocated\n");  
      for (i=0; i<s->top; i++){
	// printf("in for loop %d \n", i);
         temp[i]=s->contents[i];
      }
      free (s->contents);
      s->contents=temp;
      s->top--;
}}
int peek(struct stack s){
   return (s.contents[s.top]);
}
void destroy(struct stack *s){
   free(s->contents);
}
bool empty(struct stack s){
    if(s.top==-1) return true;
    return false;
}
int size(struct stack s){
   return (s.top+1);
}
