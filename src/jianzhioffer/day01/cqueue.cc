#include <iostream>
#include <vector>
#include <stack>
using namespace std;

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
                s2.push(s2.top());
                s1.pop();
            }
        } //s2必须为空的时候，我才能将s1全部转移过来
        int res = -1;
        if(s2.empty()){
            return -1;
        } else {
            res = s2.top();
            s2.pop();
            return res;
        }
        return res;
    }
};

int main(){
    CQueue c;
    c.appendTail(3);
    std::cout << c.deleteHead() << std::endl;
    std::cout << c.deleteHead() << std::endl;
}