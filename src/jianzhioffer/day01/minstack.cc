#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> stack1;
    stack<int> stack_help;
public:
    /** initialize your data structure here. */
    MinStack() {
        stack_help.push(INT_MAX);
    }
    int two_min(int a, int b){
        return a > b ? b : a; 
    }
    void push(int x) {
        int temp = two_min(stack_help.top(),x);
        stack1.push(x);
        stack_help.push(temp);
    }
    
    void pop() {
        stack1.pop();
        stack_help.pop();
    }
    
    int top() {
        return stack1.top();
    }
    
    int min() {
        return stack_help.top();
    }
};


int main()
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.min() << endl;
    minStack.pop();
    cout << minStack.top() << endl;
    cout << minStack.min() << endl;
}