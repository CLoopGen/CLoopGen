#include <stdio.h>

#include <inttypes.h>

extern int x;
extern int *iE;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (x = 0; x < 26; ++x) {
        temp += iE[x];
        iE[x] = 0;
    }
    // Introduced loop-carried dependency via 'temp' (WAW and RAW)
    // Each iteration depends on the previous update of 'temp'
}
