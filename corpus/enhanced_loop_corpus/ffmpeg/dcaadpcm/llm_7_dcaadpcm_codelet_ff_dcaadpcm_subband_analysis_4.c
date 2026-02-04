#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern int *diff;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (len > 0) {
        diff[0] <<= 7;
        for (i = 1; i < len; i++) {
            diff[i] = (diff[i-1] + diff[i]) << 7;
        }
    }
}
