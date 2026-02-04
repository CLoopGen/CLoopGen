#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *d;
extern int k;
extern word wt[40];
extern word scal;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i <= 39; i += 2) {
        wt[i] = ((d[i]) >> (scal));
        if (i + 1 <= 39)
            wt[i+1] = ((d[i+1]) >> (scal));
    }
}
