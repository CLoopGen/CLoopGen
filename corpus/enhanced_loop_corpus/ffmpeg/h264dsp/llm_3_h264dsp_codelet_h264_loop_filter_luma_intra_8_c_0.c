#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t xstride;
extern ptrdiff_t ystride;
extern int inner_iters;
extern int alpha;
extern int beta;
extern uint8_t *pix;
extern int d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const ptrdiff_t base_offset = -3 * xstride;
ptrdiff_t offsets[7];
for (int i = 0; i < 7; ++i) {
    offsets[i] = base_offset + i * xstride;
}
for (d = 0; d < 4 * inner_iters; d++) {
    const ptrdiff_t current_base = (char*)pix - (char*)NULL + d * ystride;
    const int p2 = *((uint8_t*)(current_base + offsets[0]));
    const int p1 = *((uint8_t*)(current_base + offsets[1]));
    const int p0 = *((uint8_t*)(current_base + offsets[2]));
    const int q0 = *((uint8_t*)(current_base + offsets[3]));
    const int q1 = *((uint8_t*)(current_base + offsets[4]));
    const int q2 = *((uint8_t*)(current_base + offsets[5]));
    if (((p0 - q0) >= 0 ? (p0 - q0) : (-(p0 - q0))) < alpha && ((p1 - p0) >= 0 ? (p1 - p0) : (-(p1 - p0))) < beta && ((q1 - q0) >= 0 ? (q1 - q0) : (-(q1 - q0))) < beta) {
        if (((p0 - q0) >= 0 ? (p0 - q0) : (-(p0 - q0))) < ((alpha >> 2) + 2)) {
            if (((p2 - p0) >= 0 ? (p2 - p0) : (-(p2 - p0))) < beta) {
                const int p3 = *((uint8_t*)(current_base + offsets[0] - xstride));
                *((uint8_t*)(current_base + offsets[2])) = (p2 + 2 * p1 + 2 * p0 + 2 * q0 + q1 + 4) >> 3;
                *((uint8_t*)(current_base + offsets[1])) = (p2 + p1 + p0 + q0 + 2) >> 2;
                *((uint8_t*)(current_base + offsets[0])) = (2 * p3 + 3 * p2 + p1 + p0 + q0 + 4) >> 3;
            } else {
                *((uint8_t*)(current_base + offsets[2])) = (2 * p1 + p0 + q1 + 2) >> 2;
            }
            if (((q2 - q0) >= 0 ? (q2 - q0) : (-(q2 - q0))) < beta) {
                const int q3 = *((uint8_t*)(current_base + offsets[5] + xstride));
                *((uint8_t*)(current_base + offsets[3])) = (p1 + 2 * p0 + 2 * q0 + 2 * q1 + q2 + 4) >> 3;
                *((uint8_t*)(current_base + offsets[4])) = (p0 + q0 + q1 + q2 + 2) >> 2;
                *((uint8_t*)(current_base + offsets[5])) = (2 * q3 + 3 * q2 + q1 + q0 + p0 + 4) >> 3;
            } else {
                *((uint8_t*)(current_base + offsets[3])) = (2 * q1 + q0 + p1 + 2) >> 2;
            }
        } else {
            *((uint8_t*)(current_base + offsets[2])) = (2 * p1 + p0 + q1 + 2) >> 2;
            *((uint8_t*)(current_base + offsets[3])) = (2 * q1 + q0 + p1 + 2) >> 2;
        }
    }
}
}
