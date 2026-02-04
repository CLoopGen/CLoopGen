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
for (; len > 0; len--) {
    if (!bufferstep) {
        inputbuffer = *inp++;
        delta = (inputbuffer >> 4) & 15;
    } else {
        delta = inputbuffer & 15;
    }
    bufferstep = !bufferstep;

    index += indexTable[delta];

    // Eliminate conditional clamping using arithmetic (no early exits or branching for bounds)
    index = (index < 0) ? 0 : index;
    index = (index > 88) ? 88 : index;

    sign = delta & 8;
    delta &= 7;
    vpdiff = step >> 3;
    vpdiff += (delta & 4) ? step : 0;
    vpdiff += (delta & 2) ? (step >> 1) : 0;
    vpdiff += (delta & 1) ? (step >> 2) : 0;

    valpred += (sign) ? -vpdiff : vpdiff;

    valpred = (valpred > 32767) ? 32767 : (valpred < -32768) ? -32768 : valpred;

    step = stepsizeTable[index];
    *outp++ = valpred;
}
}
