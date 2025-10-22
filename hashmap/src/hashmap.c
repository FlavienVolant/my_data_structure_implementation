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

enum HashMapReturnValue put(struct hashmap *map, int key, int value)
{
    if(key < 0 || key >= VALUES_COUNT)
        return WRONG_KEY_VALUE;

    map->values[key] = value;

    return SUCCESS;
}

enum HashMapReturnValue get(struct hashmap *map, int key, int *res)
{
    if(key < 0 || key >= VALUES_COUNT)
        return WRONG_KEY_VALUE;

    int val = map->values[key];

    if(val == VALUE_EMPTY)
        return KEY_UNKNOW;


    if(res != NULL)
        *res = val;

    return SUCCESS;
}

enum HashMapReturnValue del(struct hashmap *map, int key, int *res)
{
    if(key < 0 || key >= VALUES_COUNT)
        return WRONG_KEY_VALUE;
    
    int val = map -> values[key];

    if(val == VALUE_EMPTY)
        return KEY_UNKNOW;

    map -> values[key] = VALUE_EMPTY;
    
    if(res != NULL)
        *res = val;

    return SUCCESS;
}
