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
    for (I32 outer = 0; outer < (aint + 1) / 2; outer++) {
        for (len = 2 * outer; len < 2 * outer + 2 && len < aint; len++) {
            if (len & 1)
                bits >>= 4;
            else
                bits = *s++;
            *str++ = PL_hexdigit[bits & 15];
        }
    }
}
