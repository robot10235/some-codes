#include <iostream> 
#include <vector>
#include <time.h>
#include <cstdlib>
#include <queue>

using namespace std;

class bomb{
	
	bomb(int l = 0, int w = 0) {
		this->width = w;
		this->length = l;
		for(int i = 0; i < this->length; i ++) {
			vector<int> temp;
			for(int j = 0; j < this->width; j ++) {
				temp.push_back(0);
			}
			this->zone.push_back(temp);
			this->show.push_back(temp);
		}
	}
	
	void set(int l, int w, int num) {
		// set bomb
		srand(time(NULL));
		for(int i = 0; i < num; i ++) {
			int pos = rand() % this->width * this->length;
			int pos_i = pos / this->width;
			int pos_j = pos % this->width;
			if(pos_i != l || pos_j != w) {
				this->zone[pos_i][pos_j] = -1;
				this->show[pos_i][pos_j] = -1;
			}
			else {
				i --;
			}
		}
		// init hint
		for(int i = 0; i < this->length; i ++) {
			for(int j = 0; j < this->width; j ++) {
				if(this->zone[i][j] != -1) {
					if(i > 0 && this->zone[i-1][j] == -1) {
						this->zone[i][j] ++;
					}
					if(i+1 < this->length && this->zone[i+1][j] == -1) {
						this->zone[i][j] ++;
					}
					if(j > 0 && this->zone[i][j-1] == -1) {
						this->zone[i][j] ++;
					}
					if(j+1 < this->width && this->zone[i][j+1] == -1) {
						this->zone[i][j] ++;
					}
				}
			}
		}
	}
	
	// bfs show like visited 
	int update_show(int i, int j) {
		// already shown
		if(this->show[i][j] == 1) {
			return 0;
		}
		
		// good game
		if(this->zone[pos_i][pos_j] == -1) {
			return -1;
		}
		
		queue<int> q;
		q.push(i * this->width);
		while(!q.empty()) {
			int pos = q.top();
			int pos_i = pos / this->width;
			int pos_j = pos % this->width;
			
			if(pos_i > 0 && this->show[pos_i-1][pos_j] == 0) {
				q.push((pos_i-1) * this->width + pos_j);
				show[pos_i-1][pos_j] = 1;
			}
			if(pos_i + 1 < this->length && this->show[pos_i+1][pos_j] == 0) {
				q.push((pos_i+1) * this->width + pos_j);
				show[pos_i+1][pos_j] = 1;
			}
			if(pos_j > 0 && this->show[pos_i][pos_j-1] == 0) {
				q.push(pos_i * this->width + pos_j-1);
				show[pos_i][pos_j-1] = 1;
			}
			if(pos_j + 1 < this->width && this->show[pos_i][pos_j+1] == 0) {
				q.push(pos_i * this->width + pos_j+1);
				show[pos_i][pos_j+1] = 1;
			}
		}
		return 1;
	}
	
	bool Win() {
		int flag = 1;
		for(int i = 0; i < this->length; i ++) {
			for(int j = 0; j < this->width; j ++) {
				if(this->show[i][j] == 0) {
					flag = 0;
					break;
				}
			}
		}
		if(flag)
			return true;
		return false;
	}
	
	void display(){
		
	}
	
	void Run() {
		int l, w, num, i, j;
		cout << "length: " << endl;
		cin >> l;
		cout << "width: " << endl;
		cin >> w;
		cout << "bomb num: " << endl;
		cin >> num;
		
		int flag = 1;
		
		while(!this->Win()) {
			cout << "i: " << endl;
			cin >> i;
			cout << "j: " << endl;
			cin >> j;
			if(flag) {
				this->set(i, j, num);
			}
			int status = this->update_show(i, j);
			if(status == 0) {
				cout << "invalid input" << endl;
				continue;
			}
			else if(status == -1) {
				cout << "you lose" << endl;
				break;
			}
			this->display();
		}
	}
	
	public:
		int width;
		int length;
		vector<vector<int>> zone;
		vector<vector<int>> show;
};
