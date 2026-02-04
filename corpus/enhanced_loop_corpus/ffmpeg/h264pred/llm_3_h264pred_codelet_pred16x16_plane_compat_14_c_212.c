#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int k;
extern int stride;
extern  uint16_t * src0;
extern  uint16_t *src1;
extern  uint16_t *src2;
extern int H;
extern int V;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 2; k <= 8; ++k) {
    int idx = k;
    H += idx * (src0[idx] - src0[0]); // Consecutive access with fixed base at src0[0]
    V += idx * (src1[(idx-2)*stride] - src2[(idx-2)*stride]); // Strided access using increasing offsets
}
}
