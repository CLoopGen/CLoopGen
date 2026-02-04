#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t stride;
extern tmsize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tmsize_t temp = 0;
    for (i = stride - 4; i > 0; i--) {
        temp += i * stride;
    }
    // Introduces RAW dependency: 'temp' is read and written in each iteration.
    // Loop-carried dependency on 'temp' creates a sequential data flow.
}
