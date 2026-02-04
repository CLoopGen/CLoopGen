#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; count > 0; count--) {
        int temp = count * count;
        temp += count / 2;
        temp -= count % 3;
        temp ^= 5;
        temp += (temp << 1);
        temp -= (temp >> 2);
        temp += 7;
        temp *= 2;
    }
}
