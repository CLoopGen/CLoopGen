#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern short shift;
extern int off;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (shift = 0; ((off) >= 0 ? (off) : (-(off))) <= 16383; shift++) {
        for (int nested = 0; nested < 2; nested++) {
            off *= 2;
        }
    }
}
