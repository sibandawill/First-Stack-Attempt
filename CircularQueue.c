#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int * array;
    int l;
    int r;
    int size;
    int capacity;
}Queue;
void initQueue(Queue * p, int capacity){
    if (capacity <= 0){
        printf("\nPlease Enter a positive number\n");
        return;
    }
    p -> l = -1;
    p -> r = -1;
    p -> capacity = capacity;
    p -> array = (int*)malloc(sizeof(int) * capacity);
    p -> size = 0;
    if (p->array == NULL) {
        printf("Memory allocation failed\n");
        return;

}
}
bool isFull(Queue * p){
    return p -> size == p -> capacity;
        
}
bool isEmpty(Queue * p){
    return p -> size == 0;
}
int Enqueue(Queue * p, int i){
    if(isFull(p)){
        printf("\nQueue is full\n");
        return false;
    }
    else if(p -> r == p -> capacity - 1 && p -> size != 0){
        p -> r = 0;
        p -> array[p -> r] = i;
        p -> size++;
    }
    else if(isEmpty(p)){
        p -> r = 0;
        p -> l = 0;
        p -> size++;
        p -> array[p -> r] = i;

        

    }
    else{
        p -> r++;
        p -> size++;
        p -> array[p -> r] = i;
    }

}
void Dequeue(Queue * p){
    if (isEmpty(p)){
        printf("\nQueue is Empty. Cannot Dequeue\n");
        
    }
    else if(p -> l == p -> capacity - 1){
        printf("\n%d was dequeued\n", p -> array[p->l]);
        p -> l = 0;
        p -> size--;
    }
    else{
        printf("\n%d was dequeued\n", p -> array[p -> l]);
        p -> l++;
        //p -> l = (p->l + 1) % p->capacity;
        p -> size--;
        

    }
}
int peek(Queue * p){
    printf("\n%d\n", p -> array[p -> l]);
    return p -> array[p -> l];
}

int main(){
    Queue CircularQueue;
    Queue * pp = &CircularQueue;
    initQueue(pp, 5);
   /* Enqueue(pp, 5);
   // printf("%d\n", pp -> array[pp -> l]);
    
    Enqueue(pp, 7);
    // printf("%d\n", pp -> array[pp -> r]);
    peek(pp);
    Dequeue(pp);
    peek(pp); */
    Enqueue(pp, 1);
    Enqueue(pp, 2);
    Enqueue(pp, 3);
    Enqueue(pp, 4);
    Enqueue(pp, 5);

  // Fails to enqueue because front == 0 && rear == SIZE - 1
    Enqueue(pp, 6);

  
    Dequeue(pp);

    peek(pp);
    Dequeue(pp);
    Enqueue(pp, 7);
    peek(pp);
    Dequeue(pp);
    peek(pp);
    Dequeue(pp);
    peek(pp);
    Dequeue(pp);
    peek(pp);
    Dequeue(pp);
    Dequeue(pp);
    Enqueue(pp, 7);
    peek(pp);
    Dequeue(pp);
    Enqueue(pp, 5);
    peek(pp);

    
    
    
    
}
