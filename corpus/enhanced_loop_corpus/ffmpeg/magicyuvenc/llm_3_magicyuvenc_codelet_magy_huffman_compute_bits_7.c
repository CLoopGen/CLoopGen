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
    int indices[2048];
    int total_accesses = 0;
    while (i < size || j + 1 < from->nitems) {
        indices[total_accesses++] = i < size && (j + 1 >= from->nitems || prob_table[i].prob < from->probability[j] + from->probability[j + 1]) ? -1 : j;
        if (i < size && (j + 1 >= from->nitems || prob_table[i].prob < from->probability[j] + from->probability[j + 1])) {
            i++;
        } else {
            j += 2;
        }
    }
    for (int idx = 0; idx < total_accesses; idx++) {
        to->nitems++;
        to->item_idx[to->nitems] = to->item_idx[to->nitems - 1];
        if (indices[idx] == -1) {
            to->items[to->item_idx[to->nitems]++] = prob_table[i - 1].value;
            to->probability[to->nitems - 1] = prob_table[i - 1].prob;
        } else {
            int base_j = indices[idx];
            for (k = from->item_idx[base_j]; k < from->item_idx[base_j + 2]; k++) {
                to->items[to->item_idx[to->nitems]++] = from->items[k];
            }
            to->probability[to->nitems - 1] = from->probability[base_j] + from->probability[base_j + 1];
        }
    }
    temp = to;
    to = from;
    from = temp;
}
}
