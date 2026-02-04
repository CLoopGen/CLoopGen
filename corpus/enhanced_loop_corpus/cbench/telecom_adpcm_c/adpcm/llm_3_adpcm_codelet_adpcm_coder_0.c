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
int *in_ptr = (int*)inp;
short local_valpred = valpred;
int local_index = index;
int local_step = step;
int local_bufferstep = bufferstep;
int local_outputbuffer = outputbuffer;

for (; len > 0; len -= 2) {
    int v0, v1;
    int diff0, diff1;
    int sign0, sign1;
    int delta0, delta1;
    int vpdiff0, vpdiff1;

    v0 = in_ptr[0]; v1 = in_ptr[1]; in_ptr += 2;

    diff0 = v0 - local_valpred; sign0 = (diff0 < 0) ? 8 : 0; if (sign0) diff0 = -diff0;
    diff1 = v1 - local_valpred; sign1 = (diff1 < 0) ? 8 : 0; if (sign1) diff1 = -diff1;

    delta0 = delta1 = 0;
    vpdiff0 = (local_step >> 3);
    vpdiff1 = (local_step >> 3);

    if (diff0 >= local_step) { delta0 = 4; diff0 -= local_step; vpdiff0 += local_step; }
    if (diff1 >= local_step) { delta1 = 4; diff1 -= local_step; vpdiff1 += local_step; }

    local_step >>= 1;

    if (diff0 >= local_step) { delta0 |= 2; diff0 -= local_step; vpdiff0 += local_step; }
    if (diff1 >= local_step) { delta1 |= 2; diff1 -= local_step; vpdiff1 += local_step; }

    local_step >>= 1;

    if (diff0 >= local_step) { delta0 |= 1; vpdiff0 += local_step; }
    if (diff1 >= local_step) { delta1 |= 1; vpdiff1 += local_step; }

    if (sign0) local_valpred -= vpdiff0; else local_valpred += vpdiff0;
    if (sign1) local_valpred -= vpdiff1; else local_valpred += vpdiff1;

    if (local_valpred > 32767) local_valpred = 32767;
    else if (local_valpred < -32768) local_valpred = -32768;

    delta0 |= sign0;
    delta1 |= sign1;

    local_index += indexTable[delta0];
    local_index += indexTable[delta1];
    if (local_index < 0) local_index = 0;
    if (local_index > 88) local_index = 88;

    local_step = stepsizeTable[local_index];

    if (local_bufferstep) {
        local_outputbuffer = (delta0 << 4) & 240;
        *outp++ = (delta1 & 15) | local_outputbuffer;
        local_bufferstep = 0;
    } else {
        local_outputbuffer = (delta1 << 4) & 240;
        *outp++ = (delta0 & 15) | local_outputbuffer;
        local_bufferstep = 1;
    }
}

valpred = local_valpred;
index = local_index;
step = local_step;
bufferstep = local_bufferstep;
outputbuffer = local_outputbuffer;
inp = (short*)in_ptr;
}
