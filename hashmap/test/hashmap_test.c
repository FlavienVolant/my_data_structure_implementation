#include <stdio.h>          
#include <assert.h>

#include "hashmap.h"

void put_a_key_value_then_get_the_value_by_giving_the_key() {

    struct hashmap *map = init_hashmap();

    int key = 5;
    int value = 23;
    int res;

    put(map, key, value);
    assert(get(map, key, &res) == 0);
    assert(res == value);
}


int main() {
    printf("Welcome to the hashmap test\n");

    put_a_key_value_then_get_the_value_by_giving_the_key();

}