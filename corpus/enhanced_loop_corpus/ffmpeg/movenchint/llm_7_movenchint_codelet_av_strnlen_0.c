#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp;
    for (i = 0; i < len && s[i]; ) {
        temp = i;      // Read current value of i (RAW: read after write)
        i = temp + 1;  // Write to i based on temp — introduces explicit RAW within the loop body
        // Eliminates the increment in the for-loop header, moving it into the body
        // Creates a loop-carried dependence where each iteration depends on the previous via i
    }
}
