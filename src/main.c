/*main.c*/

//Created by Daria Shinkevich, BSU, FAMCS, group 15

/*	 This program fills two sequences with random integer numbers,
*	 counts the number of even number in the first sequence and the number of odd in the second
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned int BOOL;
#define FALSE 0
#define TRUE 1

BOOL is_even(int number) {
	if (number % 2 == 0) {
		return TRUE;
	}
	return FALSE;
}

//fills array with integer random numbers. Numbers are in range [1,1000]
void init_array(int* array, int array_size) {
	for (int i = 0; i < array_size; i++) {
		array[i] = rand() % 1000 + 1;
	}
}

void print_array(int* array, int array_size) {
	for (int i = 0; i < array_size; i++) {
		printf("%d ", array[i]);
	}
}

int main() {
	const int sequence_length = 8;
	int* a_sequence = (int*)malloc(sequence_length * sizeof(int));
	int* b_sequence = (int*)malloc(sequence_length * sizeof(int));
	int num_of_even_a = 0;
	int num_of_odd_b = 0;

	srand(time(NULL));

	init_array(a_sequence, sequence_length);
	init_array(b_sequence, sequence_length);

	printf("a sequence:\n");
	print_array(a_sequence, sequence_length);
	printf("\nb sequence:\n");
	print_array(b_sequence, sequence_length);

	for (int i = 0; i < sequence_length; i++) {
		if (is_even(a_sequence[i])) {
			num_of_even_a++;
		}
	}

	for (int i = 0; i < sequence_length; i++) {
		if (!is_even(b_sequence[i])) {
			num_of_odd_b++;
		}
	}

	printf("\n\nnumber of even numbers in a sequence: %d\n", num_of_even_a);
	printf("number of odd numbers in b sequence: %d\n", num_of_odd_b);

	return 0;
}