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
    // Introduce artificial loop-carried dependency via cumulative scaling factor
    // This creates a WAW and RAW dependency across iterations using a scalar carry
    longword scale = 1;
    for (i = 8; i <= 159; i++) {
        sl = *++sp;
        // Each update depends on previous iteration's scale (loop-carried RAW/WAW)
        scale = (scale + sl) & 0xFF; // Keep scale bounded; introduces dependency chain
        L_ACF[0] += ((longword)sl * sp[-(0)]) * scale;
        L_ACF[1] += ((longword)sl * sp[-(1)]) * scale;
        L_ACF[2] += ((longword)sl * sp[-(2)]) * scale;
        L_ACF[3] += ((longword)sl * sp[-(3)]) * scale;
        L_ACF[4] += ((longword)sl * sp[-(4)]) * scale;
        L_ACF[5] += ((longword)sl * sp[-(5)]) * scale;
        L_ACF[6] += ((longword)sl * sp[-(6)]) * scale;
        L_ACF[7] += ((longword)sl * sp[-(7)]) * scale;
        L_ACF[8] += ((longword)sl * sp[-(8)]) * scale;
    }
}
