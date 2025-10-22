#ifndef HASHMAP_H
#define HASHMAP_H

struct hashmap {

};

struct hashmap* init_hashmap();
int destroy_hashmap(struct hashmap *map);
int put(struct hashmap *map, int key, int value);
int get(struct hashmap *map, int key, int *res);

#endif