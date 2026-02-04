#include <stdio.h>

#include <inttypes.h>

extern int i;
extern long n;
extern size_t resp_len;
extern  unsigned char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; i++) {
        for (int j = 0; j < 1; j++) {
            resp_len <<= 8;
            resp_len |= *p++;
        }
    }
}
