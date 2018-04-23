#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct newtype1{
	int A;
	int B;
};
typedef struct newtype1 pair;

// <------ MIN HEAP OF PAIRS ------>

pair heap[100005];
int heapsize;

void insert(int w, int v){
	pair P; P.A = w; P.B = v;
	heapsize++;
	heap[heapsize] = P;
	int curr = heapsize, par = curr / 2;
	while(heap[curr].A < heap[par].A){
		pair temp = heap[curr];
		heap[curr] = heap[par];
		heap[par] = temp;
		curr = par; par = curr / 2;
	}
}

void heapify(int s){
	int left = 2 * s, right = left + 1, largest;
	if(left <= heapsize && heap[left].A < heap[s].A){
		largest = left;
	}
	else{
		largest = s;
	}
	if(right <= heapsize && heap[right].A < heap[largest].A){
		largest = right;
	}
	if(largest != s){
		pair temp = heap[s];
		heap[s] = heap[largest];
		heap[largest] = temp;
		heapify(largest);
	}
}

pair delete(){
	pair R = heap[1];
	heap[1] = heap[heapsize];
	heapsize--;
	heapify(1);
	return R;
}

// <------ GRAPH ------>

struct newtype{
	int ver;
	int w;
	struct newtype *next;
};
typedef struct newtype node;

node *graph[100005];

node* insertEdge(node *head, int ver, int w){
	node *temp = head;
	node *temp1 = (node *)malloc(sizeof(node));
	temp1 -> ver = ver;
	temp1 -> w = w;
	temp1 -> next = NULL;
	if(temp == NULL){
		head = temp1;
	}
	else{
		temp1 -> next = temp;
		head = temp1;
	}
	return head;
}

void initGraph(int size){
	int i;
	for(i = 0; i < size; i++){
		graph[i] = NULL;
	}
}

// <------ DIJKSTRA ------>  

int dist[100005];
int visited[100005];

void dijkstra(int s){
	// INITIALIZE DISTANCE ARRAY TO INF OUTSIDE THE FUNCTION
	memset(visited, 0, sizeof(visited));
	heapsize = 0;
	dist[s] = 0;
	insert(0, s);
	while(heapsize > 0){
		pair curr = delete();
		int ver = curr.B;
		int wei = curr.A;
		visited[ver] = 1;
		node *temp = graph[ver];
		while(temp != NULL){
			if(visited[temp -> ver] == 0 && dist[temp -> ver] > wei + temp -> w){
				dist[temp -> ver] = wei + temp -> w;
				insert(dist[temp -> ver], temp -> ver);
			}
			temp = temp -> next;
		}
	}
}                                                                                                                                                                                                                               

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, m, i;
		scanf("%d %d", &n, &m);
		for(i = 0; i < m; i++){
			int x, y, w;
			scanf("%d %d %d", &x, &y, &w);
			graph[x] = insertEdge(graph[x], y, w);
			graph[y] = insertEdge(graph[y], x, w);
		}
		for(i = 0; i <= n; i++){
			dist[i] = 1000000007;
		}
		dijkstra(1);
		for(i = 1; i <= n; i++){
			printf("%d ", dist[i]);
		}
	}
}