#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef int Int32;

Int32 *limit;
Int32 *base;
Int32 minLen;
Int32 maxLen;
Int32 i;
Int32 vec;

#define DATA_SIZE (64 << 20) / sizeof(Int32)

static Int32 limit_storage[DATA_SIZE];
static Int32 base_storage[DATA_SIZE];

void init_vars() {
    const Int32 min_possible = 0;
    const Int32 max_possible = DATA_SIZE - 2; 

    minLen = min_possible;
    maxLen = max_possible;

    base = base_storage;
    limit = limit_storage;

    vec = 1;

    for (Int32 idx = 0; idx < DATA_SIZE; idx++) {
        base[idx] = (Int32)(idx * 31);
        limit[idx] = 0;
    }
}