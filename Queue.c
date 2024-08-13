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
    if (p -> capacity < 0){
        printf("Please Enter a positive number");
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
        printf("Queue is full");
        return false;
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
        printf("Queue is Empty. Cannot Dequeue");
        
    }
    else{
        printf("\n%d was dequeued\n", p -> array[p -> l]);
        p -> l = (p->l + 1) % p->capacity;
        p -> size--;
        

    }
}
int peek(Queue * p){
    printf("%d\n", p -> array[p -> l]);
    return p -> array[p -> l];
}

int main(){
    Queue p;
    Queue * pp = &p;
    initQueue(pp, 5);
    Enqueue(pp, 5);
   // printf("%d\n", pp -> array[pp -> l]);
    
    Enqueue(pp, 7);
    // printf("%d\n", pp -> array[pp -> r]);
    peek(pp);
    Dequeue(pp);
    peek(pp);
}
