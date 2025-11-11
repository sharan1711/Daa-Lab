#include <stdio.h>
#define INF 99999
#define MAX_N 20 // Maximum value for N
int main() {
	int N, E;
	printf("Enter the number of vertices : ");
	scanf("%d", &N);
	printf("Enter the number of edges : ");
	scanf("%d", &E);
	int dist[N][N];
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if(i == j)
				dist[i][j] = 0;
			else
				dist[i][j] = INF;
		}
	}
	for (int i = 0; i < E; i++){
		int src,dest,weight;
		printf("Enter source : ");
		scanf("%d", &src);
		printf("Enter destination : ");
		scanf("%d", &dest);
		printf("Enter weight : ");
		scanf("%d", &weight);

		dist[src - 1][dest - 1] = weight;
	}


	for(int k = 0; k < N; k++){
		for(int i = 0; i<N; i++){
			for(int j = 0; j < N; j++){
				if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	printf("The following matrix shows the shortest distances between all pairs of the vertices.\n");

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (dist[i][j] == INF)
				printf("  INF");
			else
				printf("%5d",dist[i][j]);
		}
		printf("\n");
	}
	return 0;
}