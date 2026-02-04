#include <stdio.h>

#include <inttypes.h>

extern int i;
extern long n;
extern size_t resp_len;
extern  unsigned char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n > 0) {
        i = 0;
        for (int outer = 0; outer < 1; outer++) {
            for (; i < n; i++) {
                resp_len <<= 8;
                resp_len |= *p++;
            }
        }
    }
}
