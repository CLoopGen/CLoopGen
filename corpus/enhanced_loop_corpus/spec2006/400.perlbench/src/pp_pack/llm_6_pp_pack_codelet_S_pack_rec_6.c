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
    I32 temp_items = 0;
    for (len = 0; len++ < aint;) {
        temp_items |= *str++ & 1;
        if (len & 7) {
            temp_items <<= 1;
        } else {
            *aptr++ = temp_items & 255;
            temp_items = 0;
        }
    }
    items = temp_items;
}
