#ifndef HASHMAP_H
#define HASHMAP_H

#define VALUES_COUNT 256
#define VALUE_EMPTY -1

struct hashmap {
    int values[VALUES_COUNT];
};

struct hashmap* init_hashmap();
void free_hashmap(struct hashmap *map);
int put(struct hashmap *map, int key, int value);
int get(struct hashmap *map, int key, int *res);

#endif