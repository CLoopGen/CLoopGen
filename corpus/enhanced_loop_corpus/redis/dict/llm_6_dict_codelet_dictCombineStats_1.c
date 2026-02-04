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
    unsigned long temp[50];
    for (int i = 0; i < 50; i++) {
        temp[i] = from->clvector[i];
    }
    for (int i = 0; i < 50; i++) {
        into->clvector[i] += temp[i];
    }
}
