public class CustomStack {
    private int[] stack;
    private int[] lazy;  
    private int maxSize;
    private int top;     

    public CustomStack(int maxSize) {
        this.maxSize = maxSize;
        this.stack = new int[maxSize];
        this.lazy = new int[maxSize];
        this.top = -1;
    }
    
    public void push(int x) {
        if (top < maxSize - 1) {
            top++;
            stack[top] = x;
        }
    }
    
    public int pop() {
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
    
    public void increment(int k, int val) {
        if (top >= 0) {
            int idx = Math.min(k - 1, top);
            lazy[idx] += val;
        }
    }
    
    public static void main(String[] args) {
        CustomStack stk = new CustomStack(3);
        
        stk.push(1);                        
        stk.push(2);                        
        System.out.println(stk.pop());      
        stk.push(2);                        
        stk.push(3);                        
        stk.push(4);                        
        stk.increment(5, 100);              
        stk.increment(2, 100);              
        System.out.println(stk.pop());      
        System.out.println(stk.pop());      
        System.out.println(stk.pop());      
        System.out.println(stk.pop());      
    }
}