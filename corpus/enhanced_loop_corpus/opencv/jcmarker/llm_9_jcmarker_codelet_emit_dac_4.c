#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char dc_in_use[16];
extern char ac_in_use[16];
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        length += dc_in_use[i] * 2 + ac_in_use[i] * 2 + dc_in_use[15 - i] + ac_in_use[15 - i];
    }
}
