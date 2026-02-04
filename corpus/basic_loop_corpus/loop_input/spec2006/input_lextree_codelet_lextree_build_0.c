#include <stdio.h>
#include <inttypes.h>

typedef char int8;
typedef int8 s3cipid_t;
typedef int int32;

s3cipid_t *lc;
int32 n_lc;

static s3cipid_t data[1 << 20]; // 1MB of data (approx. 2^20 elements)

void init_vars() {
    size_t i;
    for (i = 0; i < (sizeof(data) / sizeof(data[0])) - 1; i++) {
        data[i] = (s3cipid_t)1; // positive values to continue loop
    }
    data[(sizeof(data) / sizeof(data[0])) - 1] = (s3cipid_t)-1; // terminate condition

    lc = data;
    n_lc = 0;
}