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
// Reduced computational intensity: remove conditional bit checks and approximate vpdiff
for (; len > 0; len--) {
    if (bufferstep) {
        delta = inputbuffer & 15;
    } else {
        inputbuffer = *inp++;
        delta = (inputbuffer >> 4) & 15;
    }
    bufferstep = !bufferstep;
    index += indexTable[delta];
    index = (index < 0) ? 0 : (index > 88) ? 88 : index;

    // Simplify delta contribution using lookup or direct shift approximation
    sign = delta & 8;
    delta &= 7;
    // Approximate vpdiff with fewer operations: use only base + one term
    vpdiff = step >> 3;
    if (delta >= 4)  // Covers delta & 4 case, approximates higher impact
        vpdiff += step;

    valpred = sign ? (valpred - vpdiff) : (valpred + vpdiff);

    // Clamp using ternary to reduce branching
    valpred = (valpred > 32767) ? 32767 : (valpred < -32768) ? -32768 : valpred;

    step = stepsizeTable[index];
    *outp++ = valpred;
}
}
