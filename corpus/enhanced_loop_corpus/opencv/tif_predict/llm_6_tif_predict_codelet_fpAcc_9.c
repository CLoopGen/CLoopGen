#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; count > 8; count -= 8) {
        int temp1 = count;
        int temp2 = temp1 + 1;
        int temp3 = temp2 + 1;
        int temp4 = temp3 + 1;
        int temp5 = temp4 + 1;
        int temp6 = temp5 + 1;
        int temp7 = temp6 + 1;
        int temp8 = temp7 + 1;

        count = temp8 - 7;
    }
}
