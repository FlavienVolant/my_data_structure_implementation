#include "hashmap.h"

#include <stdlib.h>

struct hashmap *init_hashmap()
{
    struct hashmap *map = malloc(sizeof(struct hashmap));

    map->capacity = DEFAULT_CAPACITY;
    map->loadFactor = DEFAULT_LOAD_FACTOR;

    map->values = malloc(sizeof(int) * map->capacity);

    for(int i = 0; i < map->capacity; i ++) {
        map->values[i] = VALUE_EMPTY;
    }

    return map;
}

void free_hashmap(struct hashmap *map)
{
    free(map->values);
    free(map);
}

unsigned int hash(struct hashmap *map, int key) {
    return (unsigned int) key % map->capacity;
}

enum HashMapReturnValue put(struct hashmap *map, int key, int value)
{
    unsigned int hash_key = hash(map, key);

    map->values[hash_key] = value;

    return SUCCESS;
}

enum HashMapReturnValue get(struct hashmap *map, int key, int *res)
{
    unsigned int hash_key = hash(map, key);

    int val = map->values[hash_key];

    if(val == VALUE_EMPTY)
        return KEY_UNKNOW;


    if(res != NULL)
        *res = val;

    return SUCCESS;
}

enum HashMapReturnValue del(struct hashmap *map, int key, int *res)
{
    unsigned int hash_key = hash(map, key);
    
    int val = map -> values[hash_key];

    if(val == VALUE_EMPTY)
        return KEY_UNKNOW;

    map -> values[hash_key] = VALUE_EMPTY;
    
    if(res != NULL)
        *res = val;

    return SUCCESS;
}
