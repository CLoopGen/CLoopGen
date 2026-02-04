#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern int i;
extern word ACF[9];
extern word K[9];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= 8; i++) {
        K[i] = (ACF[i-1] + ACF[i] + ACF[(i+1)%9]) / 3;
    }
}
