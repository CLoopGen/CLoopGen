#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct dictStats {
    int htidx;
    unsigned long buckets;
    unsigned long maxChainLen;
    unsigned long totalChainLen;
    unsigned long htSize;
    unsigned long htUsed;
    unsigned long *clvector;
} dictStats;

extern dictStats *from;
extern dictStats *into;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with added conditional computation to increase per-iteration cost
    for (int i = 0; i < 25; i++) {
        unsigned long temp_from_val_0 = from->clvector[i];
        unsigned long temp_from_val_1 = from->clvector[49 - i];

        into->clvector[i] += (temp_from_val_0 > 10) ? temp_from_val_0 * 3 : temp_from_val_0 * 2;
        into->clvector[49 - i] += (temp_from_val_1 > 10) ? temp_from_val_1 / 2 : temp_from_val_1;

        into->htUsed += (into->clvector[i] % 2 == 0) ? 1 : 0;
        into->buckets += (into->clvector[49 - i] % 2 == 0) ? 1 : 0;
    }
}
