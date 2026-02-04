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
int32 elemsize = 16;
mylist_t *prev = NULL;
mylist_t *list = NULL;

#define LIST_SIZE 100000

static char **create_freelist(int count) {
    char **fl = (char **)calloc(count, sizeof(char *));
    if (!fl) exit(1);
    for (int i = 0; i < count; ++i) {
        fl[i] = (char *)calloc(1, 16);
        if (!fl[i]) exit(1);
    }
    return fl;
}

void init_vars() {
    mylist_t *current = NULL;
    mylist_t *tail = NULL;

    for (int i = 0; i < LIST_SIZE; ++i) {
        current = (mylist_t *)calloc(1, sizeof(mylist_t));
        if (!current) exit(1);

        current->freelist = create_freelist(10);
        current->next = NULL;
        current->elemsize = (i == LIST_SIZE - 1) ? elemsize : elemsize + 1;
        current->blocksize = 10;
        current->blk_alloc = 1;

        if (tail) {
            tail->next = current;
        } else {
            head = current;
        }
        tail = current;
    }
}