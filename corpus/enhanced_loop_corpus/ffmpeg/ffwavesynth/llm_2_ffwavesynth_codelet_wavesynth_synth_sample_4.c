#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
enum ws_interval_type {
    WS_SINE = (('S') | (('I') << 8) | (('N') << 16) | ((unsigned int)('E') << 24)),
    WS_NOISE = (('N') | (('O') << 8) | (('I') << 16) | ((unsigned int)('S') << 24))
};


struct ws_interval {
    int64_t ts_start;
    int64_t ts_end;
    uint64_t phi0;
    uint64_t dphi0;
    uint64_t ddphi;
    uint64_t amp0;
    uint64_t damp;
    uint64_t phi;
    uint64_t dphi;
    uint64_t amp;
    uint32_t channels;
    enum ws_interval_type type;
    int next;
};


extern int32_t *channels;
extern int32_t *cv;
extern unsigned int val;
extern struct ws_interval *in;
extern uint32_t c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled stride of 2
    unsigned int temp_val = (unsigned int)val;
    for (c = in->channels, cv = channels; c; c >>= 2, cv += 2) {
        if (c & 1)
            *cv += temp_val;
        if (c & 2)
            *(cv + 1) += temp_val;
    }
}
