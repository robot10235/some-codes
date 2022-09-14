#include <iostream> 
#include <vector>
#include <deque>

class new_queue{
	public:
		new_queue(){}
		
		void q_pop(int value) {
			if(value == nq.front()) {
				nq.pop_front();
			}
		}
		
		void q_push(int value) {
			while(!nq.empty() && value > nq.back()) {
				nq.pop_back();
			}
			nq.push_back(value);
		}
		
        int q_top() {
            return nq.front();
        }

		deque<int> nq;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        new_queue * nq1 = new new_queue();
        vector<int> result;
        for(int i = 0; i < k; i ++) {
            nq1->q_push(nums[i]);
        }
        result.push_back(nq1->q_top());
        for(int i = k; i < nums.size(); i ++) {
            nq1->q_pop(nums[i-k]);
            nq1->q_push(nums[i]);
            result.push_back(nq1->q_top());
        }
        delete(nq1);
        return result;
    }
};
