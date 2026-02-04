#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *d;
extern int k;
extern word wt[40];
extern word scal;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    word temp;
    for (k = 0; k <= 39; k++) {
        temp = d[k] >> scal;
        wt[k] = temp;
    }
}
