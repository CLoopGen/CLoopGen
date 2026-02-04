#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < h; i++) {
        temp += i;
    }
    // Introduce a WAW dependency on temp (though not loop-carried beyond final iteration)
    // Also introduces RAW dependency: i -> temp, and loop-carried dependency via temp
}
