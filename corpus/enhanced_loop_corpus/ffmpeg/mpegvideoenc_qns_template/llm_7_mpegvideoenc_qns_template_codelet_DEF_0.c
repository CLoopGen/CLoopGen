#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int x86_reg;

extern x86_reg i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[64];
    for (i = 0; i < 8 * 8; i++) {
        temp[i] = i * 2;       // Introduces RAW dependency: each read of 'i' must happen before write to temp[i]
        if (i > 0) {
            temp[i] += temp[i-1]; // Loop-carried dependency: each iteration depends on previous iteration's result
        }
    }
}
