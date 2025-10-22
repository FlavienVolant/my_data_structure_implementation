#include <stdio.h>          
#include <assert.h>

#include "hashmap.h"

void put_a_key_value_then_get_the_value_by_giving_the_key() {

    struct hashmap *map = init_hashmap();

    int key = 5;
    int value = 23;
    int res;

    assert(put(map, key, value) == 0);
    assert(get(map, key, &res) == 0);
    assert(res == value);

    free_hashmap(map);
}

void put_a_key_bellow_zero_will_fail() {
    struct hashmap *map = init_hashmap();

    int key = - 5;
    int value = 23;

    assert(put(map, key, value) == -1);

    free_hashmap(map);
}

void get_a_key_unknow_will_fail() {
    struct hashmap *map = init_hashmap();

    int key = 0;
    int res = -1;

    assert(get(map, key, &res) == -2);
    assert(res == -1);
    
    free_hashmap(map);
}

void put_a_key_then_del_give_the_value() {
    struct hashmap *map = init_hashmap();

    int key = 0;
    int value = 0;
    int res = -1;

    put(map, key, value);

    assert(del(map, key, &res) == 0);
    assert(res == value);
    assert(get(map, key, NULL) == -2);

    free_hashmap(map);
}


int main() {
    printf("Welcome to the hashmap test\n");

    put_a_key_value_then_get_the_value_by_giving_the_key();
    put_a_key_bellow_zero_will_fail();
    get_a_key_unknow_will_fail();
    put_a_key_then_del_give_the_value();

    return 0;
}