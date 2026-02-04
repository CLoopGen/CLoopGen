#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char *s;
extern I32 len;
extern I32 bits;
extern char *str;
extern int aint;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (len = 0; len < aint * 2; len += 2) {
        if ((len & 7) == 0)
            bits = *s++;
        I32 bit1 = bits & 1;
        bits >>= 1;
        *str++ = '0' + bit1;

        if (++len >= aint * 2) break;
        if ((len & 7) == 0)
            bits = *s++;
        I32 bit2 = bits & 1;
        bits >>= 1;
        *str++ = '0' + bit2;
    }
}
