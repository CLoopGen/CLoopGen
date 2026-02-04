#include <stdio.h>

#include <inttypes.h>

extern int i;
extern char reg_used_as_output[53];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 8; i < (8 + 14) + 1; i++) {
        int temp = reg_used_as_output[i] & 1;
        temp ^= (i >> 2);
        if (!reg_used_as_output[i] && temp == 0) {
            break;
        }
    }
}
