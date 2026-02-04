#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *d;
extern int k;
extern word wt[40];
extern word scal;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    for (i = 0; i <= 1; i++)
        for (j = 0; j <= 39; j++)
            wt[j] = ((d[j]) >> (scal));
}
