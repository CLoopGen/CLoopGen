#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct PTable {
    int value;
    int64_t prob;
} PTable;

typedef struct PackageMergerList {
    int nitems;
    int item_idx[515];
    int probability[514];
    int items[4112];
} PackageMergerList;

extern PTable *prob_table;
extern int size;
extern int max_length;
extern PackageMergerList *to;
extern PackageMergerList *from;
extern PackageMergerList *temp;
extern int times;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (times = 0; times <= max_length; times++) {
    to->nitems = 0;
    to->item_idx[0] = 0;
    j = 0;
    k = 0;
    if (times < max_length) {
        i = 0;
    }
    int local_i = i;
    int local_j = j;
    int next_nitems = 0;
    int item_write_ptr[4112];
    int item_write_count = 0;
    for (int idx = 0; local_i < size || local_j + 1 < from->nitems; idx++) {
        next_nitems++;
        to->item_idx[next_nitems] = to->item_idx[next_nitems - 1];
        int64_t current_prob;
        int items_start = to->item_idx[next_nitems];
        if (local_i < size && (local_j + 1 >= from->nitems || prob_table[local_i].prob < from->probability[local_j] + from->probability[local_j + 1])) {
            to->items[items_start] = prob_table[local_i].value;
            current_prob = prob_table[local_i].prob;
            to->item_idx[next_nitems]++;
            local_i++;
        } else {
            int src_start = from->item_idx[local_j];
            int src_end = from->item_idx[local_j + 2];
            for (int copy_idx = src_start; copy_idx < src_end; copy_idx++) {
                to->items[items_start + (copy_idx - src_start)] = from->items[copy_idx];
            }
            to->item_idx[next_nitems] += (src_end - src_start);
            current_prob = from->probability[local_j] + from->probability[local_j + 1];
            local_j += 2;
        }
        to->probability[next_nitems - 1] = current_prob;
    }
    to->nitems = next_nitems;
    i = local_i;
    j = local_j;
    temp = to;
    to = from;
    from = temp;
}
}
