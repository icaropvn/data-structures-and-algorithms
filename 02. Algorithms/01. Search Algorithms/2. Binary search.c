#include <stdio.h>

int isSorted(int *array, int length);
int binarySearch(int *array, int length, int key);

int main() {
	int numbers[100];
	int length = sizeof(numbers)/sizeof(int);
	int key;
	
	// Feeding the array 1 to 100 (sorted)
	for(int i=0; i<length; i++) {
		numbers[i] = i + 1;
	}

	// Stop execution if array not sorted
	if(!isSorted(numbers, length)) {
		printf("The Binary Search can't be applied to an unsorted array.");
		return 0;
	}
	
	printf("Insert a number to search in the array: ");
	scanf("%i", &key);
	
	int position = binarySearch(numbers, length, key);
	
	if(position != -1)
		printf("\nData found in index #%i in the array!", position);
	else
		printf("\nData isn't in the array.");
	
	return 0;
}

// Verify array sort
int isSorted(int *array, int length) {
	for(int i=1; i<length; i++) {
		if(array[i] < array[i-1])
			return 0;
	}
	
	return 1;
}

// Binary search function
int binarySearch(int *array, int length, int key) {
	
	int low = 0;
	int high = length - 1;
	
	while(low <= high) {
		int middle = low + (high - low) / 2;
		
		if(array[middle] == key)
			return middle;
		else if(array[middle] < key)
			low = middle + 1;
		else
			high = middle - 1;
	}
	
	return -1;
}
