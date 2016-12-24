#ifndef NULL
#define NULL 0
#endif

#include <Util.h>

extern void SORT_INSERTION_TEST(void **state);
extern void SORT_MERGE_TEST(void **state);
extern void SUM_TEST(void **state);

int main(void) {

	cmocka_set_message_output(CM_OUTPUT_TAP);

	const struct CMUnitTest tests[] = {
	cmocka_unit_test(SORT_INSERTION_TEST),
	cmocka_unit_test(SORT_MERGE_TEST),
	cmocka_unit_test(SUM_TEST)};



	return cmocka_run_group_tests(tests, NULL, NULL);

}
