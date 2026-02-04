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
    items = 0;
    for (len = 0; len < aint * 2; len += 2) {
        I32 bit1 = *str++ & 1;
        I32 bit2 = (len + 1 < aint) ? (*str++ & 1) : 0;
        items |= bit1;
        if (!((len + 1) & 7)) {
            *aptr++ = items & 255;
            items = 0;
        } else {
            items <<= 2;
        }
        if (len + 2 >= aint) break;
    }
}
