#include <limits.h> 
#include <stdio.h>
#define MAX 20
int V, E;
int graph[MAX][MAX];
#define INFINITY 99999
void printPath(int parent[],int j,int startnode){
	int path[MAX];
	int index = 0;

	while (j != -1 && j != startnode) {
		path[index++] = j;
		j = parent[j];
	}

	for (int i = 0; i<index; i++){
		printf("%d<-",path[i]);
	}
	printf("%d", startnode);
}
void dijkstra(int G[MAX][MAX], int n, int startnode) {
int dist[MAX], visited[MAX],parent[MAX];
	int i, count, v, min_dist;

	for (i=1; i<=n; i++){
		dist[i] = INFINITY;
		visited[i] = 0;
		parent[i] = -1;
	}
	dist[startnode] = 0;

	
	for (count = 1; count < n; count++){
		min_dist = INFINITY;
		v = -1;
		for (i = 1;i <=n; i++){
			if (!visited[i] && dist[i] < min_dist){
				min_dist = dist[i];
				v = i;
			}
		}
		if (v == -1)
			break;

		visited[v] = 1;

		for(i = 1; i<=n; i++){
			if (!visited[i] && G[v][i] != 0 && dist[v] != INFINITY && dist[v] +                 G[v][i] < dist[i]) {
				dist[i] = dist[v] + G[v][i];
				parent[i] = v;
			}
		}
	}

	printf("Node\tDistance\tPath\n");
	for (i=1; i<=n; i++){
		if (i == startnode)
			continue;
		printf("   %d\t", i);
		if(dist[i] == INFINITY){
			printf("     INF\tNO PATH\n");
		} else {
			printf("       %d\t", dist[i]);
			printPath(parent, i, startnode);
			printf("\n");
		}
	}

}
int main() { 
	int s, d, w, i, j;
	printf("Enter the number of vertices : ");
	scanf("%d", &V);
	printf("Enter the number of edges : ");
	scanf("%d", &E);
	for(i = 1 ; i <= V; i++) {
		for(j = 1; j <= V; j++) {
			graph[i][i] = 0;
		}
	}
	for(i = 1; i <= E; i++) {
		printf("Enter source : ");
		scanf("%d", &s);
		printf("Enter destination : ");
		scanf("%d", &d);
		printf("Enter weight : ");
		scanf("%d", &w);
		if(s > V || d > V || s <= 0 || d <= 0) {
			printf("Invalid index. Try again.\n");
			i--;
			continue;
		} else {
			graph[s][d] = w;
		}
	}
	printf("Enter the source :");
	scanf("%d", &s);
	dijkstra(graph, V, s); 
	return 0; 
} 