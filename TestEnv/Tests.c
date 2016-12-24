/*
 * Tests.c
 *
 *  Created on: Apr 2, 2016
 *      Author: helmelig
 */
#include <Util.h>
#include "Sort.h"
void SORT_INSERTION_TEST(void **state) {

	(void) state;

	u8 testArray[] = { 3, 7, 1, 2, 9, 5 };
	const u8 expcted[] = { 1, 2, 5, 5, 7, 9 };

	Sort_Insertion(testArray, (u8) NELEMS(testArray));

	u8 index = 0;
	for (index = 0; index < NELEMS(expcted); index++) {
		assert_int_equal(testArray[index], expcted[index]);
	}

}

void SORT_MERGE_TEST(void **state) {

	(void) state;

	u8 testArray[] = { 3, 7, 1, 2, 9, 5, 4, 6 };
	const u8 expcted[] = { 1, 2, 3, 4, 5, 6, 7, 9 };

	Sort_Merge(testArray, NELEMS(testArray), 0);
#ifdef DEBUG
	u8 printIndex = 0;
	for (printIndex = 0; printIndex < NELEMS(testArray); printIndex++) {
		printf("%d ", testArray[printIndex]);
	}
#endif
	u8 index = 0;
	for (index = 0; index < NELEMS(expcted); index++) {
		assert_int_equal(testArray[index], expcted[index]);
	}
	//assert_int_equal(0,5);
}


void SUM_TEST(void **state) {

	(void) state;

int x=10; int y=10 ; int z;
z=x+y;


assert_int_equal(z,20);

}
