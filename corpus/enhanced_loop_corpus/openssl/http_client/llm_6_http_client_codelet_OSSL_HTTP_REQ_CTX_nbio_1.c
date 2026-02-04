#include <stdio.h>

#include <inttypes.h>

extern int i;
extern long n;
extern size_t resp_len;
extern  unsigned char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp = resp_len;
    for (i = 0; i < n; i++) {
        temp <<= 8;
        temp |= *p++;
    }
    resp_len = temp;
}
