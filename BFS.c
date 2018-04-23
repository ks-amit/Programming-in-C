#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// <------ QUEUE ------>
	//initialize rear = -1, front = 0 

int queue[100007];
int front = 0, rear = -1;

void push(int item){
	queue[++rear] = item;
}

int pop(){
	if(front == rear){
		int r = queue[front];
		front = 0;
		rear = -1;
		return r;
	}
	else{
		return queue[front++];
	}
}

int isEmpty(){
	return (front > rear);
}

int size(){
	return rear - front + 1;
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

	// ALLOCATE AND INITIALIZE NEW NODE

	node *temp1 = (node *)malloc(sizeof(node));
	temp1 -> ver = ver;
	temp1 -> w = w;
	temp1 -> next = NULL;

	// INSERT NEW NODE AT BEGINNING

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

void printVertex(int ver){
	node *temp = graph[ver];
	while(temp != NULL){
		printf("%d %d\n", temp -> ver, temp -> w);
		temp = temp -> next;
	}
}

// <------ BFS ------>

int visited[100005];
int dist[100005];

void BFS(int s){
	memset(visited, 0, sizeof(visited));
	int i;
	dist[s] = 0;
	push(s);
	visited[s] = 1;
	while(size() > 0){
		int curr = pop();
		// ANY OTHER OPERATION ON ENTRY 
		node *temp = graph[curr];
		while(temp != NULL){
			if(visited[temp -> ver] == 0){
				push(temp -> ver);
				visited[temp -> ver] = 1;
				dist[temp -> ver] = dist[curr] + 1;
				// ANY OTHER OPERATION
			}
			temp = temp -> next;
		}
	}
}

int main(){
	int t;
	scanf("%d", &t);
	while(t > 0){
		int n, m, i;
		scanf("%d %d", &n, &m);
		initGraph(n + 1);
		for(i = 0; i < m; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			graph[x] = insertEdge(graph[x], y, 0);
			graph[y] = insertEdge(graph[y], x, 0);
		}
		BFS(1);
		printf("%d\n", dist[n]);
		t--;	
	}
}