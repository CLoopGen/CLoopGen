#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int temp[64];
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    int offset = i;
    {
        int a, b;
        a = temp[offset + 8 * 0];
        b = temp[offset + 8 * 1];
        temp[offset + 8 * 0] = a + b;
        temp[offset + 8 * 1] = a - b;
    }
    ;
    {
        int a, b;
        a = temp[offset + 8 * 2];
        b = temp[offset + 8 * 3];
        temp[offset + 8 * 2] = a + b;
        temp[offset + 8 * 3] = a - b;
    }
    ;
    {
        int a, b;
        a = temp[offset + 8 * 4];
        b = temp[offset + 8 * 5];
        temp[offset + 8 * 4] = a + b;
        temp[offset + 8 * 5] = a - b;
    }
    ;
    {
        int a, b;
        a = temp[offset + 8 * 6];
        b = temp[offset + 8 * 7];
        temp[offset + 8 * 6] = a + b;
        temp[offset + 8 * 7] = a - b;
    }
    ;
    {
        int a, b;
        a = temp[offset + 8 * 0];
        b = temp[offset + 8 * 2];
        temp[offset + 8 * 0] = a + b;
        temp[offset + 8 * 2] = a - b;
    }
    ;
    {
        int a, b;
        a = temp[offset + 8 * 1];
        b = temp[offset + 8 * 3];
        temp[offset + 8 * 1] = a + b;
        temp[offset + 8 * 3] = a - b;
    }
    ;
    {
        int a, b;
        a = temp[offset + 8 * 4];
        b = temp[offset + 8 * 6];
        temp[offset + 8 * 4] = a + b;
        temp[offset + 8 * 6] = a - b;
    }
    ;
    {
        int a, b;
        a = temp[offset + 8 * 5];
        b = temp[offset + 8 * 7];
        temp[offset + 8 * 5] = a + b;
        temp[offset + 8 * 7] = a - b;
    }
    ;
    sum += ((((temp[offset + 8 * 0]) + (temp[offset + 8 * 4])) >= 0 ? ((temp[offset + 8 * 0]) + (temp[offset + 8 * 4])) : (-((temp[offset + 8 * 0]) + (temp[offset + 8 * 4])))) + (((temp[offset + 8 * 0]) - (temp[offset + 8 * 4])) >= 0 ? ((temp[offset + 8 * 0]) - (temp[offset + 8 * 4])) : (-((temp[offset + 8 * 0]) - (temp[offset + 8 * 4]))))) + ((((temp[offset + 8 * 1]) + (temp[offset + 8 * 5])) >= 0 ? ((temp[offset + 8 * 1]) + (temp[offset + 8 * 5])) : (-((temp[offset + 8 * 1]) + (temp[offset + 8 * 5])))) + (((temp[offset + 8 * 1]) - (temp[offset + 8 * 5])) >= 0 ? ((temp[offset + 8 * 1]) - (temp[offset + 8 * 5])) : (-((temp[offset + 8 * 1]) - (temp[offset + 8 * 5]))))) + ((((temp[offset + 8 * 2]) + (temp[offset + 8 * 6])) >= 0 ? ((temp[offset + 8 * 2]) + (temp[offset + 8 * 6])) : (-((temp[offset + 8 * 2]) + (temp[offset + 8 * 6])))) + (((temp[offset + 8 * 2]) - (temp[offset + 8 * 6])) >= 0 ? ((temp[offset + 8 * 2]) - (temp[offset + 8 * 6])) : (-((temp[offset + 8 * 2]) - (temp[offset + 8 * 6]))))) + ((((temp[offset + 8 * 3]) + (temp[offset + 8 * 7])) >= 0 ? ((temp[offset + 8 * 3]) + (temp[offset + 8 * 7])) : (-((temp[offset + 8 * 3]) + (temp[offset + 8 * 7])))) + (((temp[offset + 8 * 3]) - (temp[offset + 8 * 7])) >= 0 ? ((temp[offset + 8 * 3]) - (temp[offset + 8 * 7])) : (-((temp[offset + 8 * 3]) - (temp[offset + 8 * 7])))));
}
}
