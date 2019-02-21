#include "unity.h"
#include "llist.h"

llist *test_list;

void setUp(void)
{
    test_list = LinkedList_Create();
}

void tearDown(void)
{
    LinkedList_Destroy(test_list);
}

void test_llist_IsEmptyAfterCreate(void)
{
    TEST_ASSERT_TRUE(LinkedList_IsEmpty(test_list));
}
