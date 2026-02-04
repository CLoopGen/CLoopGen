#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern int i;
extern word ACF[9];
extern word P[9];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i <= 4; i++) {
    P[2*i] = ACF[2*i];
    if (2*i+1 <= 8)
        P[2*i+1] = ACF[2*i+1];
}
}
