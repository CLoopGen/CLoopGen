#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *sptr;
extern uint8_t *dptr;
extern int dx;
extern int dy;
extern int h;
extern int w;
extern int stride;
extern uint8_t *pfptr;
extern int i;
extern int j;
extern uint8_t *nsptr;
extern uint8_t *npfptr;
extern int diff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint8_t local_diff = 0;
for (i = dx + h; i > dx; i--) {
    nsptr = sptr + (i - 1) * stride + dy * 3; // Introduce offset in pointer calculation to modify data access pattern
    npfptr = pfptr + (i - 1) * stride + dy * 3;
    uint8_t temp_diff = 0;
    for (j = 0; j < w * 3; j++) {
        uint8_t val = nsptr[j];
        temp_diff |= npfptr[j] ^ val;
        dptr[j] = val;
    }
    local_diff |= temp_diff; // Accumulate per-row differences without loop-carried dependency on global diff
    dptr += w * 3;
}
diff |= local_diff; // Single write to shared diff after loop, reducing WAW and RAW hazards
}
