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
    for (i = 8; i <= 159; i++) {
        sl = *(++sp);
        longword temp_sl = (longword)sl;
        word *sp_base = sp - 8;
        L_ACF[0] += temp_sl * sp_base[0];
        L_ACF[1] += temp_sl * sp_base[1];
        L_ACF[2] += temp_sl * sp_base[2];
        L_ACF[3] += temp_sl * sp_base[3];
        L_ACF[4] += temp_sl * sp_base[4];
        L_ACF[5] += temp_sl * sp_base[5];
        L_ACF[6] += temp_sl * sp_base[6];
        L_ACF[7] += temp_sl * sp_base[7];
        L_ACF[8] += temp_sl * sp_base[8];
    }
}
