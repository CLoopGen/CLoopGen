#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern int i;
extern word ACF[9];
extern word P[9];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 8; i >= 0; i--)
        P[i] = ACF[i] + (i < 8 ? P[i+1] - P[i+1] : 0);
}
