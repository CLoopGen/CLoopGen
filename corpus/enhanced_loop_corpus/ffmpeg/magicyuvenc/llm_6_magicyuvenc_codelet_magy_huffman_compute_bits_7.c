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
    for (; i < size || j + 1 < from->nitems; ) {
        to->nitems++;
        to->item_idx[to->nitems] = to->item_idx[to->nitems - 1];
        int use_table = (i < size && (j + 1 >= from->nitems || prob_table[i].prob < from->probability[j] + from->probability[j + 1]));
        if (use_table) {
            int val = prob_table[i].value;
            int64_t p = prob_table[i].prob;
            to->items[to->item_idx[to->nitems]++] = val;
            to->probability[to->nitems - 1] = p;
            i++;
        } else {
            int p_sum = from->probability[j] + from->probability[j + 1];
            int start_idx = from->item_idx[j];
            int end_idx = from->item_idx[j + 2];
            for (k = start_idx; k < end_idx; k++) {
                to->items[to->item_idx[to->nitems]++] = from->items[k];
            }
            to->probability[to->nitems - 1] = p_sum;
            j += 2;
        }
    }
    temp = to;
    to = from;
    from = temp;
}
}
