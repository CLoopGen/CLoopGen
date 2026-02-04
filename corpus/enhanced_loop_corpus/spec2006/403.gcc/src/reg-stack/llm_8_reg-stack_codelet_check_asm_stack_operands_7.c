#include <stdio.h>

#include <inttypes.h>

extern int i;
extern char reg_used_as_output[53];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = (8 + 7) + 1;
    for (; i < limit; i += 2) {
        if (reg_used_as_output[i] && (i % 3 != 0)) {
            break;
        }
    }
}
