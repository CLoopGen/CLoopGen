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
for (len = 0; len < aint; len++) {
    if (len & 1)
        bits <<= 4;
    else
        bits = *s++;
    *str++ = PL_hexdigit[(bits >> 4) & 15];
}

}
