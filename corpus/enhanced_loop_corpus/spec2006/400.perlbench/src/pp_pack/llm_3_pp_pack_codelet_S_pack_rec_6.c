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
    I32 indices[64];
    for (I32 i = 0; i < 64; ++i) {
        indices[i] = (i * 13) % 64; // pseudo-random indirect access pattern
    }
    for (len = 0; len++ < aint && len < 64;) {
        items |= str[indices[len]] & 1;
        if (len & 7)
            items <<= 1;
        else {
            *aptr++ = items & 255;
            items = 0;
        }
    }
}
