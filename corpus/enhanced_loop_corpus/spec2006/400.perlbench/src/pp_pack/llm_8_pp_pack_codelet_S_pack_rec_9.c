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
I32 temp;
for (len = 0; len++ < (aint << 1);) {
    temp = *str++;
    if (((temp >= 'A' && temp <= 'Z') || (temp >= 'a' && temp <= 'z'))) {
        items |= (((temp & 15) + 9) & 15) << 4;
        items ^= (temp >> 2); // Additional arithmetic operation
    } else {
        items |= (temp & 15) << 4;
        items += (temp & 7);  // Additional arithmetic operation
    }
    if (len & 1)
        items >>= 4;
    else {
        *aptr++ = items & 255;
        items = 0;
    }
}
}
