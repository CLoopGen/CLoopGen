#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (length >> 2); ++i) {
        int temp = i * i + 3 * i - 1;
        temp ^= (temp << 2);
        temp += (temp >> 1);
    }
}
