#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coeffs;
extern uint8_t *dst;
extern int32_t stride;
extern uint8_t loop_cnt;
extern uint8_t *temp_dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t *c = coeffs;
    uint8_t *d = dst;
    uint8_t *td = temp_dst;
    int32_t s = stride;
    uint8_t iter;

    // Eliminate loop-carried pointer updates by unrolling two iterations manually
    for (iter = 7; iter--;) {
        // First "half" iteration — fully independent operations
        td[0] = (uint8_t)((c[0] + c[1]) & 0xFF);
        td[s] = (uint8_t)((c[2] + c[3]) & 0xFF);
        d[0] = (uint8_t)((c[4] ^ c[5]) & 0xFF);
        d[s] = (uint8_t)((c[6] ^ c[7]) & 0xFF);

        // Independent memory stores with no intra-loop dependency
        td[2*s] = (uint8_t)((c[8] + c[9]) & 0xFF);
        td[3*s] = (uint8_t)((c[10] + c[11]) & 0xFF);
        d[2*s] = (uint8_t)((c[12] ^ c[13]) & 0xFF);
        d[3*s] = (uint8_t)((c[14] ^ c[15]) & 0xFF);

        // Stride-based advancement — all updates batched at end
        c += 64;
        td += 4 * s;
        d += 4 * s;

        // Second "half" using same pattern — creates uniform access but removes per-step control
        td[0] = (uint8_t)((c[0] + c[1]) & 0xFF);
        td[s] = (uint8_t)((c[2] + c[3]) & 0xFF);
        d[0] = (uint8_t)((c[4] ^ c[5]) & 0xFF);
        d[s] = (uint8_t)((c[6] ^ c[7]) & 0xFF);

        td[2*s] = (uint8_t)((c[8] + c[9]) & 0xFF);
        td[3*s] = (uint8_t)((c[10] + c[11]) & 0xFF);
        d[2*s] = (uint8_t)((c[12] ^ c[13]) & 0xFF);
        d[3*s] = (uint8_t)((c[14] ^ c[15]) & 0xFF);

        c += 64;
        td += 4 * s;
        d += 4 * s;
    }

    // Update global pointers after full execution
    coeffs = c;
    dst = d;
    temp_dst = td;
}
