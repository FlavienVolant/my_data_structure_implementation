#include <stdio.h>
#include <stdlib.h>         
#include <assert.h>

#include "hashmap.h"
#include "c_unit.h"

void* beforeEach() {
    return init_hashmap();
}

void afterEach(void* map) {
    free(map);
}

int put_a_key_value_then_get_the_value_by_giving_the_key(void *params) {

    struct hashmap *map = params;

    int key = 5;
    int value = 23;
    int res;

    ASSERT_TRUE(put(map, key, value) == SUCCESS);
    ASSERT_TRUE(get(map, key, &res) == SUCCESS);
    ASSERT_TRUE(res == value);

    return 0;
}

int put_a_key_bellow_zero_will_work(void *params) {

    struct hashmap *map = params;

    int key = - 5;
    int value = 23;
    int res;

    ASSERT_TRUE(put(map, key, value) == SUCCESS);
    ASSERT_TRUE(get(map, key, &res) == SUCCESS);
    ASSERT_TRUE(res == value);

    return 0;
}

int get_a_key_unknow_do_nothing(void *params) {

    struct hashmap *map = params;

    int key = 0;
    int res = -1;

    ASSERT_TRUE(get(map, key, &res) == KEY_UNKNOW);
    ASSERT_TRUE(res == -1);
    
    return 0;
}

int put_a_key_then_del_give_the_value(void *params) {

    struct hashmap *map = params;

    int key = 0;
    int value = 0;
    int res = -1;

    put(map, key, value);

    ASSERT_TRUE(del(map, key, &res) == SUCCESS);
    ASSERT_TRUE(res == value);
    ASSERT_TRUE(get(map, key, NULL) == KEY_UNKNOW);

    return 0;
}

int main() {

    struct TestList *tests = create_test_list();

    ADD_TEST(tests, put_a_key_value_then_get_the_value_by_giving_the_key);
    ADD_TEST(tests, put_a_key_bellow_zero_will_work);
    ADD_TEST(tests, get_a_key_unknow_do_nothing);
    ADD_TEST(tests, put_a_key_then_del_give_the_value);

    run_tests(tests, beforeEach, afterEach);

    free_test_list(tests);

    return 0;
}