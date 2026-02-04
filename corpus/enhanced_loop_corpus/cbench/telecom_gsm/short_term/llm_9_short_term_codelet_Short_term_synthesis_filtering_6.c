#include <stdio.h>

#include <inttypes.h>

typedef short word;

typedef long longword;

typedef unsigned long ulongword;

extern word *rrp;
extern word *v;
extern int i;
extern word sri;
extern word tmp1;
extern word tmp2;
extern longword ltmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 4; i--;) {
    tmp1 = rrp[i];
    tmp2 = v[i];
    longword product1 = (longword)tmp1 * (longword)tmp2;
    longword rounded1 = (product1 + 16384) >> 15;
    tmp2 = (tmp1 == ((-32767) - 1) && tmp2 == ((-32767) - 1)) ? 32767 : (65535 & rounded1);

    longword diff = (longword)sri - (longword)tmp2;
    sri = (diff >= 32767) ? 32767 : (diff <= (-32767-1)) ? (-32767-1) : diff;

    longword product2 = (longword)tmp1 * (longword)sri;
    longword rounded2 = (product2 + 16384) >> 15;
    tmp1 = (tmp1 == ((-32767) - 1) && sri == ((-32767) - 1)) ? 32767 : (65535 & rounded2);

    longword sum = (longword)v[i] + (longword)tmp1;
    ulongword range_check = (ulongword)(sum - (-32767-1));
    v[i + 1] = (range_check > (32767 - (-32767-1))) ? (sum > 0 ? 32767 : (-32767-1)) : sum;
    
    // Additional computation to increase arithmetic intensity
    v[i] = (word)((((longword)v[i] * 3 + 1) >> 1) & 65535);
    sri = (word)((((longword)sri + v[i] + tmp1) >> 1) & 65535);
}
}
