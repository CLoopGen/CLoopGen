#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern unsigned char indices5[16];
extern unsigned char indices7[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; i += 2) {
        unsigned char index0, index1;
        index0 = indices7[i];
        index1 = indices7[i + 1];
        
        if (index0 == 0)
            indices5[i] = 1;
        else if (index0 == 1)
            indices5[i] = 0;
        else
            indices5[i] = 9 - index0;

        if (index1 == 0)
            indices5[i + 1] = 1;
        else if (index1 == 1)
            indices5[i + 1] = 0;
        else
            indices5[i + 1] = 9 - index1;
    }
}
