#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float vals[8];
extern int mask;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j, i;
for (j = 0; j < 2; j++) {
    for (i = 0; i < 4; i++) {
        if (vals[4 + i] > 0.F)
            mask |= (1 << (i << 3));
    }
}
}
