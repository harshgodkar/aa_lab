#include<bits/stdc++.h>
using namespace std;

void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high, int &count){
	int pivot = arr[high];

	int i = (low - 1);
 
	for (int j = low; j <= high - 1; j++) {
    	count++;
    	if (arr[j] < pivot) {
        	i++;
        	swap(&arr[i], &arr[j]);
    	}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

int r_partition(int arr[], int p, int r, int &count){
	srand(time(0));
	int i = (rand() % (r - p + 1)) + p ;
	swap(arr[i], arr[r]);
    
	return partition(arr, p, r, count);
}

void r_quick_sort(int arr[], int low, int high, int& count){
	if(low < high){
    	int q = r_partition(arr, low, high, count);
    	r_quick_sort(arr, low, q-1, count);
    	r_quick_sort(arr, q+1, high, count);
	}
}

int main(){
	int n = 1000;
	int arr[n];
	for(int i=0; i < n; i++){
    	arr[i] = i + 10;
	}
	int count = 0;
    
	r_quick_sort(arr, 0, n-1, count);
    
	cout << count << endl;
    
	return 0;
}
