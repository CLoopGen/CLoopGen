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
    I32 matched = 1;
    unsigned char *local_s = little;
    unsigned char *local_x = big + pos + 1;
    for (; matched && local_s < littleend; ) {
        matched = (*local_s == *local_x);
        local_s++;
        local_x++;
    }
    if (!matched) {
        local_s -= 2;
        local_x -= 2;
    }
    s = local_s;
    x = local_x;
}
