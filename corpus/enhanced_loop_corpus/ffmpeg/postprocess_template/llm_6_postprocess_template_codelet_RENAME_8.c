#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int a;
extern int b;
extern int c;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < 2; x++) {
    int temp_a = a, temp_b = b, temp_c = c;
    temp_a = (temp_a & temp_c) + (((temp_a ^ temp_c) & 4278124286UL) >> 1);
    temp_b = (temp_a & temp_b) + (((temp_a ^ temp_b) & 4278124286UL) >> 1);
    temp_c = (temp_b & temp_c) + (((temp_b ^ temp_c) & 4278124286UL) >> 1);
    temp_a = (temp_a & temp_c) + (((temp_a ^ temp_c) & 4278124286UL) >> 1);
    temp_b = (temp_a & temp_b) + (((temp_a ^ temp_b) & 4278124286UL) >> 1);
    temp_c = (temp_b & temp_c) + (((temp_b ^ temp_c) & 4278124286UL) >> 1);
    temp_a = (temp_a & temp_c) + (((temp_a ^ temp_c) & 4278124286UL) >> 1);
    temp_b = (temp_a & temp_b) + (((temp_a ^ temp_b) & 4278124286UL) >> 1);
    a = temp_a; b = temp_b; c = temp_c;
}
}
