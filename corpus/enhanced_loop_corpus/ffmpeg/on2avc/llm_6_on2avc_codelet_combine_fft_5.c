#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tmp;
extern int half;
extern int len2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_copy = tmp;
    for (half = len2; temp_copy > 1; temp_copy >>= 1) {
        half = half << 1;
    }
}
