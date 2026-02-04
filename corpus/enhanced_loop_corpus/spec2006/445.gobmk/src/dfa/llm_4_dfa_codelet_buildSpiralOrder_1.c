#include <stdio.h>

#include <inttypes.h>

extern int mark[7056];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 21; i < 21 * 3; i++)
    for (j = 21; j < 21 * 3; j++)
        if ((i + j) % 2 == 0)
            mark[(4 * 21 * (i) + (j))] = 0;
}
