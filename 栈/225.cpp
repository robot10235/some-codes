#include <iostream> 
#include <queue>

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
		q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
		for(int i = 0; i < q1.size()-1; i++) {
			q1.push(q1.front());
			q1.pop();
		}
		int num = q1.front();
		q1.pop();
		return num;
    }
    
    /** Get the top element. */
    int top() {
		return q1.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
		return q1.empty();
    }
    
    queue<int> q1;
};


int main()
{
	MyStack* obj = new MyStack();
	obj->push(1);
	obj->push(2);
	int param_2 = obj->pop();
	int param_3 = obj->top();
 	bool param_4 = obj->empty();
 	cout<<param_2<<endl;
 	cout<<param_3<<endl;
 	cout<<param_4<<endl;
}
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
