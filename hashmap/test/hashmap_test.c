#include <stdio.h>
#include <stdlib.h>         
#include <assert.h>

#include "hashmap.h"

#define ADD_TEST(list, func) append(list, func, #func)

typedef void(testFunction(struct hashmap *map));

struct List {
    struct Node *head;
};

struct Node {
    testFunction *f;
    char *name;
    struct Node *next;
};

void setup(struct List *list) {
    list->head = NULL;
}

void append(struct List *list, testFunction f, char *name) {
    struct Node *new = malloc(sizeof(struct Node));
    new->f = f;
    new->name = name;
    new->next = NULL;

    struct Node *tail = list->head;

    if(tail == NULL) {
        list->head = new;
        return;
    }

    while(tail->next != NULL) {
        tail = tail->next;
    }

    tail->next = new;
}

void _free(struct Node *node) {
    if(node == NULL)
        return;
    _free(node->next);
    free(node);
}

void free_list(struct List *list) {
    _free(list->head);
}

void _run_test(testFunction f) {
    struct hashmap *map = init_hashmap();

    f(map);

    free_hashmap(map);
}

void run_test(struct List *list) {
    struct Node *current = list->head;

    while(current != NULL) {
        printf("Running test: %s\n", current->name);
        _run_test(current->f);
        printf("Passed: %s\n", current->name);
        current = current->next;
    }
}

void put_a_key_value_then_get_the_value_by_giving_the_key(struct hashmap *map) {

    int key = 5;
    int value = 23;
    int res;

    assert(put(map, key, value) == 0);
    assert(get(map, key, &res) == 0);
    assert(res == value);
}

void put_a_key_bellow_zero_will_work(struct hashmap *map) {

    int key = - 5;
    int value = 23;
    int res;

    assert(put(map, key, value) == 0);
    assert(get(map, key, &res) == 0);
    assert(res == value);
}

void get_a_key_unknow_will_fail(struct hashmap *map) {

    int key = 0;
    int res = -1;

    assert(get(map, key, &res) == -2);
    assert(res == -1);

}

void put_a_key_then_del_give_the_value(struct hashmap *map) {

    int key = 0;
    int value = 0;
    int res = -1;

    put(map, key, value);

    assert(del(map, key, &res) == 0);
    assert(res == value);
    assert(get(map, key, NULL) == -2);

    free_hashmap(map);
}

int main() {
    printf("Welcome to the hashmap test\n");

    struct List tests;
    setup(&tests);

    ADD_TEST(&tests, put_a_key_value_then_get_the_value_by_giving_the_key);
    ADD_TEST(&tests, put_a_key_bellow_zero_will_work);
    ADD_TEST(&tests, get_a_key_unknow_will_fail);
    ADD_TEST(&tests, put_a_key_then_del_give_the_value);

    run_test(&tests);

    free_list(&tests);

    return 0;
}