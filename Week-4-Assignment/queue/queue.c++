#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
private:
    vector<int> data;
    int front;
    int rear;
    int size;
    int capacity;

public:
    MyCircularQueue(int k) : capacity(k), front(0), rear(-1), size(0) {
        data.resize(k);
    }
    
    bool enQueue(int value) {
        if (size == capacity) {
            return false;  // Queue is full
        }
        
        rear = (rear + 1) % capacity;
        data[rear] = value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if (size == 0) {
            return false;  // Queue is empty
        }
        
        front = (front + 1) % capacity;
        size--;
        return true;
    }
    
    int Front() {
        if (size == 0) {
            return -1;  // Queue is empty
        }
        return data[front];
    }
    
    int Rear() {
        if (size == 0) {
            return -1;  // Queue is empty
        }
        return data[rear];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};


int main() {
    MyCircularQueue myCircularQueue(3);
    
    cout << boolalpha;  
    cout << myCircularQueue.enQueue(1) << endl;  
    cout << myCircularQueue.enQueue(2) << endl;  
    cout << myCircularQueue.enQueue(3) << endl;  
    cout << myCircularQueue.enQueue(4) << endl;  
    cout << myCircularQueue.Rear() << endl;      
    cout << myCircularQueue.isFull() << endl;    
    cout << myCircularQueue.deQueue() << endl;   
    cout << myCircularQueue.enQueue(4) << endl;  
    cout << myCircularQueue.Rear() << endl;      
    
    return 0;
}
