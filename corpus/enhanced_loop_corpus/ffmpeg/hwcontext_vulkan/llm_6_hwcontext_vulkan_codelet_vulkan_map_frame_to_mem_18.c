#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int planes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (int i = 0; i < planes; i++) {
        temp += i;
    }
    // Introduce a write-after-write (WAW) dependency on temp, but no loop-carried dependency beyond the final iteration.
    temp = temp * 2;
}
