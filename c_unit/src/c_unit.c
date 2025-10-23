#include "c_unit.h"

#include "stdio.h"
#include "stdlib.h"

struct TestList *create_test_list()
{
    struct TestList *list = malloc(sizeof(struct TestList));

    list->head = NULL;

    return list;
}

struct TestNode *_create_test_node(testFunction f, char *testName) {
    struct TestNode *node = malloc(sizeof(struct TestNode));

    node->f = f;
    node->testName = testName;
    node->next = NULL;

    return node;
}

void append_test(struct TestList *list, testFunction f, char *testName){
    
    struct TestNode *new_node = _create_test_node(f, testName);

    struct TestNode *tail = list->head;

    if(tail == NULL) {
        list->head = new_node;
        return;
    }

    while(tail->next != NULL) {
        tail = tail->next;
    }

    tail->next = new_node;
}

void run(testFunction f, _beforeEach before, _afterEach after)
{
    void *params = before();

    f(params);

    after(params);
}

void run_tests(struct TestList *list, _beforeEach before, _afterEach after){

    struct TestNode *current = list->head;

    int c = 0;

    while(current != NULL) {
        printf("Running test #%i : %s\n", ++c, current->testName);
        run(current->f, before, after);
        printf("Passed: %s\n\n", current->testName);
        current = current->next;
    }

    printf("%i test succed\n", c);
}

void free_test_list(struct TestList *list){
    clear_tests(list);
    free(list);
}

void _free_test_nodes(struct TestNode *node) {
    if(node == NULL)
        return;
    _free_test_nodes(node->next);
    node->next = NULL;
    free(node);
}

void clear_tests(struct TestList *list){
    _free_test_nodes(list->head);
    list->head = NULL;
}
