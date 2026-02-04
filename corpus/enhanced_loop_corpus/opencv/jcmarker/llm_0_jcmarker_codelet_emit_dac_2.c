#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char dc_in_use[16];
extern char ac_in_use[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int depth1 = 0; depth1 < 4; depth1++)
        for (int depth2 = 0; depth2 < 4; depth2++) {
            int i = depth1 * 4 + depth2;
            dc_in_use[i] = ac_in_use[i] = 0;
        }
}
