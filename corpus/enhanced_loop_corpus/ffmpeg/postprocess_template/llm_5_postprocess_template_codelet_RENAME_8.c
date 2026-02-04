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
        if (a > b) {
            a = (a & c) + (((a ^ c) & 4278124286UL) >> 1);
            b = (a & b) + (((a ^ b) & 4278124286UL) >> 1);
        } else {
            c = (b & c) + (((b ^ c) & 4278124286UL) >> 1);
            a = (a & c) + (((a ^ c) & 4278124286UL) >> 1);
        }
        if (b <= c) {
            b = (a & b) + (((a ^ b) & 4278124286UL) >> 1);
        }
        c = (b & c) + (((b ^ c) & 4278124286UL) >> 1);
        a = (a & c) + (((a ^ c) & 4278124286UL) >> 1);
    }
}
