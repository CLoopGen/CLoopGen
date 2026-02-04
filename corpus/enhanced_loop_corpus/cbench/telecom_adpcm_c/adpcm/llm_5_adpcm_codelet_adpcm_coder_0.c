#include <stdio.h>

#include <inttypes.h>

extern int indexTable[16];
extern int stepsizeTable[89];
extern int len;
extern short *inp;
extern signed char *outp;
extern int val;
extern int sign;
extern int delta;
extern int diff;
extern int step;
extern int valpred;
extern int vpdiff;
extern int _usr_index;
extern int outputbuffer;
extern int bufferstep;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
for (; len > 0; len--) {
    val = *inp++;
    diff = val - valpred;
    sign = (diff < 0);
    // Eliminate conditional assignment and branch on sign early
    if (sign) {
        diff = -diff;
        sign = 8;
    } else {
        sign = 0;
    }

    // Flatten control flow: compute all conditions without early exits
    delta = 0;
    vpdiff = (step >> 3);

    // Unconditionally compute contribution from each bit of delta
    int temp_diff = diff;
    int temp_step = step;
    int temp_vpdiff = vpdiff;

    temp_step >>= 0; // align logic
    if (temp_diff >= temp_step) {
        delta |= 4;
        temp_diff -= temp_step;
        temp_vpdiff += temp_step;
    }
    temp_step >>= 1;
    if (temp_diff >= temp_step) {
        delta |= 2;
        temp_diff -= temp_step;
        temp_vpdiff += temp_step;
    }
    temp_step >>= 1;
    if (temp_diff >= temp_step) {
        delta |= 1;
        temp_vpdiff += temp_step;
    }

    // Apply prediction update based on sign without branching
    valpred = sign ? (valpred - temp_vpdiff) : (valpred + temp_vpdiff);

    // Clamp valpred using conditional expressions instead of ifs
    valpred = (valpred > 32767) ? 32767 : (valpred < -32768) ? -32768 : valpred;

    delta |= sign;
    index += indexTable[delta];
    index = (index < 0) ? 0 : (index > 88) ? 88 : index;
    step = stepsizeTable[index];

    // Handle output buffer logic without branching on bufferstep
    if (bufferstep) {
        outputbuffer = (delta << 4) & 240;
    } else {
        *outp++ = (delta & 15) | outputbuffer;
    }
    bufferstep = !bufferstep;
}
}
