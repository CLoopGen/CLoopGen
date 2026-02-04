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
for (k = 0; k <= 49; k++) {
    L_result = 8192 >> 1;
    L_result += (e[(k + 0) % 60] * (longword)-134);
    L_result += (e[(k + 1) % 60] * (longword)-374);
    L_result += (e[(k + 2) % 60] * (longword)1024);
    L_result += (e[(k + 3) % 60] * (longword)2054);
    L_result += (e[(k + 4) % 60] * (longword)5741);
    L_result += (e[(k + 5) % 60] * (longword)8192);
    L_result += (e[(k + 6) % 60] * (longword)5741);
    L_result += (e[(k + 7) % 60] * (longword)2054);
    L_result += (e[(k + 8) % 60] * (longword)1024);
    L_result += (e[(k + 9) % 60] * (longword)-374);
    L_result += (e[(k + 10) % 60] * (longword)-134);
    L_result = ((L_result) >> 13);
    x[k] = (L_result < -32768 ? -32768 : (L_result > 32767 ? 32767 : L_result));
}
}
