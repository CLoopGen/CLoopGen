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
int local_step = step;  // Eliminate loop-carried dependence on shared 'step' initially
for (; len > 0; len--) {
    val = *inp++;
    diff = val - valpred;
    sign = (diff < 0) ? 8 : 0;
    if (sign)
        diff = (-diff);
    delta = 0;
    vpdiff = (local_step >> 3);
    if (diff >= local_step) {
        delta = 4;
        diff -= local_step;
        vpdiff += local_step;
    }
    local_step >>= 1;
    if (diff >= local_step) {
        delta |= 2;
        diff -= local_step;
        vpdiff += local_step;
    }
    local_step >>= 1;
    if (diff >= local_step) {
        delta |= 1;
        vpdiff += local_step;
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
    local_step = stepsizeTable[index];  // Update local copy only at end
    if (bufferstep) {
        outputbuffer = (delta << 4) & 240;
    } else {
        *outp++ = (delta & 15) | outputbuffer;
    }
    bufferstep = !bufferstep;
}
step = local_step;  // Write back final step value after loop (WAW introduced post-loop)
}
