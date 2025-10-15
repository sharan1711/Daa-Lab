#include<stdio.h>
#include<stdlib.h>
void printpass(int arr[], int left, int right)
{
	printf("Pass: ");
	for(int i=left;i<=right;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void merge(int arr[], int left, int mid, int right){
	int n1 = mid-left+1;
	int n2 = right - mid;
	int i,j,k;
	int *L = (int *)malloc(n1*sizeof(int));
	int *R = (int *)malloc(n2*sizeof(int));
	for(i=0;i<n1;i++) L[i] = arr[left + i];
	for(j=0;j<n2;j++) R[j] = arr[mid+1+j];
	i=0;j=0;k=left;

		while(i<n1 && j<n2){
			if(L[i]<= R[j])
				arr[k++] = L[i++];
			else arr[k++] = R[j++];
		}
	while(i<n1) arr[k++] = L[i++];
	while(j<n2) arr[k++] = R[j++];

	printpass(arr, left, right);
	}

void mergesort(int arr[], int left, int right){
	if(left<right){
		int mid = (left+right)/2;
		mergesort(arr, left, mid);
		mergesort(arr, mid+1, right);
		merge(arr,left,mid,right);
	}
}
int main(){
	int n, i;
	printf("no of elements: ");
	scanf("%d",&n);
	int arr[n];
	printf("elements: ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Given array:\n");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");

	mergesort(arr,0,n-1);
	printf("Sorted array:\n");
		for(i=0;i<n;i++){
		printf("%d ",arr[i]);
		}
		printf("\n");
	return 0;
		}