#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern int i;
extern word ACF[9];
extern word P[9];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i <= 8; i++) {
    P[i] = ACF[i] + ACF[i] - ACF[i];
}
}
