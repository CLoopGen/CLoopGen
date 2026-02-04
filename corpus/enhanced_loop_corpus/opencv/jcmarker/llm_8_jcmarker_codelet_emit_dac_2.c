#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char dc_in_use[16];
extern char ac_in_use[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < 16; i += 2) {
        dc_in_use[i] = ac_in_use[i] = 0;
        if (i + 1 < 16) {
            dc_in_use[i + 1] = ac_in_use[i + 1] = 0;
        }
    }
}
