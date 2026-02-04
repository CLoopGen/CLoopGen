#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern int i;
extern word ACF[9];
extern word P[9];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 8; i += 3)
        for (int k = i; k < i + 3 && k <= 8; k++)
            P[k] = ACF[k];
}
