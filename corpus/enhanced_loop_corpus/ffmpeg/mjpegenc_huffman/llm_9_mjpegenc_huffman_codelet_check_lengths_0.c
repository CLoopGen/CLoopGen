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
    int k;
    for (k = 0; k < nprobs && k < 64; k++) {
        val_counts[k] = (PTable){
            .value = k * k, 
            .prob = probs[k] + probs[k] * 2
        };
    }
}
