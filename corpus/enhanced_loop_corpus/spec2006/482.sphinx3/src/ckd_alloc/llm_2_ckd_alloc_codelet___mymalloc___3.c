#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef struct mylist_s {
    char **freelist;
    struct mylist_s *next;
    int32 elemsize;
    int32 blocksize;
    int32 blk_alloc;
} mylist_t;

extern mylist_t *head;
extern int32 elemsize;
extern mylist_t *prev;
extern mylist_t *list;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access pattern (simulate processing every other node)
    mylist_t *current = head;
    prev = NULL;

    for (; current && (current->elemsize != elemsize); current = (current->next ? current->next->next : NULL)) {
        if (current->next) {
            prev = current->next;
        }
    }

    list = current;
}
