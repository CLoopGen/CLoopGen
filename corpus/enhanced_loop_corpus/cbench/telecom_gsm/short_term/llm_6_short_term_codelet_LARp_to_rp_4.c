#include <stdio.h>

#include <inttypes.h>

typedef short word;

typedef long longword;

typedef unsigned long ulongword;

extern word *LARp;
extern int i;
extern word temp;
extern longword ltmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    word local_temp;
    longword local_ltmp;
    word *local_LARp = LARp;
    int local_i;

    for (local_i = 1; local_i <= 8; local_i++) {
        if (local_LARp[local_i - 1] < 0) {
            local_temp = local_LARp[local_i - 1] == ((-32767) - 1) ? (32767) : -(local_LARp[local_i - 1]);
            local_LARp[local_i - 1] = -((local_temp < 11059) ? local_temp << 1 : ((local_temp < 20070) ? local_temp + 11059 : ((ulongword)((local_ltmp = (longword)(local_temp >> 2) + (longword)(26112)) - ((-32767) - 1)) > (32767) - ((-32767) - 1) ? (local_ltmp > 0 ? (32767) : ((-32767) - 1)) : local_ltmp)));
        } else {
            local_temp = local_LARp[local_i - 1];
            local_LARp[local_i - 1] = (local_temp < 11059) ? local_temp << 1 : ((local_temp < 20070) ? local_temp + 11059 : ((ulongword)((local_ltmp = (longword)(local_temp >> 2) + (longword)(26112)) - ((-32767) - 1)) > (32767) - ((-32767) - 1) ? (local_ltmp > 0 ? (32767) : ((-32767) - 1)) : local_ltmp));
        }
    }
    LARp += 8; // Update original pointer after loop (WAW dependency introduced post-loop)
}
