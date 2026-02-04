#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int table[2500][2500];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
        for (int k = 0; k < 10; k++)
            table[i][j] += k;

}
