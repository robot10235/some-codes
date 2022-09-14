#include <iostream> 
#include <stack>
#include <string>

using namespace std;
	
string removeDuplicates(string s) {
    stack<char> sta;
    sta.push(s[0]);
    for(int i = 1; i < s.size(); i ++) {
        if(sta.size() > 0 && s[i] == sta.top()) {
            sta.pop();
        }
        else {
            sta.push(s[i]);
        }
	}
	string result = "" ;
	while(!sta.empty()) {
		result += sta.top();
		sta.pop();
	}
	int left = 0;
	int right = result.size()-1;
	while(left < right) {
		char temp = result[left];
		result[left] = result[right];
		result[right] = temp;
		left ++;
		right --;
	}
	return result;
}

int main()
{
	cout << removeDuplicates("abbaca") << endl;
}
