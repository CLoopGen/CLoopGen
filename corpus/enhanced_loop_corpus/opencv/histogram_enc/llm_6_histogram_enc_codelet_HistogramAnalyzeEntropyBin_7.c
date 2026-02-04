#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int histo_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < histo_size; ++i) {
        temp += i;
    }
    // Introduces a WAW and RAW dependency on 'temp' within the loop.
    // Loop-carried dependency via 'temp' across iterations.
}
