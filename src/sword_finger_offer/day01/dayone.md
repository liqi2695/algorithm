#### [剑指 Offer 09. 用两个栈实现队列](https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/)

解题思路：

明确栈和队列的特性才能做出精准的解答。栈先进后出，队列先进先出。

那么在用栈s1和s2模拟queue的时候，需要确保几个点:

* 首先构造类的时候需要保证s1 and s2为空

* 入队的时候直接插入s1即可
* 出队的时候，先判断s2是否为空，如果是，那么需要将s1全部元素转移到s2。接下来，继续判断s2是否为空，如果还为空，则证明整个队列为空，返回-1 。如果s2不为空，直接返回s2的栈顶元素即可。

注意：在出队第三步的时候不需要再去将s1新插入的元素再转移到s2，也就是**仅仅当s2为空时**才会发生s1转移。

代码实现：

```cc
class CQueue {
private:
    stack<int> s1;
    stack<int> s2;    
public:
    CQueue() {
        while(!s1.empty()){
            s1.pop();
        }
        while(!s2.empty()){
            s2.pop();
        }
    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        } //s2必须为空的时候，我才能将s1全部转移过来
        if(s2.empty()){
            return -1;
        } else {
            int res = s2.top();
            s2.pop();
            return res;
        }
    }
};
```









#### [剑指 Offer 30. 包含min函数的栈](https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/)



遇到的问题:

* 如果定义一个min变量在每次push的进行一个比较从而得出最小值的话，那么如果这个新push的x为最小值，但是后面一步pop操作后，x就没了，最小值就变成了原栈中第二小的，此时应该怎么计算。
  * 可以构建一个辅助栈，每次push的时候将辅助栈的stack_help.top()与push的x比较，将小值入栈。注意：每次都需要这个操作，保证两个栈的长度相同。（这样pop的时候，两个栈都需要pop），此时最小值也就在辅助栈的栈顶了。当然为了保证代码运行，可以先将辅助栈push一个INT_MAX；



代码实现：

```cc
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
```

