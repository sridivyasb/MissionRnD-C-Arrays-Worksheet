/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>

void * removeArrayDuplicates(int *Arr, int len)
{
	int sorted = 1;
	for (int index = 0; index < len - 1; index++) {
		if (Arr[index] <= Arr[index + 1])
			continue;
		else {
			sorted = 0;
			break;
		}
	}
	if (sorted) {
		int j = 0;
		for (int index = 1; index < len; index++){
			if (Arr[index] != Arr[j]) {
				j++;
				Arr[j] = Arr[index]; // Move it to the front
			}
		}
		len = j + 1;
	}
	else {
		for (int index = 0; index < len; index++) {
			int j = index + 1;
			while (j < len) {
				if (Arr[j] == Arr[index]) {
					for (int k = j; k < len; k++)
						Arr[k] = Arr[k + 1];
					len--;
				}
				else
					j++;
			}
		}
	}
	return NULL;
}