#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_LEVEL = 8;
const double RAND_LEVEL = 0.5;

struct node {
    int val;
    node* level[MAX_LEVEL];
};

class Skiplist {
public:
    Skiplist() {
        head = new node();
        head->val = INT_MIN;
    }
    
    bool search(int target) {
        node* it = searchHelper(target)[0];
        return it->level[0] != nullptr && it->level[0]->val == target;
    }
    
    void add(int num) {
        // random level
        int randlevel = 1;
        srand((unsigned)time(NULL));
        while(rand() / double(RAND_MAX) < RAND_LEVEL && randlevel < MAX_LEVEL) {
            ++randlevel;
        }
        
        node** p = searchHelper(num);
        node* newnode = new node();
        newnode->val = num;
        for(int i = 0; i < randlevel; ++i) {
            newnode->level[i] = p[i]->level[i];
            p[i]->level[i] = newnode;
        }
    }
    
    bool erase(int num) {
        node** it = searchHelper(num);
        if(it[0]->level[0] == nullptr || it[0]->level[0]->val != num) {
            return false;
        }
        node* del = it[0]->level[0];
        for(int i = 0; i < MAX_LEVEL; ++i) {
            if(it[i]->level[i] == del) {
                it[i]->level[i] = del->level[i];
            }
        }
        return true;
    }

private:
    node** searchHelper(int target) {
        for(int i = 0; i < MAX_LEVEL; ++i) prev[i] = nullptr;
        node* cur = head;
        for(int i = MAX_LEVEL-1; i >= 0; --i) {
            while(cur->level[i] != nullptr && cur->level[i]->val < target) {
                cur = cur->level[i];
            }
            prev[i] = cur;
        }
        return prev;
    }

    node* prev[MAX_LEVEL];
    node* head;
};