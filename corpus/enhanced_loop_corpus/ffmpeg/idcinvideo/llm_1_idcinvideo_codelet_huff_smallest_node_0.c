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



void loop(){
for (i = 0; i < num_hnodes && !hnodes[i].used && !hnodes[i].count; i++) {
}
if (i < num_hnodes) {
    best = hnodes[i].count;
    best_node = i;
    for (i = i + 1; i < num_hnodes; i++) {
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
}
