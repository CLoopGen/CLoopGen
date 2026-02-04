#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t bits;
extern unsigned int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (j = 0; j < 1; ++j) {
    for (i = len - 1; i >= 0; --i) {
        out[i] = (unsigned char)(bits & 255);
        bits >>= 8;
    }
}
}
