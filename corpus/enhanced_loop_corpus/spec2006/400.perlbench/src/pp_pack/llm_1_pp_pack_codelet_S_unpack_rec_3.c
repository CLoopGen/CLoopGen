#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern const char *PL_hexdigit;
extern char *s;
extern I32 len;
extern I32 bits;
extern char *str;
extern int aint;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 temp_len = 0;
    for (I32 group = 0; group < aint; group += 8) {
        for (I32 step = 0; step < 8 && temp_len < aint; step++, temp_len++) {
            len = temp_len;
            if (len & 1)
                bits >>= 4;
            else
                bits = *s++;
            *str++ = PL_hexdigit[bits & 15];
        }
    }
}
