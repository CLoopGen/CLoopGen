#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *out;
extern int i;
extern int stride;
extern int map;
extern int hi;
extern int lo;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced trip count with unrolled bit checks using lookup table concept
    const uint8_t mask_val[16][4] = {
        {lo, lo, lo, lo}, {hi, lo, lo, lo}, {lo, hi, lo, lo}, {hi, hi, lo, lo},
        {lo, lo, hi, lo}, {hi, lo, hi, lo}, {lo, hi, hi, lo}, {hi, hi, hi, lo},
        {lo, lo, lo, hi}, {hi, lo, lo, hi}, {lo, hi, lo, hi}, {hi, hi, lo, hi},
        {lo, lo, hi, hi}, {hi, lo, hi, hi}, {lo, hi, hi, hi}, {hi, hi, hi, hi}
    };
    
    for (i = 0; i < 2; i++) {
        int idx = map & 0xF;
        out[0] = mask_val[idx][0];
        out[1] = mask_val[idx][1];
        out[2] = mask_val[idx][2];
        out[3] = mask_val[idx][3];
        map >>= 4;
        out += stride;
        
        // Early termination if map becomes zero
        if (map == 0) break;
    }
}
