#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *d;
extern int k;
extern word wt[40];
extern word scal;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 1; k <= 39; k++)
        wt[k] = (d[k-1] >> scal);
    if (k == 40)
        wt[0] = (d[0] >> scal);
}
