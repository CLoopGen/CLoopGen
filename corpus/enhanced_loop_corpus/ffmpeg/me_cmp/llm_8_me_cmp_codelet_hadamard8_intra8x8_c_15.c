#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int temp[64];
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i++) {
    {
        int a, b;
        a = temp[8 * 0 + (i % 8)];
        b = temp[8 * 1 + (i % 8)];
        temp[8 * 0 + (i % 8)] = a + b;
        temp[8 * 1 + (i % 8)] = a - b;
    }
    ;
    {
        int a, b;
        a = temp[8 * 2 + (i % 8)];
        b = temp[8 * 3 + (i % 8)];
        temp[8 * 2 + (i % 8)] = a + b;
        temp[8 * 3 + (i % 8)] = a - b;
    }
    ;
    {
        int a, b;
        a = temp[8 * 4 + (i % 8)];
        b = temp[8 * 5 + (i % 8)];
        temp[8 * 4 + (i % 8)] = a + b;
        temp[8 * 5 + (i % 8)] = a - b;
    }
    ;
    {
        int a, b;
        a = temp[8 * 6 + (i % 8)];
        b = temp[8 * 7 + (i % 8)];
        temp[8 * 6 + (i % 8)] = a + b;
        temp[8 * 7 + (i % 8)] = a - b;
    }
    ;
    sum += ((((temp[8 * 0 + (i % 8)]) + (temp[8 * 4 + (i % 8)])) >= 0 ? ((temp[8 * 0 + (i % 8)]) + (temp[8 * 4 + (i % 8)])) : (-((temp[8 * 0 + (i % 8)]) + (temp[8 * 4 + (i % 8)])))) + (((temp[8 * 0 + (i % 8)]) - (temp[8 * 4 + (i % 8)])) >= 0 ? ((temp[8 * 0 + (i % 8)]) - (temp[8 * 4 + (i % 8)])) : (-((temp[8 * 0 + (i % 8)]) - (temp[8 * 4 + (i % 8)]))))) + ((((temp[8 * 1 + (i % 8)]) + (temp[8 * 5 + (i % 8)])) >= 0 ? ((temp[8 * 1 + (i % 8)]) + (temp[8 * 5 + (i % 8)])) : (-((temp[8 * 1 + (i % 8)]) + (temp[8 * 5 + (i % 8)])))) + (((temp[8 * 1 + (i % 8)]) - (temp[8 * 5 + (i % 8)])) >= 0 ? ((temp[8 * 1 + (i % 8)]) - (temp[8 * 5 + (i % 8)])) : (-((temp[8 * 1 + (i % 8)]) - (temp[8 * 5 + (i % 8)]))))) + ((((temp[8 * 2 + (i % 8)]) + (temp[8 * 6 + (i % 8)])) >= 0 ? ((temp[8 * 2 + (i % 8)]) + (temp[8 * 6 + (i % 8)])) : (-((temp[8 * 2 + (i % 8)]) + (temp[8 * 6 + (i % 8)])))) + (((temp[8 * 2 + (i % 8)]) - (temp[8 * 6 + (i % 8)])) >= 0 ? ((temp[8 * 2 + (i % 8)]) - (temp[8 * 6 + (i % 8)])) : (-((temp[8 * 2 + (i % 8)]) - (temp[8 * 6 + (i % 8)]))))) + ((((temp[8 * 3 + (i % 8)]) + (temp[8 * 7 + (i % 8)])) >= 0 ? ((temp[8 * 3 + (i % 8)]) + (temp[8 * 7 + (i % 8)])) : (-((temp[8 * 3 + (i % 8)]) + (temp[8 * 7 + (i % 8)])))) + (((temp[8 * 3 + (i % 8)]) - (temp[8 * 7 + (i % 8)])) >= 0 ? ((temp[8 * 3 + (i % 8)]) - (temp[8 * 7 + (i % 8)])) : (-((temp[8 * 3 + (i % 8)]) - (temp[8 * 7 + (i % 8)])))));
}

}
