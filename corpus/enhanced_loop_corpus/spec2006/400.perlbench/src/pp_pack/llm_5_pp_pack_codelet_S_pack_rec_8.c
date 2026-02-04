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
    char c = *str;
    if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
        items |= *str++ & 15;
    else
        items |= ((*str++ & 15) + 9) & 15;

    if (!(len & 1)) {
        *aptr++ = items & 255;
        items = 0;
        continue;
    }
    items <<= 4;
}
}
