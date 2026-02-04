#include <stdio.h>

#include <inttypes.h>

extern int dfa_p[7056];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i, j;
for (i = 0; i < 4 * 21; i++)
    for (j = 0; j < 4 * 21; j++)
        dfa_p[i * (4 * 21) + j] = 3;
}
