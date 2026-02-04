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
    sign = (diff < 0) ? 8 : 0;
    if (sign) {
        diff = (-diff);
    } else {
        // Introduce alternate path: when non-negative, skip further processing for this iteration
        if (diff == 0) {
            bufferstep = !bufferstep;
            continue;
        }
    }
    delta = 0;
    vpdiff = (step >> 3);
    if (diff >= step) {
        delta = 4;
        diff -= step;
        vpdiff += step;
    }
    step >>= 1;
    if (diff >= step) {
        delta |= 2;
        diff -= step;
        vpdiff += step;
    }
    step >>= 1;
    if (diff >= step) {
        delta |= 1;
        vpdiff += step;
    }
    if (sign)
        valpred -= vpdiff;
    else
        valpred += vpdiff;
    if (valpred > 32767)
        valpred = 32767;
    else if (valpred < -32768)
        valpred = -32768;
    delta |= sign;
    index += indexTable[delta];
    if (index < 0)
        index = 0;
    if (index > 88)
        index = 88;
    step = stepsizeTable[index];
    if (bufferstep) {
        outputbuffer = (delta << 4) & 240;
    } else {
        *outp++ = (delta & 15) | outputbuffer;
    }
    bufferstep = !bufferstep;
}
}
