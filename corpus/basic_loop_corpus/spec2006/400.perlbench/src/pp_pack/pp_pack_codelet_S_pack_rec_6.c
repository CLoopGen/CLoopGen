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
for (len = 0; len++ < aint;) {
    items |= *str++ & 1;
    if (len & 7)
        items <<= 1;
    else {
        *aptr++ = items & 255;
        items = 0;
    }
}

}
