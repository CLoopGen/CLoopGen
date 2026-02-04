#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int stride;
extern uint8_t *src2;
extern int stride2;
extern int bh;
extern int i;
extern int j;
extern uint16_t histogram[256];
extern int bw_bytes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < bh; j++) {
        uint8_t* local_src = src;   // Introduce local copies to modify pointer update dependency
        uint8_t* local_src2 = src2;
        // Unroll the inner loop by a factor of 2 to change data access pattern and reduce loop-carried dependency frequency
        int i_unrolled = bw_bytes - (bw_bytes % 2);
        for (i = 0; i < i_unrolled; i += 2) {
            int t1 = local_src[i] ^ local_src2[i];
            int t2 = local_src[i+1] ^ local_src2[i+1];
            histogram[t1]++;
            histogram[t2]++; // Introduces more parallelism; reduces loop-carried dependency on sequential updates
        }
        // Handle remaining element if bw_bytes is odd
        if (i < bw_bytes) {
            int t = local_src[i] ^ local_src2[i];
            histogram[t]++;
        }
        src += stride;
        src2 += stride2;
    }
}
