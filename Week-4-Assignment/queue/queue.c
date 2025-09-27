#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* data;
    int front;
    int rear;
    int size;
    int capacity;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->data = (int*)malloc(k * sizeof(int));
    obj->front = 0;
    obj->rear = -1;
    obj->size = 0;
    obj->capacity = k;
    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj->size == obj->capacity) {
        return false;  // Queue is full
    }
    
    obj->rear = (obj->rear + 1) % obj->capacity;
    obj->data[obj->rear] = value;
    obj->size++;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->size == 0) {
        return false;  // Queue is empty
    }
    
    obj->front = (obj->front + 1) % obj->capacity;
    obj->size--;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj->size == 0) {
        return -1;  // Queue is empty
    }
    return obj->data[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj->size == 0) {
        return -1;  // Queue is empty
    }
    return obj->data[obj->rear];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->size == 0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size == obj->capacity;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->data);
    free(obj);
}


int main() {
    MyCircularQueue* myCircularQueue = myCircularQueueCreate(3);
    
    printf("%s\n", myCircularQueueEnQueue(myCircularQueue, 1) ? "true" : "false");  
    printf("%s\n", myCircularQueueEnQueue(myCircularQueue, 2) ? "true" : "false");  
    printf("%s\n", myCircularQueueEnQueue(myCircularQueue, 3) ? "true" : "false");  
    printf("%s\n", myCircularQueueEnQueue(myCircularQueue, 4) ? "true" : "false");  
    printf("%d\n", myCircularQueueRear(myCircularQueue));                           
    printf("%s\n", myCircularQueueIsFull(myCircularQueue) ? "true" : "false");     
    printf("%s\n", myCircularQueueDeQueue(myCircularQueue) ? "true" : "false");    
    printf("%s\n", myCircularQueueEnQueue(myCircularQueue, 4) ? "true" : "false"); 
    printf("%d\n", myCircularQueueRear(myCircularQueue));                          
    
    myCircularQueueFree(myCircularQueue);
    return 0;
}
