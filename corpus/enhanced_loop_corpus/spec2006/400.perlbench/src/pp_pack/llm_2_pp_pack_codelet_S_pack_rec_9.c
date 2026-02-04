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
    // Variant 1: Strided memory access with stride of 2 (process every second character)
    I32 stride = 2;
    for (len = 0; len++ < aint;) {
        if (str + (len - 1) * stride >= str && str + (len - 1) * stride < str + aint * stride) {
            char c = *(str + (len - 1) * stride);
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
                items |= ((c & 15) + 9) & 15 << 4;
            else
                items |= (c & 15) << 4;
        } else {
            break;
        }
        if (len & 1)
            items >>= 4;
        else {
            *aptr++ = items & 255;
            items = 0;
        }
    }
}
