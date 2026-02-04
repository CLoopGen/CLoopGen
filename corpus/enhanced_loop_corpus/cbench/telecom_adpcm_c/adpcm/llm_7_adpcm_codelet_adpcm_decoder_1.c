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
    int local_step = step;
    int local_index = index;
    for (; len > 0; len--) {
        int local_delta, local_vpdiff, local_sign;
        if (bufferstep) {
            local_delta = inputbuffer & 15;
        } else {
            inputbuffer = *inp++;
            local_delta = (inputbuffer >> 4) & 15;
        }
        bufferstep = !bufferstep;
        local_index += indexTable[local_delta];
        if (local_index < 0)
            local_index = 0;
        if (local_index > 88)
            local_index = 88;
        local_sign = local_delta & 8;
        local_delta &= 7;
        local_vpdiff = local_step >> 3;
        if (local_delta & 4)
            local_vpdiff += local_step;
        if (local_delta & 2)
            local_vpdiff += local_step >> 1;
        if (local_delta & 1)
            local_vpdiff += local_step >> 2;
        if (local_sign)
            valpred -= local_vpdiff;
        else
            valpred += local_vpdiff;
        if (valpred > 32767)
            valpred = 32767;
        else if (valpred < -32768)
            valpred = -32768;
        local_step = stepsizeTable[local_index];
        *outp++ = valpred;
    }
    step = local_step;
    index = local_index;
}
