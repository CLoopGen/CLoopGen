#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t k1;
extern  size_t product_1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t local_accum = 0;
    for (k1 = 0; k1 < product_1; k1++) {
        local_accum = k1 * k1 + local_accum; // RAW dependency: local_accum read before write; loop-carried dependence via local_accum
    }
    k1 = local_accum; // WAR avoided by writing to k1 after loop; no intra-loop interference
}
