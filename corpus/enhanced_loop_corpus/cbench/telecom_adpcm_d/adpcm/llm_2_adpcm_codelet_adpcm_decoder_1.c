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
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of conditionally reading high/low nibble based on bufferstep,
    // pre-load two consecutive input bytes and process both in one iteration (unrolled by 2).
    // This changes memory access to be more sequential and reduces branching.

    int remaining = len;
    while (remaining > 0) {
        // Process two samples per loop if possible
        if (remaining >= 2) {
            int inp0 = *inp++;
            int inp1 = *inp++;

            // First sample: upper nibble
            int delta0 = (inp0 >> 4) & 15;
            index += indexTable[delta0];
            index = (index < 0) ? 0 : (index > 88) ? 88 : index;
            int sign0 = delta0 & 8;
            delta0 &= 7;
            vpdiff = step >> 3;
            if (delta0 & 4) vpdiff += step;
            if (delta0 & 2) vpdiff += step >> 1;
            if (delta0 & 1) vpdiff += step >> 2;
            valpred = sign0 ? valpred - vpdiff : valpred + vpdiff;
            valpred = (valpred > 32767) ? 32767 : (valpred < -32768) ? -32768 : valpred;
            step = stepsizeTable[index];
            *outp++ = valpred;

            // Second sample: lower nibble
            int delta1 = inp0 & 15;
            index += indexTable[delta1];
            index = (index < 0) ? 0 : (index > 88) ? 88 : index;
            int sign1 = delta1 & 8;
            delta1 &= 7;
            vpdiff = step >> 3;
            if (delta1 & 4) vpdiff += step;
            if (delta1 & 2) vpdiff += step >> 1;
            if (delta1 & 1) vpdiff += step >> 2;
            valpred = sign1 ? valpred - vpdiff : valpred + vpdiff;
            valpred = (valpred > 32767) ? 32767 : (valpred < -32768) ? -32768 : valpred;
            step = stepsizeTable[index];
            *outp++ = valpred;

            remaining -= 2;
        } else {
            // Handle leftover single element
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
            valpred = sign ? valpred - vpdiff : valpred + vpdiff;
            if (valpred > 32767) valpred = 32767;
            else if (valpred < -32768) valpred = -32768;
            step = stepsizeTable[index];
            *outp++ = valpred;
            remaining--;
        }
    }
    len = 0; // Ensure loop is done
}
