#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (; k < 16; ++k) {
        temp += k * k;
    }
    k = temp > 0 ? temp % 16 : k;
}
