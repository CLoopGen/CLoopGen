#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < 16; i += 2) {
        temp += i * i + 3 * i - 5;
        temp %= 1000;
    }
}
