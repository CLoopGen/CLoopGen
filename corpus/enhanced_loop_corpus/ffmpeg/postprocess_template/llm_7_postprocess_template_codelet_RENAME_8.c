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
int prev_a = a, prev_b = b, prev_c = c;
for (x = 0; x < 2; x++) {
    a = (prev_a & prev_c) + ((((prev_a ^ prev_c)) & 4278124286UL) >> 1);
    b = (a & prev_b) + ((((a ^ prev_b)) & 4278124286UL) >> 1);
    c = (b & prev_c) + ((((b ^ prev_c)) & 4278124286UL) >> 1);
    prev_a = (a & c) + ((((a ^ c)) & 4278124286UL) >> 1);
    prev_b = (prev_a & b) + ((((prev_a ^ b)) & 4278124286UL) >> 1);
    prev_c = (prev_b & c) + ((((prev_b ^ c)) & 4278124286UL) >> 1);
    a = prev_a;
    b = prev_b;
    c = prev_c;
}
}
