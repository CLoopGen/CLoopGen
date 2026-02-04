#include <stdio.h>

#include <inttypes.h>

extern int mark[7056];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 21; i < 21 * 3; i++)
    for (int k = 0; k < 5; k++)
        for (j = 21; j < 21 * 3; j++)
            mark[(4 * 21 * i + j + k)] = 0;
}
