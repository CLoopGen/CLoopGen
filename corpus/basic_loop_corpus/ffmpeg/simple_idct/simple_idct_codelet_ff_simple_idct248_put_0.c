#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int16_t *ptr;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 4; i++) {
    {
        int a0, a1;
        a0 = ptr[0];
        a1 = ptr[8 + 0];
        ptr[0] = a0 + a1;
        ptr[8 + 0] = a0 - a1;
    }
    ;
    {
        int a0, a1;
        a0 = ptr[1];
        a1 = ptr[8 + 1];
        ptr[1] = a0 + a1;
        ptr[8 + 1] = a0 - a1;
    }
    ;
    {
        int a0, a1;
        a0 = ptr[2];
        a1 = ptr[8 + 2];
        ptr[2] = a0 + a1;
        ptr[8 + 2] = a0 - a1;
    }
    ;
    {
        int a0, a1;
        a0 = ptr[3];
        a1 = ptr[8 + 3];
        ptr[3] = a0 + a1;
        ptr[8 + 3] = a0 - a1;
    }
    ;
    {
        int a0, a1;
        a0 = ptr[4];
        a1 = ptr[8 + 4];
        ptr[4] = a0 + a1;
        ptr[8 + 4] = a0 - a1;
    }
    ;
    {
        int a0, a1;
        a0 = ptr[5];
        a1 = ptr[8 + 5];
        ptr[5] = a0 + a1;
        ptr[8 + 5] = a0 - a1;
    }
    ;
    {
        int a0, a1;
        a0 = ptr[6];
        a1 = ptr[8 + 6];
        ptr[6] = a0 + a1;
        ptr[8 + 6] = a0 - a1;
    }
    ;
    {
        int a0, a1;
        a0 = ptr[7];
        a1 = ptr[8 + 7];
        ptr[7] = a0 + a1;
        ptr[8 + 7] = a0 - a1;
    }
    ;
    ptr += 2 * 8;
}

}
