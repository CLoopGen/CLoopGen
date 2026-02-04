#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef int int32;

typedef struct mylist_s {
    char **freelist;
    struct mylist_s *next;
    int32 elemsize;
    int32 blocksize;
    int32 blk_alloc;
} mylist_t;

mylist_t *head = NULL;
int32 elemsize = 42;
mylist_t *prev = NULL;
mylist_t *list = NULL;

#define LIST_SIZE 100000

static char **create_char_ptr_array() {
    char **arr = (char **)calloc(10, sizeof(char *));
    for (int i = 0; i < 10; i++) {
        arr[i] = (char *)calloc(16, sizeof(char));
        sprintf(arr[i], "str%d", i);
    }
    return arr;
}

void init_vars() {
    mylist_t *current = NULL;
    mylist_t *tail = NULL;

    for (int i = 0; i < LIST_SIZE; i++) {
        current = (mylist_t *)malloc(sizeof(mylist_t));
        current->freelist = create_char_ptr_array();
        current->elemsize = (i == LIST_SIZE - 1) ? elemsize : elemsize + 1;
        current->blocksize = 16;
        current->blk_alloc = 1;
        current->next = NULL;

        if (tail) {
            tail->next = current;
        } else {
            head = current;
        }
        tail = current;
    }

    prev = NULL;
    list = NULL;
}