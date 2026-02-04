#include <stdio.h>

#include <inttypes.h>

extern int reg_set_luid[53];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 53 - 1; i >= 0; i--) {
    if (reg_set_luid[i] == 0)
        continue;
    reg_set_luid[i] = 0;
}
}
