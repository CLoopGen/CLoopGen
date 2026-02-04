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
    // Variant 2: Strided Memory Access with Indirect Indexing
    // Instead of direct indexing into indexTable and stepsizeTable,
    // use a strided access pattern via pointer arithmetic and indirect lookup tables.
    // Also, reorganize the control flow to minimize conditional updates using bit manipulations.

    // Define stride for indirect access (e.g., simulate aligned or padded table access)
    const int STRIDE = 2; // Simulate non-unit stride in table layout
    static const int* pIndexTable = &indexTable[0];
    static const int* pStepSizeTable = &stepsizeTable[0];

    for (; len > 0; len--) {
        if (bufferstep) {
            delta = inputbuffer & 15;
        } else {
            inputbuffer = *inp++;
            delta = (inputbuffer >> 4) & 15;
        }
        bufferstep = !bufferstep;

        // Use strided indirect access for indexTable
        index += *(pIndexTable + STRIDE * delta); // Strided access
        index = (index < 0) ? 0 : (index > 88) ? 88 : index;

        sign = delta & 8;
        delta &= 7;

        // Compute vpdiff using arithmetic instead of branching where possible
        vpdiff = step >> 3;
        vpdiff += (delta & 4) ? step : 0;
        vpdiff += (delta & 2) ? (step >> 1) : 0;
        vpdiff += (delta & 1) ? (step >> 2) : 0;

        valpred += (sign ? -vpdiff : vpdiff);

        // Clamp using arithmetic expressions
        valpred = (valpred > 32767) ? 32767 : (valpred < -32768) ? -32768 : valpred;

        // Strided access to step size table (simulating alternate memory layout)
        step = *(pStepSizeTable + STRIDE * index / STRIDE); // Still covers same range

        *outp++ = valpred;
    }
}
