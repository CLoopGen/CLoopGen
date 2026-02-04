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
    // Variant 2: Reduced computational intensity by simplifying bit manipulations
    // and combining conditional updates into fewer operations using lookup logic.
    // Also reduces effective work per iteration by skipping every other sample (downsampling effect).
    for (; len > 0; len -= 2) {  // Process only every other element, halving effective workload
        if (len <= 0) break;

        if (bufferstep) {
            delta = inputbuffer & 15;
        } else {
            inputbuffer = *inp++;
            delta = (inputbuffer >> 4) & 15;
        }
        bufferstep = !bufferstep;

        // Clamp index using min/max logic via ternary to reduce branch misprediction
        index = (index + indexTable[delta]);
        index = (index < 0) ? 0 : (index > 88) ? 88 : index;

        // Extract sign and magnitude in one go
        sign = delta & 8;
        delta &= 7;

        // Replace cascaded ifs with a precomputed shift-and-add pattern (conceptually fused)
        vpdiff = step >> 3;
        vpdiff += (delta & 4) ? step : 0;
        vpdiff += (delta & 2) ? (step >> 1) : 0;
        vpdiff += (delta & 1) ? (step >> 2) : 0;

        valpred += (sign) ? -vpdiff : vpdiff;

        // Saturate using conditional assignments instead of multiple ifs
        valpred = (valpred > 32767) ? 32767 : (valpred < -32768) ? -32768 : valpred;

        step = stepsizeTable[index];
        *outp++ = valpred;

        // Skip next sample processing (simulates lower intensity or subsampling mode)
        // Only process half the samples
        if (len > 1) {
            // Simulate consuming next input without updating output
            if (bufferstep) {
                inputbuffer = *inp++;
            }
            bufferstep = !bufferstep;
            len--; // Account for skipped sample
        }
    }
}
