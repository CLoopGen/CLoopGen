#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (x = 0; x < 8; x++) {
        temp += x;
    }
    x = temp;
}
