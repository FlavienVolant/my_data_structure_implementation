#include "hashmap.h"

#include <stdlib.h>

struct hashmap *init_hashmap()
{
    struct hashmap *map = malloc(sizeof(struct hashmap));

    for(int i = 0; i < VALUES_COUNT; i ++) {
        map->values[i] = VALUE_EMPTY;
    }

    return map;
}

void free_hashmap(struct hashmap *map)
{
    free(map);
}

int put(struct hashmap *map, int key, int value)
{
    if(key < 0 || key >= VALUES_COUNT)
        return -1;

    map->values[key] = value;

    return 0;
}

int get(struct hashmap *map, int key, int *res)
{
    if(key < 0 || key >= VALUES_COUNT)
        return -1;

    int val = map->values[key];

    if(val == VALUE_EMPTY)
        return -2;

    *res = val;

    return 0;
}
