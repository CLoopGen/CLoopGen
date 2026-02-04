#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *d;
extern int k;
extern word wt[40];
extern word scal;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k <= 39; k += 2) {
        wt[k] = ((d[k]) >> (scal));
        if (k + 1 <= 39) {
            wt[k + 1] = ((d[k + 1]) >> (scal));
        }
    }
}
