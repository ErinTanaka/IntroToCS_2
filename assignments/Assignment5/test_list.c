#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
   char filename[20];
   struct list l;
   FILE * fileptr;
   char num[3];
   int n, loc;
   
   l.head=NULL;
   l.tail=NULL;

   printf("Enter filename: ");
   scanf ("%s", filename);
   fileptr= fopen(filename, "r");

   while (fscanf(fileptr, "%s", num)!=EOF){
      printf("number is: %d \n", atoi(num));
      push_front(&l, atoi(num));
      push_back(&l, atoi(num));
   }

   printf("Length: %d \n", length(l));
   printf("Contents: ");
   print(l);

   sort_ascending(&l);
   printf("Contents ascending: ");
   print(l);

   sort_descending(&l);
   printf("Contents descending: ");
   print(l);

   printf("Enter a value to be removed: ");
   scanf("%d", &n);
   remove_val(&l, n);
   printf("Contents: ");
   print(l);

   printf("Enter a value to insert: ");
   scanf("%d", &n);
   printf("Enter a location to inster the value: ");
   scanf("%d", &loc);
   insert(&l, n, loc);
   printf("Contents: ");
   print(l);

   clear(&l);

   fclose(fileptr);
   
   return 0;
}
