#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int x86_reg;

extern x86_reg i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8 * 8; i++) {
        i = i + (i % 2); // Introduces WAW dependency: write-after-write on 'i'
    }
}
