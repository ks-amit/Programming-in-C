#include<stdio.h>
#include<stdlib.h>

// <------ DISJOINT SUBSET ------>

int dsu[100005], size[100005];

void setupDS(int dsu[], int size[], int n){
	for(int i = 0; i < n; i++){
		dsu[i] = i;
		size[i] = 1;
	}
}

int rootDS(int dsu[], int n, int A){
	while(dsu[A] != A){
		dsu[A] = dsu[dsu[A]];
		A = dsu[A];
	}
	return A;
}

void unionDS(int dsu[], int size[], int n, int A, int B){
	int rootA = rootDS(dsu, n, A);
	int rootB = rootDS(dsu, n, B);
	if(size[rootA] < size[rootB]){
		dsu[rootA] = dsu[rootB];
		size[rootB] += size[rootA];
	}
	else{
		dsu[rootB] = dsu[rootA];
		size[rootA] += size[rootB];
	}
}

struct newtype{
	int A;
	int B;
	int weight;
};
typedef struct newtype node;

int kruskals(node arr[], int n){
	int i, minCost = 0;
	for(i = 0; i < n; i++){
		if(rootDS(dsu, n, arr[i].A) != rootDS(dsu, n, arr[i].B)){
			minCost += arr[i].weight;
			unionDS(dsu, size, n, arr[i].A, arr[i].B);
		}
	}
	return minCost;
}

int cmp(const void *a,const void *b){
	node A = *(const node *)a;
	node B = *(const node *)b;
	if((A).weight < (B).weight){
		return -1;
	}
	return 1;
}

int main(){
	int n, m, i;
	scanf("%d %d", &n, &m);
	node edge[m];
	setupDS(dsu, size, n);
	for(i = 0; i < m; i++){
		int x, y, w;
		scanf("%d %d %d", &edge[i].A, &edge[i].B, &edge[i].weight);
	}
	qsort((void *)edge, m, sizeof(edge[0]), cmp);
	int ans = kruskals(edge, m);
	printf("%d\n", ans);
}