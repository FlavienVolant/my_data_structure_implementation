#ifndef HASHMAP_H
#define HASHMAP_H

#define DEFAULT_CAPACITY 256
#define DEFAULT_LOAD_FACTOR 0.75
#define VALUE_EMPTY -1

struct hashmap {
    int capacity;
    int loadFactor;
    int *values;
};

enum HashMapReturnValue {
    SUCCESS = 0,
    KEY_UNKNOW = -1
};

struct hashmap* init_hashmap();
void free_hashmap(struct hashmap *map);
enum HashMapReturnValue put(struct hashmap *map, int key, int value);
enum HashMapReturnValue get(struct hashmap *map, int key, int *res);
enum HashMapReturnValue del(struct hashmap *map, int key, int *res);

#endif