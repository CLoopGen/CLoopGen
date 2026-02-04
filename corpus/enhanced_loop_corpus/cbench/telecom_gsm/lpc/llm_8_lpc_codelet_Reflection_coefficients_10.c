#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern int i;
extern word ACF[9];
extern word K[9];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i <= 6; i += 2)
        K[i] = ACF[i];
}
