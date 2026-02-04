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
        sl = *++sp;
        for (int j = 0; j <= 8; j++) {
            L_ACF[j] += ((longword)sl * sp[-j]);
        }
    }
}
