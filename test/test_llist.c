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

void test_llist_IsNotEmptyAfterPrepend(void)
{
    LinkedList_Prepend(test_list, 1);
    TEST_ASSERT_FALSE(LinkedList_IsEmpty(test_list));
}

void test_llist_IsNotEmptyAfterAppend(void)
{
    LinkedList_Append(test_list, 1);
    TEST_ASSERT_FALSE(LinkedList_IsEmpty(test_list));
}

void test_llist_IsEmptyAfterAppendAndDelete(void)
{
    LinkedList_Append(test_list, 1);
    LinkedList_DeleteItem(test_list, 1);
    TEST_ASSERT_TRUE(LinkedList_IsEmpty(test_list));
}
