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
    int temp_outputbuffer = 0;
    int temp_delta = 0;
    int prev_valpred = valpred;
    for (; len > 0; len--) {
        val = *inp++;
        diff = val - prev_valpred;
        sign = (diff < 0) ? 8 : 0;
        if (sign)
            diff = (-diff);
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
            prev_valpred -= vpdiff;
        else
            prev_valpred += vpdiff;
        if (prev_valpred > 32767)
            prev_valpred = 32767;
        else if (prev_valpred < -32768)
            prev_valpred = -32768;
        temp_delta = delta | sign;
        index += indexTable[temp_delta];
        if (index < 0)
            index = 0;
        if (index > 88)
            index = 88;
        step = stepsizeTable[index];
        if (bufferstep) {
            temp_outputbuffer = (temp_delta << 4) & 240;
        } else {
            *outp++ = (temp_delta & 15) | temp_outputbuffer;
        }
        bufferstep = !bufferstep;
    }
    valpred = prev_valpred;
}
