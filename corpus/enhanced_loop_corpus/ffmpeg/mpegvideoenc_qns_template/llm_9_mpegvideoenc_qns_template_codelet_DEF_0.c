#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int x86_reg;

extern x86_reg i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        for (x86_reg j = 0; j < 8; j++) {
            x86_reg product = i * j;
            product += product * 3;
        }
    }
}
