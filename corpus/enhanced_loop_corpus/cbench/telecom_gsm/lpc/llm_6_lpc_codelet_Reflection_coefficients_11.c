#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern int i;
extern word ACF[9];
extern word P[9];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    word temp[9];
    for (i = 0; i <= 8; i++)
        temp[i] = ACF[i];
    for (i = 0; i <= 8; i++)
        P[i] = temp[i];
}
