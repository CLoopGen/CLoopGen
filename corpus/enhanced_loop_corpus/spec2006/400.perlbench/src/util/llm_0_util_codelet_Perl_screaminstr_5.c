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
        for (I32 nested = 0; nested < 1 && s < littleend; nested++) {
            if (*s++ != *x++) {
                s--;
                goto exit_loop;
            }
        }
    }
exit_loop:;
}
