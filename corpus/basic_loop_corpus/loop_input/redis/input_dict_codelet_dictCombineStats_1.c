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

static unsigned long *from_clvector_data;
static unsigned long *into_clvector_data;
dictStats *from;
dictStats *into;

void init_vars() {
    from_clvector_data = (unsigned long *)calloc(50, sizeof(unsigned long));
    into_clvector_data = (unsigned long *)calloc(50, sizeof(unsigned long));
    
    for (int i = 0; i < 50; i++) {
        from_clvector_data[i] = i + 1;
        into_clvector_data[i] = (i % 7) * 2;
    }

    from = (dictStats *)malloc(sizeof(dictStats));
    into = (dictStats *)malloc(sizeof(dictStats));

    from->htidx = 0;
    from->buckets = 50;
    from->maxChainLen = 10;
    from->totalChainLen = 45;
    from->htSize = 100;
    from->htUsed = 50;
    from->clvector = from_clvector_data;

    into->htidx = 1;
    into->buckets = 50;
    into->maxChainLen = 8;
    into->totalChainLen = 38;
    into->htSize = 100;
    into->htUsed = 50;
    into->clvector = into_clvector_data;
}