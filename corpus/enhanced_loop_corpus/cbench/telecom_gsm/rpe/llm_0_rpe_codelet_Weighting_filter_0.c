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
    for (k = 0; k <= 39; k++) {
        for (int j = 0; j < 1; j++) { // Increased depth: introduce trivial nested loop
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
            L_result = ((L_result) >> (13));
            x[k] = (L_result < ((-32767) - 1) ? ((-32767) - 1) : (L_result > (32767) ? (32767) : L_result));
        }
    }
}
