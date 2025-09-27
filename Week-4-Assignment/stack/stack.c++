#include <iostream>
#include <vector>
#include <algorithm>  
using namespace std;

class CustomStack {
private:
    vector<int> stack;
    vector<int> lazy;  
    int maxSize;
    int top;           

public:
    CustomStack(int maxSize) : maxSize(maxSize), top(-1) {
        stack.resize(maxSize);
        lazy.resize(maxSize, 0);
    }
    
    void push(int x) {
        if (top < maxSize - 1) {
            top++;
            stack[top] = x;
        }
    }
    
    int pop() {
        if (top == -1) {
            return -1;
        }
        
        int result = stack[top] + lazy[top];
        
        if (top > 0) {
            lazy[top - 1] += lazy[top];
        }
        
        lazy[top] = 0; 
        top--;
        
        return result;
    }
    
    void increment(int k, int val) {
        if (top >= 0) {
            // Apply increment to the minimum of k-1 and top (0-indexed)
            int idx = min(k - 1, top);
            lazy[idx] += val;
        }
    }
};

// Test function

int main() {
    CustomStack stk(3);
    
    stk.push(1);                        
    stk.push(2);                      
    cout << stk.pop() << endl;          
    stk.push(2);                        
    stk.push(3);                        
    stk.push(4);                        
    stk.increment(5, 100);              
    stk.increment(2, 100);              
    cout << stk.pop() << endl;          
    cout << stk.pop() << endl;          
    cout << stk.pop() << endl;         
    cout << stk.pop() << endl;          
    
    return 0;
}
