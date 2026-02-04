#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern double *elist;
extern size_t *order;
extern size_t nint;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
size_t local_order[256]; 
double local_elist[256];
size_t cache_size = (nint < 256) ? nint : 256;
if (nint > 0) {
    for (size_t block = 0; block < nint; block += cache_size) {
        size_t block_end = (block + cache_size < nint) ? block + cache_size : nint;
        for (size_t k = block; k < block_end; k++) {
            local_order[k - block] = order[k];
            local_elist[k - block] = elist[order[k]];
        }
        for (size_t k = block; k < block_end; k++) {
            size_t i1 = local_order[k - block];
            double e1 = local_elist[k - block];
            size_t i_max_idx = k - block;
            for (size_t j = k + 1; j < block_end; j++) {
                size_t idx = j - block;
                if (local_elist[idx] > e1) {
                    e1 = local_elist[idx];
                    i_max_idx = idx;
                }
            }
            if (i_max_idx != (k - block)) {
                size_t temp = local_order[k - block];
                local_order[k - block] = local_order[i_max_idx];
                local_order[i_max_idx] = temp;
                local_elist[k - block] = elist[local_order[k - block]];
                local_elist[i_max_idx] = elist[local_order[i_max_idx]];
            }
            order[k] = local_order[k - block];
        }
    }
}
}
