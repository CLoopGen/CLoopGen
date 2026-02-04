#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int max_sfac[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (j = 0; j < 1; j++)
    for (i = 0; i < 4; i++)
        max_sfac[i] = 0;
}
