#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern unsigned char *s;
extern unsigned char *x;
extern unsigned char *big;
extern I32 pos;
extern unsigned char *little;
extern unsigned char *littleend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char *temp_s = little;
    unsigned char *temp_x = big + pos + 1;
    I32 offset = 0;
    for (; temp_s < littleend; temp_s++, temp_x++, offset++) {
        if (*(temp_s) != *(temp_x)) {
            temp_s--;
            break;
        }
    }
    s = temp_s;
    x = temp_x;
}
