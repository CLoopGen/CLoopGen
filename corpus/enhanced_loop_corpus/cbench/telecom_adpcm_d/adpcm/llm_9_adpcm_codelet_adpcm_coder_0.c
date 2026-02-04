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
int local_step, local_valpred, local_index = index;
for (; len > 0; len--) {
    val = *inp++;
    diff = val - valpred;
    sign = (diff < 0);
    delta = 0;
    local_step = stepsizeTable[local_index];

    // Reduced branching with arithmetic masking
    int mask = -(int)sign;
    diff = (diff ^ mask) - mask;  // Absolute value without branch
    vpdiff = (local_step >> 3);

    // Combined conditional updates using arithmetic
    int cond1 = (diff >= local_step);
    delta = cond1 * 4;
    diff -= local_step & (-cond1);
    vpdiff += local_step & (-cond1);

    local_step >>= 1;
    int cond2 = (diff >= local_step);
    delta |= cond2 * 2;
    diff -= local_step & (-cond2);
    vpdiff += local_step & (-cond2);

    local_step >>= 1;
    int cond3 = (diff >= local_step);
    delta |= cond3 * 1;
    vpdiff += local_step & (-cond3);

    // Update prediction using sign mask
    vpdiff = (vpdiff ^ (-sign)) + sign; // Apply negative if sign=1
    local_valpred = valpred - vpdiff;
    valpred = (local_valpred > 32767) ? 32767 : (local_valpred < -32768) ? -32768 : local_valpred;

    delta |= sign * 8;
    local_index += indexTable[delta];
    local_index = (local_index < 0) ? 0 : (local_index > 88) ? 88 : local_index;

    if (bufferstep) {
        outputbuffer = (delta << 4) & 240;
    } else {
        *outp++ = (delta & 15) | outputbuffer;
    }
    bufferstep = !bufferstep;
}
index = local_index;
}
