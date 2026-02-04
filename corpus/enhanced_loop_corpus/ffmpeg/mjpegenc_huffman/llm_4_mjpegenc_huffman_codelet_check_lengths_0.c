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
for (i = 0; i < nprobs; i++) {
    if (probs[i] > 0) {
        val_counts[i] = (PTable){.value = i, .prob = probs[i]};
    }
}
}
