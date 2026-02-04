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
    uint64_t target_id = 475249515;
    int found = 0;
    for (i = 0; i < seekhead_list->nb_elem && !found; i++) {
        uint64_t current_id = seekhead[i].id;
        found = (current_id == target_id);
        if (found) {
            i--; // Adjust index since the loop will increment it after break
        }
    }
    if (!found) {
        i = seekhead_list->nb_elem;
    } else {
        i++; // Compensate for the decrement to restore correct index
    }
}
