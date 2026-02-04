#include <stdio.h>

#include <inttypes.h>

extern int dfa_p[7056];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i, j, k, l;
for (i = 0; i < 4; i++)
    for (j = 0; j < 21; j++)
        for (k = 0; k < 4; k++)
            for (l = 0; l < 21; l++)
                dfa_p[(((i * 21 + j) * 4 + k) * 21 + l)] = 3;
}
