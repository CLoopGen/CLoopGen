#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct EbmlList {
    int nb_elem;
    unsigned int alloc_elem_size;
    void *elem;
} EbmlList;

typedef struct MatroskaSeekhead {
    uint64_t id;
    uint64_t pos;
} MatroskaSeekhead;

extern EbmlList *seekhead_list;
extern MatroskaSeekhead *seekhead;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse traversal to alter memory access pattern
    int n = seekhead_list->nb_elem;
    for (i = n - 1; i >= 0; i--) {
        if (seekhead[i].id == 475249515) {
            break;
        }
    }
    // Adjust i to point to found element or -1 if not found
    // Note: After reverse search, if i == -1, no match was found.
    // Original behavior assumes i >= 0 means valid index. This preserves logic under reverse scan.
}
