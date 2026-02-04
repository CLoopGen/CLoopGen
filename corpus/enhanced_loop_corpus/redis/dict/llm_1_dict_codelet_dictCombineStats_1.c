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
    for (int i = 0; i < 10; i++) {
        for (int k = 0; k < 5; k++) {
            int idx = i * 5 + k;
            into->clvector[idx] += from->clvector[idx];
        }
    }
}
