#include <stdio.h>

#include <inttypes.h>

typedef long longword;

typedef short word;

extern longword *L_ACF;
extern int i;
extern word *sp;
extern word sl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    longword temp[9] = {0}; // Local accumulation to break WAW and RAW dependencies
    word sl_val;
    for (i = 8; i <= 159; i++) {
        sl_val = *++sp;
        // Accumulate into local temporaries to eliminate write-after-write (WAW) and read-after-write (RAW)
        // on L_ACF, converting loop-carried dependencies into local reduction
        temp[0] += ((longword)sl_val * sp[-(0)]);
        temp[1] += ((longword)sl_val * sp[-(1)]);
        temp[2] += ((longword)sl_val * sp[-(2)]);
        temp[3] += ((longword)sl_val * sp[-(3)]);
        temp[4] += ((longword)sl_val * sp[-(4)]);
        temp[5] += ((longword)sl_val * sp[-(5)]);
        temp[6] += ((longword)sl_val * sp[-(6)]);
        temp[7] += ((longword)sl_val * sp[-(7)]);
        temp[8] += ((longword)sl_val * sp[-(8)]);
    }
    // Final update of global L_ACF without loop-carried dependency
    for (int j = 0; j <= 8; j++) {
        L_ACF[j] += temp[j];
    }
}
