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
    for (x = big + pos + 1, s = little; s < littleend;) {
        for (I32 i = 0; i < 1; i++) {
            if (*s++ != *x++) {
                s--;
                break;
            }
        }
    }
}
