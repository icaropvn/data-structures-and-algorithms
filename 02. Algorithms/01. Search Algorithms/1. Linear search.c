#include <stdio.h>

int linearSearch(int *array, int length, int key);

int main() {
	int numbers[100];
	int length = sizeof(numbers)/sizeof(int);
	int key;
	
	// Feeding the array 1 to 100
	for(int i=0; i<length; i++) {
		numbers[i] = i + 1;
	}
	
	printf("Insert a number to search in the array: ");
	scanf("%i", &key);
	
	int position = linearSearch(numbers, length, key);
	
	if(position != -1)
		printf("\nData found in index #%i in the array!", position);
	else
		printf("\nData isn't in the array.");
	
	return 0;
}

// Linear search function
int linearSearch(int *array, int length, int key) {
	for(int i=0; i<length; i++) {
		if(array[i] == key)
			return i;
	}
	
	return -1;
}
