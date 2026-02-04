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
    int limit = seekhead_list->nb_elem;
    for (i = 0; i < limit; i += 2) {
        if (i >= limit) break;
        if (seekhead[i].id == 475249515) {
            break;
        }
    }
}
