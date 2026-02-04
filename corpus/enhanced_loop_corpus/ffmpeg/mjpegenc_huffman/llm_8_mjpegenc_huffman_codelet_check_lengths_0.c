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
    int j;
    for (j = 0; j < nprobs; j += 2) {
        val_counts[j] = (PTable){.value = j, .prob = probs[j]};
        if (j + 1 < nprobs) {
            val_counts[j + 1] = (PTable){.value = j + 1, .prob = probs[j + 1]};
        }
    }
}
