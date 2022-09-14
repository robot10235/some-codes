#include <iostream> 
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <pair>

using namespace std;

class MaxHeap{
	public:
		MaxHeap(){}
		
		void maxheapify(int i) {
			pair<int, int> temp;
			if(2 * i + 2 < heap.size()) {
				my = heap[i].second;
				left = heap[2 * i + 1].second; 
				right = heap[2 * i + 2].second;
				if(left > my && left >= right) {
					temp = heap[2 * i + 1];
					heap[2 * i + 1] = heap[i];
					heap[i] = temp;
					this->maxheapify(2 * i + 1);
				}
				else if(right > my && right >= left) {
					temp = heap[2 * i + 2];
					heap[2 * i + 2] = heap[i];
					heap[i] = temp;
					this->maxheapify(2 * i + 2);
				}
			}
			else if(2 * i + 1 < heap.size()){
				if(heap[2 * i + 1].second > heap[i].second) {
					temp = heap[2 * i + 1];
					heap[2 * i + 1] = heap[i];
					heap[i] = temp;
					this->maxheapify(2 * i + 1);
				}
			}
		}
		
		void h_push(pair<int, int> p) {
			heap.push_back(p);
			i = heap.size()-1;
			
			while(i >= 0) {
				int parent = (i - 1) / 2;
				if(heap[i].second > heap[parent].second) {
					pair<int, int> temp = heap[i];
					heap[i] = heap[parent];
					heap[parent] = temp;
					i = p;
				}
				else {
					break;
				}
			}
		}
		
		int h_pop() {
			int n = heap.size();
			if(n > 0) {
				pair<int, int> top = heap[0];
				heap[0] = heap[n-1];
				heap.pop_back();
				this->maxheapify(0);
			}
			return top.first;
		}
		
		vector<pair<int, int>> heap;
};

vector<int> topKFrequent(vector<int>& nums, int k) {
	unordered_map<int, int> um1;
	for(int i = 0; i < nums.size(); i ++) {
		um1[nums[i]] ++;
	}
	MaxHeap * mh = new MaxHeap();
	for(auto it = um1.begin(); it != um1.end(); it ++) {
		mh->h_push(make_pair(it->left, it->right));
	}
	vector<int> result;
	for(int i = 0; i < k; i++) {
		result.push_back(mh->h_pop());
	}
	delete(mh);
	return result;
}
