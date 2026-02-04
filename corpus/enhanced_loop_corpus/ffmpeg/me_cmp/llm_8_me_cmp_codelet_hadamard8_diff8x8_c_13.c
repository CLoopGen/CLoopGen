#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int temp[64];
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    {
        int a, b;
        a = temp[8 * 0 + i];
        b = temp[8 * 1 + i];
        temp[8 * 0 + i] = a + b;
        temp[8 * 1 + i] = a - b;
    }
    ;
    {
        int a, b;
        a = temp[8 * 2 + i];
        b = temp[8 * 3 + i];
        temp[8 * 2 + i] = a + b;
        temp[8 * 3 + i] = a - b;
    }
    ;
    {
        int a, b;
        a = temp[8 * 4 + i];
        b = temp[8 * 5 + i];
        temp[8 * 4 + i] = a + b;
        temp[8 * 5 + i] = a - b;
    }
    ;
    {
        int a, b;
        a = temp[8 * 6 + i];
        b = temp[8 * 7 + i];
        temp[8 * 6 + i] = a + b;
        temp[8 * 7 + i] = a - b;
    }
    ;
    {
        int a, b;
        a = temp[8 * 0 + i];
        b = temp[8 * 2 + i];
        temp[8 * 0 + i] = a + b;
        temp[8 * 2 + i] = a - b;
    }
    ;
    {
        int a, b;
        a = temp[8 * 1 + i];
        b = temp[8 * 3 + i];
        temp[8 * 1 + i] = a + b;
        temp[8 * 3 + i] = a - b;
    }
    ;
    sum += ((abs(temp[8 * 0 + i]) + abs(temp[8 * 1 + i])) + (abs(temp[8 * 2 + i]) + abs(temp[8 * 3 + i]))) +
           ((abs(temp[8 * 4 + i]) + abs(temp[8 * 5 + i])) + (abs(temp[8 * 6 + i]) + abs(temp[8 * 7 + i])));
}
}
