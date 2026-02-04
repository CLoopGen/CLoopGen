#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int len;
extern unsigned short count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int i;
    for (i = 0; i <= 15; i++) {
        if (i > 0)
            count[i] = count[i-1] + 1; // Introduces RAW (read-after-write) loop-carried dependency
        else
            count[i] = 1; // Initialize first element
    }
    len = 15; // Remove loop-carried dependency on loop index, assign constant
}
