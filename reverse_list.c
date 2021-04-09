#include <stdio.h>
#include <stdlib.h>

struct node{
    int v;
    struct node * next;
};

void dump_list(struct node * cursor){
   while(cursor){
     printf("%d, ", cursor->v);
     cursor = cursor->next;
   }   
   fflush(stdout); 
}

struct node * reverse_list(struct node * head){ 
   struct node * prev = 0, * next = 0;  
   while(head){  // what beautiful code
       next = head->next;
       head->next = prev;
       prev = head;
       head = next;
   }   
   return prev;
}

int main(){
   struct node *cursor, *head;
   head = cursor = (struct node*)malloc(sizeof(struct node));
   cursor->v = 0; cursor->next = 0;
   for (int i = 1; i < 10; i++){
      cursor->next = (struct node*)malloc(sizeof(struct node));
      cursor->next->v = i; cursor->next->next = 0;
      cursor = cursor->next;
   }
   dump_list(reverse_list(head));
}  
