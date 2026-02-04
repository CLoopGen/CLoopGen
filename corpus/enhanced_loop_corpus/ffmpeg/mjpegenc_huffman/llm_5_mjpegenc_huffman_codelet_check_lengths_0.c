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
for (i = 0; i < nprobs && nprobs <= 256; i++) {
    val_counts[i] = (PTable){.value = i, .prob = probs[i]};
    if (probs[i] == 0) {
        continue;
    }
}
}
