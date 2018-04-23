#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// <------ MAX HEAP ------>

int heap[100005];

void heapify(int s, int size){
	int left = 2 * s, right = left + 1, largest;
	if(left <= size && heap[left] > heap[s]){
		largest = left;
	}
	else{
		largest = s;
	}
	if(right <= size && heap[right] > heap[largest]){
		largest = right;
	}
	if(largest > s){
		int temp = heap[s];
		heap[s] = heap[largest];
		heap[largest] = temp;
		heapify(largest, size);
	}
}

void insert(int item, int size){
	heap[size] = item;
	int curr = size, par = curr / 2;
	while(curr > 1 && heap[par] < heap[curr]){
		int temp = heap[par];
		heap[par] = heap[curr];
		heap[curr] = temp;
		curr = par; par = curr / 2;
	}
}

void delete(int size){
	heap[1] = heap[size];
	size = size - 1;
	heapify(1, size);
}

int main(){
	int n, i, size = 0;
	scanf("%d", &n);
	for(i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);
		insert(x, ++size);
		if(i > 2){
			int e1 = heap[1];
			delete(size--);
			int e2 = heap[1];
			delete(size--);
			int e3 = heap[1];
			printf("%lld\n", ((long long)e1 * (long long)e2 * (long long)e3));
			insert(e2, ++size);
			insert(e1, ++size);
		}
		else{
			printf("-1\n");
		}
	}
}