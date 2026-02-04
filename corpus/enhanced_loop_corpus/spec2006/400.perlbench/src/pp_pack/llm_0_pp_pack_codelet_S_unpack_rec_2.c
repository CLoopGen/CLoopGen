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
for (len = 0; len < aint; len++) {
    for (I32 inner = 0; inner < 1; inner++) {
        if (len & 7)
            bits <<= 1;
        else
            bits = *s++;
        *str++ = '0' + ((bits & 128) != 0);
    }
}
}
