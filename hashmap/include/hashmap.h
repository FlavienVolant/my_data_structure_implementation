#ifndef HASHMAP_H
#define HASHMAP_H

#define DEFAULT_CAPACITY 256
#define DEFAULT_LOAD_FACTOR 0.75

struct Hashmap {
    int capacity;
    int loadFactor;
    struct Node **table;
};

struct Node {
    int key;
    int value;
    struct Node *next;
};

enum HashMapReturnValue {
    SUCCESS = 0,
    KEY_UNKNOW = -1
};

struct Hashmap* init_hashmap();
enum HashMapReturnValue put(struct Hashmap *map, int key, int value);
enum HashMapReturnValue get(struct Hashmap *map, int key, int *res);
enum HashMapReturnValue del(struct Hashmap *map, int key, int *res);
void free_hashmap(struct Hashmap *map);

#endif