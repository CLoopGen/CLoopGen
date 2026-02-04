#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct PTable {
    int value;
    int prob;
} PTable;

extern  int *probs;
extern int nprobs;
extern PTable val_counts[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    PTable prev = {0, 0};
    for (i = 0; i < nprobs; i++) {
        int adjusted_prob = probs[i] + prev.prob;
        val_counts[i] = (PTable){.value = i, .prob = adjusted_prob};
        prev = val_counts[i];
    }
}
