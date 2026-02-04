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
    int speculative_index;
    int local_step;
    int unrolled_val;
    int unrolled_diff;
    for (; len >= 2; len -= 2) {
        // First iteration - reduce loop-carried dependency on 'valpred' by computing ahead
        unrolled_val = inp[0];
        unrolled_diff = unrolled_val - valpred;
        sign = (unrolled_diff < 0) ? 8 : 0;
        if (sign) unrolled_diff = -unrolled_diff;
        delta = 0;
        vpdiff = (step >> 3);
        if (unrolled_diff >= step) {
            delta = 4;
            unrolled_diff -= step;
            vpdiff += step;
        }
        local_step = step >> 1;
        if (unrolled_diff >= local_step) {
            delta |= 2;
            unrolled_diff -= local_step;
            vpdiff += local_step;
        }
        local_step >>= 1;
        if (unrolled_diff >= local_step) {
            delta |= 1;
            vpdiff += local_step;
        }
        delta |= sign;
        speculative_index = index + indexTable[delta];
        if (speculative_index < 0) speculative_index = 0;
        if (speculative_index > 88) speculative_index = 88;
        int next_step = stepsizeTable[speculative_index];

        // Update state for first sample
        if (sign)
            valpred -= vpdiff;
        else
            valpred += vpdiff;
        if (valpred > 32767) valpred = 32767;
        else if (valpred < -32768) valpred = -32768;
        int first_output = (delta & 15) | ((bufferstep ? 0 : outputbuffer));
        bufferstep ^= 1;
        if (bufferstep) outputbuffer = (delta << 4) & 240;

        // Second iteration using updated step and index, but avoid re-reading step from memory until commit
        unrolled_val = inp[1];
        unrolled_diff = unrolled_val - valpred;
        sign = (unrolled_diff < 0) ? 8 : 0;
        if (sign) unrolled_diff = -unrolled_diff;
        delta = 0;
        vpdiff = (next_step >> 3);
        if (unrolled_diff >= next_step) {
            delta = 4;
            unrolled_diff -= next_step;
            vpdiff += next_step;
        }
        local_step = next_step >> 1;
        if (unrolled_diff >= local_step) {
            delta |= 2;
            unrolled_diff -= local_step;
            vpdiff += local_step;
        }
        local_step >>= 1;
        if (unrolled_diff >= local_step) {
            delta |= 1;
            vpdiff += local_step;
        }
        delta |= sign;
        index = speculative_index; // commit index only after second use
        step = next_step; // commit step update
        if (sign)
            valpred -= vpdiff;
        else
            valpred += vpdiff;
        if (valpred > 32767) valpred = 32767;
        else if (valpred < -32768) valpred = -32768;
        if (!bufferstep)
            *outp++ = (delta & 15) | outputbuffer;
        bufferstep ^= 1;
        if (bufferstep)
            outputbuffer = (delta << 4) & 240;

        inp += 2;
        if (len == 1) break; // in case len was odd, prevent underflow
    }
    // Handle leftover element
    for (; len > 0; len--) {
        val = *inp++;
        diff = val - valpred;
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
