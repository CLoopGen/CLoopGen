#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int minsf[128];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < sizeof(minsf) / sizeof(minsf[0]); ++i)
        minsf[i] = (i * i) % 37;
}
