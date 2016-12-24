/*
 * Sort.c
 *
 *  Created on: Apr 1, 2016
 *      Author: helmelig
 */

#include <Util.h>
#include "Sort.h"

static void swap(u8 testArray[], u8 index1, u8 index2);
static void merge(u8 testArray[], const u8 startIndex, const u8 size);

/*  Insertion sort:
 *  Stable
 *  O(1) extra space
 *  O(n2) comparisons and swaps
 *  Adaptive: O(n) time when nearly sorted
 *  Very low overhead
 */
void Sort_Insertion(u8 testArray[], u8 size) {
	u8 key, walker;

	for (key = 1; key < size; key++) {

		for (walker = key; walker > 0; walker--) {
			if (testArray[walker] < testArray[walker - 1])
				swap(testArray, walker, walker - 1);
			else
				break;
		}

	}
}


/**
 * Algo: -If the input sequence has only one element, return.
 *       -Partition the input sequence into two halves.
 *       -Sort the two subsequences using the same algorithm.
 *       -Merge the two sorted subsequences to form the output sequence.
 *Props: -Stable
 *		 -O(lg(n)) extra space for linked lists
 *		 -O(n·lg(n)) time
 *		 -Not adaptive
 *		 -Does not require random access to data
 * */
void Sort_Merge(u8 testArray[], u8 size, u8 start) {
#ifdef DEBUG
	printf("size %d start %d\n", size, start);
#endif
	if (size == 1)
		return;
	u8 pivot = size / 2;
	Sort_Merge(testArray, pivot, start);
	Sort_Merge(testArray, pivot, start + pivot);
	merge(testArray, start, size);

	return;
}

static void merge(u8 testArray[], const u8 startIndex, const u8 size) {

	int leftIndex = startIndex;
	int rightIndex = startIndex + size / 2;
	u8 mergeIndex = 0;
	while (mergeIndex < size) {
		if (testArray[leftIndex] > testArray[rightIndex]) {
			swap(testArray, leftIndex, rightIndex);
			rightIndex++;
		} else {
			leftIndex++;
		}
		mergeIndex++;
	}
}

static void swap(u8 testArray[], u8 index1, u8 index2) {
	u8 temp = testArray[index1];
	testArray[index1] = testArray[index2];
	testArray[index2] = temp;
}


