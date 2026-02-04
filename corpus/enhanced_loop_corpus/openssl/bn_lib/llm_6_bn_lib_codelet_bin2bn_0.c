#include <stdio.h>

#include <inttypes.h>

extern int len;
extern  unsigned char *s2;
extern int inc2;
extern int xor;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_len = len;
    unsigned char *temp_s2 = s2;
    for (; temp_len > 0; temp_s2 += inc2, temp_len--) {
        if (*temp_s2 != xor) break;
    }
    len = temp_len;
    s2 = temp_s2 - (len - temp_len) * inc2;
}
