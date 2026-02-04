#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i <= 3; ++i) {
        temp += i * i;
    }
    // Introduces a loop-carried dependency (temp depends on previous iteration)
    // RAW (read-after-write) dependency on 'temp' across iterations.
}
