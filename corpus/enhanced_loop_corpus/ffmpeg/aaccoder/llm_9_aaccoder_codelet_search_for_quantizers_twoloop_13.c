#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int minsf[128];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int n = sizeof(minsf) / sizeof(minsf[0]);
    for (i = 0; i < n; i += 2) {
        minsf[i] = 0;
        if (i + 1 < n)
            minsf[i + 1] = 0;
    }
}
