#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cstdlib>

using namespace std;

int evalRPN(vector<string>& tokens) {
	stack<int> num_sta;
	for(int i = 0; i < tokens.size(); i++) {
		string t = tokens[i];
		if(t == "+") {
			int n1 = num_sta.top();
			num_sta.pop();
			int n2 = num_sta.top();
			num_sta.pop();
			num_sta.push(n1 + n2);
		}
		else if(t == "-") {
			int n1 = num_sta.top();
			num_sta.pop();
			int n2 = num_sta.top();
			num_sta.pop();
			num_sta.push(n1 - n2);
		}
		else if(t == "*") {
			int n1 = num_sta.top();
			num_sta.pop();
			int n2 = num_sta.top();
			num_sta.pop();
			num_sta.push(n1 * n2);
		}
		else if(t == "/") {
			int n1 = num_sta.top();
			num_sta.pop();
			int n2 = num_sta.top();
			num_sta.pop();
			num_sta.push(n1 / n2);			
		}
		else {
			num_sta.push(atoi(t.c_str()));
		}
	}
	return num_sta.top();
}

int main()
{
	vector<string> tk;
	//tk.push_back("4");
	tk.push_back("13");
	tk.push_back("5");
	tk.push_back("/");
	//tk.push_back("+");
	cout<<evalRPN(tk)<<endl;
}
