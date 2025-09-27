#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* stack;
    int* lazy;  
    int maxSize;
    int top;    
} CustomStack;

CustomStack* customStackCreate(int maxSize) {
    CustomStack* obj = (CustomStack*)malloc(sizeof(CustomStack));
    obj->stack = (int*)malloc(maxSize * sizeof(int));
    obj->lazy = (int*)calloc(maxSize, sizeof(int)); 
    obj->maxSize = maxSize;
    obj->top = -1;
    return obj;
}

void customStackPush(CustomStack* obj, int x) {
    if (obj->top < obj->maxSize - 1) {
        obj->top++;
        obj->stack[obj->top] = x;
    }
}

int customStackPop(CustomStack* obj) {
    if (obj->top == -1) {
        return -1;
    }
    
    int result = obj->stack[obj->top] + obj->lazy[obj->top];
    
    // Propagate the lazy value to the element below
    if (obj->top > 0) {
        obj->lazy[obj->top - 1] += obj->lazy[obj->top];
    }
    
    obj->lazy[obj->top] = 0;  // Clear the lazy value
    obj->top--;
    
    return result;
}

void customStackIncrement(CustomStack* obj, int k, int val) {
    if (obj->top >= 0) {
        // Apply increment to the minimum of k-1 and top (0-indexed)
        int idx = (k - 1 < obj->top) ? k - 1 : obj->top;
        obj->lazy[idx] += val;
    }
}

void customStackFree(CustomStack* obj) {
    free(obj->stack);
    free(obj->lazy);
    free(obj);
}

// Test function
int main() {
    CustomStack* stk = customStackCreate(3);
    
    customStackPush(stk, 1);                    // [1]
    customStackPush(stk, 2);                    // [1, 2]
    printf("%d\n", customStackPop(stk));        // 2, stack: [1]
    customStackPush(stk, 2);                    // [1, 2]
    customStackPush(stk, 3);                    // [1, 2, 3]
    customStackPush(stk, 4);                    // [1, 2, 3] (no change)
    customStackIncrement(stk, 5, 100);         // [101, 102, 103]
    customStackIncrement(stk, 2, 100);         // [201, 202, 103]
    printf("%d\n", customStackPop(stk));        // 103, stack: [201, 202]
    printf("%d\n", customStackPop(stk));        // 202, stack: [201]
    printf("%d\n", customStackPop(stk));        // 201, stack: []
    printf("%d\n", customStackPop(stk));        // -1
    
    customStackFree(stk);
    return 0;
}