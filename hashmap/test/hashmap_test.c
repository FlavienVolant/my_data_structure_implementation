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

void put_a_key_value_then_get_the_value_by_giving_the_key(void *params) {

    struct hashmap *map = params;

    int key = 5;
    int value = 23;
    int res;

    assert(put(map, key, value) == SUCCESS);
    assert(get(map, key, &res) == SUCCESS);
    assert(res == value);
}

void put_a_key_bellow_zero_will_work(void *params) {

    struct hashmap *map = params;

    int key = - 5;
    int value = 23;
    int res;

    assert(put(map, key, value) == SUCCESS);
    assert(get(map, key, &res) == SUCCESS);
    assert(res == value);
}

void get_a_key_unknow_will_fail(void *params) {

    struct hashmap *map = params;

    int key = 0;
    int res = -1;

    assert(get(map, key, &res) == KEY_UNKNOW);
    assert(res == -1);

}

void put_a_key_then_del_give_the_value(void *params) {

    struct hashmap *map = params;

    int key = 0;
    int value = 0;
    int res = -1;

    put(map, key, value);

    assert(del(map, key, &res) == SUCCESS);
    assert(res == value);
    assert(get(map, key, NULL) == KEY_UNKNOW);
}

int main() {

    struct TestList *tests = create_test_list();

    ADD_TEST(tests, put_a_key_value_then_get_the_value_by_giving_the_key);
    ADD_TEST(tests, put_a_key_bellow_zero_will_work);
    ADD_TEST(tests, get_a_key_unknow_will_fail);
    ADD_TEST(tests, put_a_key_then_del_give_the_value);

    run_tests(tests, beforeEach, afterEach);

    free_test_list(tests);

    return 0;
}