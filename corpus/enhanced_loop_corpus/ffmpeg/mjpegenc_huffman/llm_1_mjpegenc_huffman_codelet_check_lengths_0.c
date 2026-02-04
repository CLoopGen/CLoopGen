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
    if (nprobs > 0) {
        for (i = 0; i < nprobs; i += 2) {
            val_counts[i] = (PTable){.value = i, .prob = probs[i]};
            if (i + 1 < nprobs) {
                val_counts[i + 1] = (PTable){.value = i + 1, .prob = probs[i + 1]};
            }
        }
    }
}
