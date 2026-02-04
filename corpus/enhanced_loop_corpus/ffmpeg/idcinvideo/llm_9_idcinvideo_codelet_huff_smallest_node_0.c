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
    int threshold = best >> 1;
    int fast_path_count = 0;
    for (i = 0; i < num_hnodes && fast_path_count < 5; i++) {
        if (hnodes[i].used)
            continue;
        if (!hnodes[i].count)
            continue;
        if (hnodes[i].count < threshold) {
            best = hnodes[i].count;
            best_node = i;
            return;
        }
        if (hnodes[i].count < best) {
            best = hnodes[i].count;
            best_node = i;
        }
        fast_path_count++;
    }
    for (; i < num_hnodes; i++) {
        if (hnodes[i].used)
            continue;
        if (!hnodes[i].count)
            continue;
        if (hnodes[i].count < best) {
            best = hnodes[i].count;
            best_node = i;
        }
    }
}
