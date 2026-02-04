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
    PTable temp[256];
    for (i = 0; i < nprobs; i++) {
        temp[i] = (PTable){.value = i, .prob = probs[i]};
    }
    for (i = 0; i < nprobs; i++) {
        val_counts[i] = temp[i];
    }
}
