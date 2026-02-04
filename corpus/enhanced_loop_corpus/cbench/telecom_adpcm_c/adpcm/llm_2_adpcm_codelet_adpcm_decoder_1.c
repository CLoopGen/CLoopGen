#include <stdio.h>

#include <inttypes.h>

extern int indexTable[16];
extern int stepsizeTable[89];
extern int len;
extern signed char *inp;
extern short *outp;
extern int sign;
extern int delta;
extern int step;
extern int valpred;
extern int vpdiff;
extern int _usr_index;
extern int inputbuffer;
extern int bufferstep;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 1: Consecutive memory access with unrolled stride-2 pattern
    // We process two iterations per loop cycle to enable consecutive reads from input and output arrays.
    // This improves cache locality and enables better vectorization potential.

    for (; len >= 2; len -= 2) {
        int delta0, delta1;
        int sign0, sign1;
        int vpdiff0, vpdiff1;
        int index_next;

        // First iteration
        if (bufferstep) {
            delta0 = inputbuffer & 15;
        } else {
            inputbuffer = *inp++;
            delta0 = (inputbuffer >> 4) & 15;
        }
        bufferstep = !bufferstep;
        index_next = index + indexTable[delta0];
        if (index_next < 0) index_next = 0;
        if (index_next > 88) index_next = 88;
        sign0 = delta0 & 8;
        delta0 &= 7;
        vpdiff0 = step >> 3;
        if (delta0 & 4) vpdiff0 += step;
        if (delta0 & 2) vpdiff0 += step >> 1;
        if (delta0 & 1) vpdiff0 += step >> 2;

        // Second iteration
        if (bufferstep) {
            delta1 = inputbuffer & 15;
        } else {
            inputbuffer = *inp++;
            delta1 = (inputbuffer >> 4) & 15;
        }
        bufferstep = !bufferstep;
        int index_final = index_next + indexTable[delta1];
        if (index_final < 0) index_final = 0;
        if (index_final > 88) index_final = 88;
        sign1 = delta1 & 8;
        delta1 &= 7;
        vpdiff1 = stepsizeTable[index_next] >> 3;
        if (delta1 & 4) vpdiff1 += stepsizeTable[index_next];
        if (delta1 & 2) vpdiff1 += stepsizeTable[index_next] >> 1;
        if (delta1 & 1) vpdiff1 += stepsizeTable[index_next] >> 2;

        // Update valpred for first sample
        int valpred0 = sign0 ? valpred - vpdiff0 : valpred + vpdiff0;
        if (valpred0 > 32767) valpred0 = 32767;
        else if (valpred0 < -32768) valpred0 = -32768;

        // Update valpred for second sample
        int valpred1 = sign1 ? valpred0 - vpdiff1 : valpred0 + vpdiff1;
        if (valpred1 > 32767) valpred1 = 32767;
        else if (valpred1 < -32768) valpred1 = -32768;

        // Write both outputs
        *outp++ = valpred0;
        *outp++ = valpred1;

        // Update shared state
        valpred = valpred1;
        index = index_final;
        step = stepsizeTable[index_final];
    }

    // Handle remaining element
    for (; len > 0; len--) {
        if (bufferstep) {
            delta = inputbuffer & 15;
        } else {
            inputbuffer = *inp++;
            delta = (inputbuffer >> 4) & 15;
        }
        bufferstep = !bufferstep;
        index += indexTable[delta];
        if (index < 0) index = 0;
        if (index > 88) index = 88;
        sign = delta & 8;
        delta &= 7;
        vpdiff = step >> 3;
        if (delta & 4) vpdiff += step;
        if (delta & 2) vpdiff += step >> 1;
        if (delta & 1) vpdiff += step >> 2;
        if (sign)
            valpred -= vpdiff;
        else
            valpred += vpdiff;
        if (valpred > 32767)
            valpred = 32767;
        else if (valpred < -32768)
            valpred = -32768;
        step = stepsizeTable[index];
        *outp++ = valpred;
    }
}
