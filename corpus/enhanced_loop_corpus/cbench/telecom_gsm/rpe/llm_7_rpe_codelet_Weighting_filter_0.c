#include <stdio.h>

#include <inttypes.h>

typedef short word;

typedef long longword;

extern word *e;
extern word *x;
extern longword L_result;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Introduce loop-carried dependence by accumulating partial results across iterations
    // This creates a WAW and RAW dependency between consecutive iterations
    static longword carry = 0;
    for (k = 0; k <= 39; k++) {
        L_result = 8192 >> 1;
        L_result += (e[k + 0] * (longword)-134);
        L_result += (e[k + 1] * (longword)-374);
        L_result += (e[k + 3] * (longword)2054);
        L_result += (e[k + 4] * (longword)5741);
        L_result += (e[k + 5] * (longword)8192);
        L_result += (e[k + 6] * (longword)5741);
        L_result += (e[k + 7] * (longword)2054);
        L_result += (e[k + 9] * (longword)-374);
        L_result += (e[k + 10] * (longword)-134);

        // Add previous iteration's scaled result as carry-in (introduces loop-carried dependency)
        L_result += carry;

        // Update carry for next iteration: inject a portion of current result
        carry = (L_result >> 16) & 0xFFFF;

        L_result = ((L_result) >> (13));
        x[k] = (L_result < (-32768) ? -32768 : (L_result > 32767 ? 32767 : L_result));
    }
    // Note: carry persists between calls unless reset externally
}
