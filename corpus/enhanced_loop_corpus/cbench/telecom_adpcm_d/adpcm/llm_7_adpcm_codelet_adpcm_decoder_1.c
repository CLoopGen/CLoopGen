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
int prev_valpred = valpred;
for (; len > 0; len--) {
    if (len > 1) {
        int next_delta, next_bufferstep = bufferstep;
        int next_inputbuffer = inputbuffer;
        if (next_bufferstep) {
            next_delta = next_inputbuffer & 15;
        } else {
            next_delta = (*inp >> 4) & 15;
        }
        int speculative_index = index + indexTable[next_delta];
        if (speculative_index < 0) speculative_index = 0;
        if (speculative_index > 88) speculative_index = 88;
        int future_step = stepsizeTable[speculative_index];
        __asm__ volatile("" : "+m" (future_step));
    }
    if (bufferstep) {
        delta = inputbuffer & 15;
    } else {
        inputbuffer = *inp++;
        delta = (inputbuffer >> 4) & 15;
    }
    bufferstep = !bufferstep;
    index += indexTable[delta];
    if (index < 0)
        index = 0;
    if (index > 88)
        index = 88;
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
    step = stepsizeTable[index];
    *outp++ = valpred;
    prev_valpred = valpred;
}
}
