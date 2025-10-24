#include "hashmap.h"

#include <stdlib.h>

struct Hashmap *init_hashmap()
{
    struct Hashmap *map = malloc(sizeof(struct Hashmap));

    map->capacity = DEFAULT_CAPACITY;
    map->loadFactor = DEFAULT_LOAD_FACTOR;

    map->table = malloc(sizeof(struct Node*) * map->capacity);
    
    for(int i = 0; i < map->capacity; i++) {
        map->table[i] = NULL;
    }
    
    return map;
}

unsigned int hash(struct Hashmap *map, int key) {
    return (key * key + 1) % map->capacity;
}

struct Node* createNode(int key, int value) {
    struct Node *new = malloc(sizeof(struct Node));

    new->key = key;
    new->value = value;
    new->next = NULL;

    return new;
}

enum HashMapReturnValue put(struct Hashmap *map, int key, int value)
{
    unsigned int hash_key = hash(map, key);
    struct Node **current = &map->table[hash_key];
    while (*current != NULL) {
        if ((*current)->key == key) {
            (*current)->value = value;
            return SUCCESS;
        }
        current = &(*current)->next;
    }
    *current = createNode(key, value);
    return SUCCESS;
}

enum HashMapReturnValue get(struct Hashmap *map, int key, int *res)
{
    unsigned int hash_key = hash(map, key);

    struct Node *head = map->table[hash_key];

    while(head != NULL) {
        if(head->key == key) {
            if(res != NULL)
                *res = head->value;

            return SUCCESS;
        }
        head = head->next;
    }

    return KEY_UNKNOW;
}

enum HashMapReturnValue del(struct Hashmap *map, int key, int *res)
{
    unsigned int hash_key = hash(map, key);
    
    struct Node *before = NULL;
    struct Node *head = map->table[hash_key];

    while(head != NULL) {
        if(head->key == key) {
            if(res != NULL)
                *res = head->value;

            if(before == NULL)
                map->table[hash_key] = head->next;
            else
                before->next = head->next;
            return SUCCESS;
        }
        before = head;
        head = head->next;
    }

    return KEY_UNKNOW;
}

void free_node(struct Node *head) {
    if (head == NULL)
        return;
    
    free_node(head->next);
    free(head);
}

void free_hashmap(struct Hashmap *map)
{
    free_node(map->table[0]);
    free(map->table);
    free(map);
}