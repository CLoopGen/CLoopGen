#include <stdio.h>
#include <inttypes.h>

typedef int Int32;

Int32 *limit;
Int32 *base;
Int32 minLen;
Int32 maxLen;
Int32 i;

#define DATA_SIZE (64 << 20) / sizeof(Int32)

static Int32 limit_arr[DATA_SIZE];
static Int32 base_arr[DATA_SIZE];

void init_vars() {
    size_t idx;
    for (idx = 0; idx < DATA_SIZE; ++idx) {
        limit_arr[idx] = 1;
        base_arr[idx] = 1;
    }
    minLen = 1;
    maxLen = DATA_SIZE - 1;
    limit = limit_arr;
    base = base_arr;
    i = 0;
}