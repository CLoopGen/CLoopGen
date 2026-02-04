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
    int is_alpha = ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
    str++;
    if (is_alpha) {
        items |= ((c & 15) + 9) & 15 << 4;
    } else {
        items |= (c & 15) << 4;
    }
    if (!(len & 1)) {
        *aptr++ = items & 255;
        items = 0;
    } else {
        items >>= 4;
    }
}
}
