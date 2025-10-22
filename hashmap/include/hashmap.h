#ifndef HASHMAP_H
#define HASHMAP_H

#define VALUES_COUNT 256
#define VALUE_EMPTY -1

struct hashmap {
    int values[VALUES_COUNT];
};

enum HashMapReturnValue {
    SUCCESS = 0,
    WRONG_KEY_VALUE = -1,
    KEY_UNKNOW = -2
};

struct hashmap* init_hashmap();
void free_hashmap(struct hashmap *map);
enum HashMapReturnValue put(struct hashmap *map, int key, int value);
enum HashMapReturnValue get(struct hashmap *map, int key, int *res);
enum HashMapReturnValue del(struct hashmap *map, int key, int *res);

#endif