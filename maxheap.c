#include <stdio.h>

// definition of max heap:
// a[root] > a[2 * root + 1] && a[root] > a[2 * root + 2]
// max heap is a complete binary tree

// place the root into the right place of a max heap
// O(logn) time since the tree height is logn
void maxheapify(int * a, int root, int n) {
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    int great = root;
    if(left < n && a[left] > a[great]) {
        great = left;
    }
    if(right < n && a[right] > a[great]) {
        great = right;
    }
    if(great != root) {
        int temp = a[root];
        a[root] = a[great];
        a[great] = temp;
        maxheapify(a, great, n);        
    }
}

// O(nlogn)
void buildMaxHeap(int * a, int n) {
    // find the last non leaf node 
    // it must be the parent of the last node
    int parent = n / 2 - 1;
    int i;
    for(i = parent; i >= 0; --i) {
        maxheapify(a, i, n);
    }
}