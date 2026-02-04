#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct hnode {
    int count;
    unsigned char used;
    int children[2];
} hnode;

extern hnode *hnodes;
extern int num_hnodes;
extern int i;
extern int best;
extern int best_node;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int local_best = best;
    int local_best_node = best_node;
    int step = 2;
    for (i = 0; i < num_hnodes - (num_hnodes % step); i += step) {
        if (hnodes[i].used || !hnodes[i].count) continue;
        if (hnodes[i].count < local_best) {
            local_best = hnodes[i].count;
            local_best_node = i;
        }
        int j = i + 1;
        if (j < num_hnodes && !hnodes[j].used && hnodes[j].count && hnodes[j].count < local_best) {
            local_best = hnodes[j].count;
            local_best_node = j;
        }
    }
    // Handle odd-sized tail if needed
    for (; i < num_hnodes; i++) {
        if (hnodes[i].used)
            continue;
        if (!hnodes[i].count)
            continue;
        if (hnodes[i].count < local_best) {
            local_best = hnodes[i].count;
            local_best_node = i;
        }
    }
    best = local_best;
    best_node = local_best_node;
}
