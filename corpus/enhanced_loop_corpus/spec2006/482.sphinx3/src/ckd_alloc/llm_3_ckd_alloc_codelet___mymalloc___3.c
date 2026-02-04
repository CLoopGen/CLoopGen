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
    // Variant 2: Indirect access via pointer array simulation (assume blocky list structure stored indirectly)
    mylist_t *temp_list[256];  // Simulated bounded indirect access buffer
    int count = 0;
    mylist_t *it = head;

    // Build indirect reference array with limit
    while (it && count < 255) {
        temp_list[count++] = it;
        it = it->next;
    }
    temp_list[count] = NULL;

    prev = NULL;
    list = NULL;

    // Traverse through indirect array with reverse-like access pattern (to alter spatial locality)
    for (int i = 0; i < count && !list; ++i) {
        if (temp_list[i]->elemsize == elemsize) {
            list = temp_list[i];
        } else {
            prev = temp_list[i];
        }
    }
}
