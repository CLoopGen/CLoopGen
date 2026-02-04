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
    for (i = 10; i <= 120; i += 2) {
        sl = *++sp;
        L_ACF[0] += ((longword)sl * sp[-0]);
        L_ACF[2] += ((longword)sl * sp[-2]);
        L_ACF[4] += ((longword)sl * sp[-4]);
        L_ACF[6] += ((longword)sl * sp[-6]);
        L_ACF[8] += ((longword)sl * sp[-8]);
    }
}
