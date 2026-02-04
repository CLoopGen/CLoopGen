#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern I32 items;
extern I32 len;
extern int aint;
extern char *aptr;
extern char *str;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (len = 0; len < (aint << 1); len += 2) {
        I32 chunk = 0;
        if (len < aint) {
            char c1 = *str++;
            if ((c1 >= 'A' && c1 <= 'Z') || (c1 >= 'a' && c1 <= 'z'))
                chunk |= ((c1 & 15) + 9) & 15;
            else
                chunk |= c1 & 15;
            chunk <<= 4;
        }
        if (len + 1 < aint) {
            char c2 = *str++;
            if ((c2 >= 'A' && c2 <= 'Z') || (c2 >= 'a' && c2 <= 'z'))
                chunk |= ((c2 & 15) + 9) & 15;
            else
                chunk |= c2 & 15;
        }
        *aptr++ = chunk & 255;
    }
    items = (aint + 1) >> 1;
}
