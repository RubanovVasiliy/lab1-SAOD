#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MIN 0
#define MAX 100000

double wtime() {
	struct timeval t;
	gettimeofday(&t, NULL);
	return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int getrand(int min, int max) {
	return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf(" %d", arr[i]);
	}
	printf("\n\n");
}

void fillArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = getrand(MIN, MAX);
	}
}

void bubbleSort(int arr[], int n) {
	int swapped = 1;
	while (swapped == 1) {
		swapped = 0;
		int temp;
		for (int i = 0; i < n - 1; ++i) {
			if (arr[i] > arr[i + 1]) {
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swapped = 1;
			}
		}
	}
}

void countSort(int arr[], int n) {
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	max++;
	int count[max];

	for (int i = 0; i < max; i++) {
		count[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		count[arr[i]]++;
	}

	int temp = 0;
	int currentSorteddIndex = 0;

	for (int size = 0; size < max; size++) {
		temp = count[size];
		for (int k = 0; k < temp; k++) {
			arr[currentSorteddIndex] = size;
			currentSorteddIndex++;
		}
	}
}

int main(void) {
	int size;
	scanf("%d", &size);

	int a[size];
	fillArray(a, size);

	printArray(a, size);
	countSort(a, size);
	printArray(a, size);

	return 0;
}