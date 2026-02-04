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
I32 i;
for (i = 0; i < aint; i++) {
    for (len = i; len++ < i + 1;) {
        items |= *str++ & 1;
        if (len & 7)
            items <<= 1;
        else {
            *aptr++ = items & 255;
            items = 0;
        }
    }
}
}
