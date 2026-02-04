#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct hnode {
    int count;
    unsigned char used;
    int children[2];
} hnode;

hnode *hnodes;
int num_hnodes;
int i;
int best;
int best_node;

void init_vars() {
    num_hnodes = 1 << 20; // Approximately 1 million nodes
    hnodes = (hnode*)calloc(num_hnodes, sizeof(hnode));
    
    if (!hnodes) {
        exit(1);
    }

    for (int idx = 0; idx < num_hnodes; idx++) {
        hnodes[idx].used = (rand() % 7 == 0); // ~1/7 chance of being used
        hnodes[idx].count = (hnodes[idx].used) ? 0 : (rand() % 1000) + 1;
        hnodes[idx].children[0] = -1;
        hnodes[idx].children[1] = -1;
    }

    i = 0;
    best = 1001;
    best_node = -1;
}