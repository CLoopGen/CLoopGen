#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < n; i += 2) {
        temp = temp + i;
    }
    // Introduces a WAW and RAW dependency on 'temp' within the loop.
    // Loop-carried dependency via 'temp' across iterations.
}
