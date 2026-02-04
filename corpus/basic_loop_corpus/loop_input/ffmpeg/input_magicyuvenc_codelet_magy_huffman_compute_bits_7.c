#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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

PTable *prob_table;
int size = 256;
int max_length = 10;
PackageMergerList *to;
PackageMergerList *from;
PackageMergerList *temp;
int times;
int i;
int j;
int k;

void init_vars() {
    prob_table = (PTable*)calloc(size, sizeof(PTable));
    for (int idx = 0; idx < size; idx++) {
        prob_table[idx].value = idx;
        prob_table[idx].prob = (int64_t)(idx + 1) * 100;
    }

    PackageMergerList *list1 = (PackageMergerList*)calloc(1, sizeof(PackageMergerList));
    PackageMergerList *list2 = (PackageMergerList*)calloc(1, sizeof(PackageMergerList));

    list1->nitems = 0;
    list1->item_idx[0] = 0;
    list2->nitems = 0;
    list2->item_idx[0] = 0;

    to = list1;
    from = list2;
}