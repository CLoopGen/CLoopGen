#include <stdio.h>

#include <inttypes.h>

typedef long longword;

typedef short word;

extern longword *L_ACF;
extern int i;
extern word temp;
extern word ACF[9];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 8; i++) {
        if (i % 2 == 0) {
            ACF[i] = ((L_ACF[i] << temp) >> 16);
        } else {
            continue;
        }
    }
}
