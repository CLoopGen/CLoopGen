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
    int local_index = index;
    if (bufferstep) {
        delta = inputbuffer & 15;
    } else {
        inputbuffer = *inp++;
        delta = (inputbuffer >> 4) & 15;
    }
    bufferstep = !bufferstep;
    local_index += indexTable[delta];
    if (local_index < 0)
        local_index = 0;
    if (local_index > 88)
        local_index = 88;
    sign = delta & 8;
    delta = delta & 7;
    vpdiff = step >> 3;
    if (delta & 4)
        vpdiff += step;
    if (delta & 2)
        vpdiff += step >> 1;
    if (delta & 1)
        vpdiff += step >> 2;
    if (sign)
        valpred -= vpdiff;
    else
        valpred += vpdiff;
    if (valpred > 32767)
        valpred = 32767;
    else if (valpred < -32768)
        valpred = -32768;
    step = stepsizeTable[local_index];
    index = local_index;
    *outp++ = valpred;
}
}
