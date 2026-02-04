#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t nsym;
extern uint16_t *freqs;
extern uint16_t *freqs1;
extern uint16_t *cnts;
extern uint8_t *dectab;
extern uint32_t a;
extern uint32_t b;
extern uint32_t c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Use indirect access via index remapping (reverse order traversal)
for (int d_idx = 0; d_idx < nsym; d_idx++) {
    int d = nsym - 1 - d_idx;  // reverse index mapping

    freqs[d] = b;
    freqs1[d] = a;
    cnts[d] = c;

    int q_start = (a + 128 - 1) >> 7;
    int q_end = (a + b - 1) >> 7 + 1;

    for (int q = q_start; q < q_end; q++) {
        dectab[q] = d;
    }

    a += b;
}
}
