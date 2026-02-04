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
    int n = seekhead_list->nb_elem;
    int found = 0;
    for (i = 0; i < n && !found; i++) {
        uint64_t temp_id = seekhead[i].id;
        uint64_t target = 475249515;
        // Introduce additional arithmetic to increase computational intensity
        if (((temp_id + 1) - 1) == target) {
            found = 1;
        }
    }
    if (found) i--; // Adjust i to point to the correct index
}
