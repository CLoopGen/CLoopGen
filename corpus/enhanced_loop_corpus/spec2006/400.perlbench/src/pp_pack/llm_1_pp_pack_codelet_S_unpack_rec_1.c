#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char *s;
extern I32 len;
extern I32 bits;
extern char *str;
extern int aint;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (len = 0; len < aint; len += 2) {
    for (I32 step = 0; step < 2 && (len + step) < aint; step++) {
        I32 curr_len = len + step;
        if (curr_len & 7)
            bits >>= 1;
        else
            bits = *s++;
        *str++ = '0' + (bits & 1);
    }
}
}
