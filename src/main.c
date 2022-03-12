/*main.c*/

//Created by Daria Shinkevich, BSU, FAMCS, gr15

/*	 This program fills two sequences with random integer numbers,
*	   counts the number of even number in the first sequence 
*    and the number of odd in the second
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

int main() {
	const int sequence_length = 8;
	int* a_sequence = (int*)malloc(sequence_length * sizeof(int));
	int* b_sequence = (int*)malloc(sequence_length * sizeof(int));
	int num_of_even_a = 0;
	int num_of_odd_b = 0;

	srand(time(NULL));

	for (int i = 0; i < sequence_length; i++) {
		a_sequence[i] = rand() % 1000 + 1;
	}
	for (int i = 0; i < sequence_length; i++) {
		b_sequence[i] = rand() % 1000 + 1;
	}

	printf("a sequence:\n");
	for (int i = 0; i < sequence_length; i++) {
		printf("%d ", a_sequence[i]);
	}
	printf("\nb sequence:\n");
	for (int i = 0; i < sequence_length; i++) {
		printf("%d ", b_sequence[i]);
	}

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