#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int n;
extern int32_t *smp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = smp[0];
    for (i = 1; i < n; i++) {
        if (smp[i] != temp) {
            temp = smp[i];  // Introduce WAW dependency: temp is written based on prior write
            break;
        }
        // RAW dependency: smp[i] read after smp[0] read; loop-carried dependency via temp
    }
}
