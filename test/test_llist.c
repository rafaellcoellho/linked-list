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

void test_llist_IsEmptyAfterPrependThenDelete(void)
{
    LinkedList_Prepend(test_list, 1);
    LinkedList_DeleteItem(test_list, 1);
    TEST_ASSERT_TRUE(LinkedList_IsEmpty(test_list));
}

void test_llist_IsEmptyAfterAppendThenDelete(void)
{
    LinkedList_Append(test_list, 1);
    LinkedList_DeleteItem(test_list, 1);
    TEST_ASSERT_TRUE(LinkedList_IsEmpty(test_list));
}

void test_llist_DeleteItemThatDoesNotExist(void)
{
    LinkedList_Append(test_list, 1);
    LinkedList_DeleteItem(test_list, 2);
    TEST_ASSERT_FALSE(LinkedList_IsEmpty(test_list));
}

void test_llist_DeleteItemInEmptyList(void)
{
    LinkedList_DeleteItem(test_list, 2);
    TEST_ASSERT_TRUE(LinkedList_IsEmpty(test_list));
}

void test_llist_ListOfMultipleSizes(void)
{
    LinkedList_Prepend(test_list, 1);
    LinkedList_Prepend(test_list, 2);
    TEST_ASSERT_EQUAL_UINT32(2 ,LinkedList_GetSize(test_list));
    LinkedList_Prepend(test_list, 3);
    TEST_ASSERT_EQUAL_UINT32(3 ,LinkedList_GetSize(test_list));
    LinkedList_DeleteItem(test_list, 1);
    TEST_ASSERT_EQUAL_UINT32(2 ,LinkedList_GetSize(test_list));
}

void test_llist_ShiftEmptyList(void)
{
    TEST_ASSERT_EQUAL_UINT16(0, LinkedList_Shift(test_list));
}

void test_llist_ShiftListWithSizeOne(void)
{
    LinkedList_Prepend(test_list, 1);
    TEST_ASSERT_EQUAL_UINT16(1, LinkedList_Shift(test_list));
}

void test_llist_ShiftAndListIsEmpty(void)
{
    LinkedList_Prepend(test_list, 1);
    LinkedList_Shift(test_list);
    TEST_ASSERT_TRUE(LinkedList_IsEmpty(test_list));
}

void test_llist_ShiftAndListIsNotEmpty(void)
{
    LinkedList_Prepend(test_list, 1);
    LinkedList_Prepend(test_list, 2);
    LinkedList_Shift(test_list);
    TEST_ASSERT_FALSE(LinkedList_IsEmpty(test_list));
}
