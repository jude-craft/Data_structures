public class MyCircularQueue {
    private int[] data;
    private int front;
    private int rear;
    private int size;
    private int capacity;

    public MyCircularQueue(int k) {
        this.capacity = k;
        this.data = new int[k];
        this.front = 0;
        this.rear = -1;
        this.size = 0;
    }
    
    public boolean enQueue(int value) {
        if (size == capacity) {
            return false;  // Queue is full
        }
        
        rear = (rear + 1) % capacity;
        data[rear] = value;
        size++;
        return true;
    }
    
    public boolean deQueue() {
        if (size == 0) {
            return false;  // Queue is empty
        }
        
        front = (front + 1) % capacity;
        size--;
        return true;
    }
    
    public int Front() {
        if (size == 0) {
            return -1;  // Queue is empty
        }
        return data[front];
    }
    
    public int Rear() {
        if (size == 0) {
            return -1;  // Queue is empty
        }
        return data[rear];
    }
    
    public boolean isEmpty() {
        return size == 0;
    }
    
    public boolean isFull() {
        return size == capacity;
    }
    
   
    public static void main(String[] args) {
        MyCircularQueue myCircularQueue = new MyCircularQueue(3);
        
        System.out.println(myCircularQueue.enQueue(1));  // true
        System.out.println(myCircularQueue.enQueue(2));  // true
        System.out.println(myCircularQueue.enQueue(3));  // true
        System.out.println(myCircularQueue.enQueue(4));  // false
        System.out.println(myCircularQueue.Rear());      // 3
        System.out.println(myCircularQueue.isFull());    // true
        System.out.println(myCircularQueue.deQueue());   // true
        System.out.println(myCircularQueue.enQueue(4));  // true
        System.out.println(myCircularQueue.Rear());      // 4
    }
    
}