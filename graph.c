#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

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

void printVertex(int ver){
	node *temp = graph[ver];
	while(temp != NULL){
		printf("%d %d\n", temp -> ver, temp -> w);
		temp = temp -> next;
	}
}

int main(){
	initGraph(11);
	int i;
	for(i = 1; i < 5; i++){
		graph[i] = insertEdge(graph[i], i + 1, 3);
	}
	for(i = 1; i < 10; i++){
		graph[i] = insertEdge(graph[i], i + 2, 5);
	}
	for(i = 0; i <= 10; i++){
		printf("\nVERTEX --> %d\n", i);
		printVertex(i);
	}
}
