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
    I32 temp_bits[8] = {0};
    char temp_str[8];
    I32 chunk, i;
    for (len = 0; len < aint; len += 8) {
        chunk = *s++;
        for (i = 0; i < 8 && (len + i) < aint; i++) {
            temp_bits[i] = chunk;
            chunk <<= 1;
            temp_str[i] = '0' + ((temp_bits[i] & 128) != 0);
        }
        for (i = 0; i < 8 && (len + i) < aint; i++) {
            *str++ = temp_str[i];
        }
    }
}
