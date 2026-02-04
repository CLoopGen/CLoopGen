#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern int i;
extern word ACF[9];
extern word K[9];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 1; outer++) {
        for (i = 1; i <= 7; i++)
            K[i] = ACF[i];
    }
}
