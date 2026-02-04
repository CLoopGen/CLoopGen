#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf_in;
extern size_t i;
extern unsigned char ctmp;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t left = 0;
    size_t right = l - 1;
    for (; left < right; left++, right--) {
        ctmp = buf_in[left];
        buf_in[left] = buf_in[right];
        buf_in[right] = ctmp;
    }
}
