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
    word temp[11];
    for (k = 0; k <= 39; k++) {
        // Pre-load all required e[] values to eliminate repeated memory accesses
        // This introduces local data dependencies but removes redundant loads (reducing RAW hazards)
        temp[0] = e[k + 0]; temp[1] = e[k + 1]; temp[3] = e[k + 3];
        temp[4] = e[k + 4]; temp[5] = e[k + 5]; temp[6] = e[k + 6];
        temp[7] = e[k + 7]; temp[9] = e[k + 9]; temp[10] = e[k + 10];

        L_result = 8192 >> 1;
        L_result += (temp[0] * (longword)-134);
        L_result += (temp[1] * (longword)-374);
        L_result += (temp[3] * (longword)2054);
        L_result += (temp[4] * (longword)5741);
        L_result += (temp[5] * (longword)8192);
        L_result += (temp[6] * (longword)5741);
        L_result += (temp[7] * (longword)2054);
        L_result += (temp[9] * (longword)-374);
        L_result += (temp[10] * (longword)-134);
        L_result = ((L_result) >> (13));
        x[k] = (L_result < (-32768) ? -32768 : (L_result > 32767 ? 32767 : L_result));
    }
}
