#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf_in;
extern size_t i;
extern unsigned char ctmp;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t start = 0;
    size_t end = l - 1;
    while (start < end) {
        ctmp = buf_in[start];
        buf_in[start] = buf_in[end];
        buf_in[end] = ctmp;
        start++;
        end--;
    }
}
