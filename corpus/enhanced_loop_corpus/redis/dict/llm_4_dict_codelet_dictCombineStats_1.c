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
    for (int i = 0; i < 50; i++) {
        if (from->clvector[i] > 0) {
            into->clvector[i] += from->clvector[i];
        }
    }
}
