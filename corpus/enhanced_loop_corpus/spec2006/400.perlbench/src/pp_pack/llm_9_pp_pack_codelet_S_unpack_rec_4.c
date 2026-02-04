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
    for (len = 0; len < (aint + 3) / 4; len++) {
        I32 val = s[len];
        bits = ((val & 0xF0) >> 4);
        *str++ = PL_hexdigit[bits];
        bits = (val & 0x0F);
        *str++ = PL_hexdigit[bits];
        bits = ((val & 0x0F) << 4);
        *str++ = PL_hexdigit[(bits >> 4) & 15];
    }
}
