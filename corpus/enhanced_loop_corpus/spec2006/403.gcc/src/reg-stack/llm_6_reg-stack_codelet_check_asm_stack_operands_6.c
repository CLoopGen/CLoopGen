#include <stdio.h>

#include <inttypes.h>

extern int i;
extern char reg_used_as_output[53];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 8; i <= (8 + 7); i++) {
        temp += reg_used_as_output[i];  // Introduce RAW dependency: temp depends on prior reads
        if (!reg_used_as_output[i]) {
            break;
        }
    }
    reg_used_as_output[8] = temp;  // Introduce WAW: write-after-write on reg_used_as_output[8]
}
