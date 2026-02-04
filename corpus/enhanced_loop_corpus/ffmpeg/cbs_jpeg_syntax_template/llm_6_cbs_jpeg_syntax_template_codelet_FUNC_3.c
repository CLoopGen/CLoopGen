#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < 16; i++) {
        temp += i * 2;
    }
    // Introduces a loop-carried dependency (temp depends on previous iteration)
    // RAW (Read-After-Write) dependency on 'temp' across iterations
}
