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
for (len = 0; len++ < (aint >> 1);) {
    char c = *str++;
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        items |= (((c & 15) + 9) & 15) << 4;
    else
        items |= (c & 15) << 4;

    // Reduced operations: removed conditional shift, always process output
    *aptr++ = items & 255;
    items = 0;
    len++; // Simulate processing two elements per iteration
}
}
