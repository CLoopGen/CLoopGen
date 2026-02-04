#include <stdint.h>

typedef int32_t int32;

int32 i;
int32 n_feat;
int32 *veclen;
int32 blk;

void init_vars() {
    n_feat = 1 << 20;  // 1 million elements, ~4MB of data

    veclen = (int32*)__builtin_malloc(n_feat * sizeof(int32));
    
    for (int j = 0; j < n_feat; j++) {
        veclen[j] = 1;  // simple non-zero values to ensure meaningful accumulation
    }
}