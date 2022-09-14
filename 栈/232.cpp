#include <iostream> 
#include <stack>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
		s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
    	// build queue
    	if(s2.empty()) {
    		while(s1.size() > 0) {
				s2.push(s1.top());
				s1.pop();
			}
		}
		// pop
		int num = s2.top();
		s2.pop();
		return num;
    }
    
    /** Get the front element. */
    int peek() {
		// build queue
    	if(s2.empty()) {
    		while(s1.size() > 0) {
				s2.push(s1.top());
				s1.pop();
			}
		}
		// pop
		int num = s2.top();
		return num;	
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
		return (s1.empty() && s2.empty());
    }
    
    stack<int> s1;
    stack<int> s2;
};

int main()
{
	MyQueue* obj = new MyQueue();
	obj->push(1);
	obj->push(2);
	obj->push(3);
	int param_2 = obj->pop();
	int param_3 = obj->peek();
	bool param_4 = obj->empty();
	cout << param_2 << param_3 << param_4 << endl;
}
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
