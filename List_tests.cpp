// Project UID c1f28c309e55405daf00c565d57ff9ad

#include "List.h"
#include "unit_test_framework.h"

using namespace std;

// Add your test cases here

TEST(test_empty) {
    List<int> empty_list;
    ASSERT_TRUE(empty_list.empty());
}

TEST(test_size) {
    List<int> my_list;

    my_list.empty();
    ASSERT_TRUE(my_list.size() == 0);

    my_list.push_back(99);
    my_list.push_back(73);
    ASSERT_TRUE(my_list.size() == 2);


}

TEST(test_push_front_back) {
    List<int> my_list;
    my_list.push_back(42);
    my_list.push_front(36);
    my_list.push_back(0);
    my_list.push_back(4);
    my_list.push_front(2);

    ASSERT_TRUE(my_list.size() == 5);

}

TEST(test_get_front_and_back) {
    List<int> my_list;
    my_list.push_back(42);
    my_list.push_front(36);
    my_list.push_back(0);
    my_list.push_back(4);
    my_list.push_front(2);

    ASSERT_TRUE(my_list.front() == 2);
    ASSERT_TRUE(my_list.back() == 4);

}

TEST(test_pop_front_back) {
    List<int> my_list;
    my_list.push_back(42);
    my_list.push_front(36);
    my_list.push_back(21);
    my_list.push_back(4);
    my_list.push_front(2);

    my_list.pop_back();
    my_list.pop_front();

    assert(my_list.front() == 36);
    ASSERT_TRUE(my_list.back() == 21);

    my_list.pop_back();
    my_list.pop_back();
    my_list.pop_back();

    ASSERT_TRUE(my_list.size() == 0);

}

TEST(test_clear) {
    List<int> my_list;
    my_list.push_back(42);
    my_list.push_front(36);
    my_list.push_back(21);
    my_list.push_back(4);
    my_list.push_front(2);
    
    my_list.clear();

    ASSERT_TRUE(my_list.size() == 0);
    ASSERT_TRUE(my_list.empty());

}

TEST(test_basic) {
    List<int> my_list;

    int size = 0;
    my_list.empty();
    my_list.size();
    assert(my_list.size() == size);

    my_list.push_front(42);
    my_list.push_back(42);

    my_list.front() = 73;
    my_list.back() = 73;

    my_list.pop_front();
    my_list.pop_back();

    List<int> list2(my_list);
    list2 = my_list;

    List<int>::Iterator iter = my_list.begin();
    my_list.insert(iter, 42);
    iter = my_list.begin();
    my_list.erase(iter);
    iter = my_list.begin();

    List<int>::Iterator iter2 = my_list.end();
    const List<int>::Iterator iter3 = iter2;

    bool b = iter == iter2;
    b = iter3 == my_list.end();
    b = my_list.end() == iter3;
    my_list.push_front(42);
    my_list.push_back(42);
    iter = my_list.begin();
    b = iter != iter2;
    b = iter3 != my_list.end();
    b = my_list.end() != iter3;
    assert(b == 0);
    ++iter;

    assert(*iter == 42);

    List<int>::Iterator iter_cpy(iter);
    iter_cpy = iter;

    assert(*++--iter == 42);
    assert(*--++my_list.begin() == 42);

    my_list.insert(my_list.begin(), 3);
    my_list.erase(my_list.begin());

    List<int> list3;
    list3.push_back(3);
    assert(*list3.begin() == 3);

    List<int> list4;
    list4.push_back(4);
    assert(list4.size() == 1);

    my_list.clear();
}


TEST_MAIN()
