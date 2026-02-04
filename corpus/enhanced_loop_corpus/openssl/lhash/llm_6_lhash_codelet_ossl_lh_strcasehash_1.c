#include <stdio.h>

#include <inttypes.h>

extern  char *c;
extern unsigned long ret;
extern long n;
extern unsigned long v;
extern int r;
extern  long case_adjust;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    long temp_n = 256;
    while (1) {
        if (*c == '\x00') break;
        v = temp_n | (case_adjust & *c);
        r = (int)((v >> 2) ^ v) & 15;
        ret = (ret << r) | (unsigned long)((uint64_t)ret >> (32 - r));
        ret &= 4294967295L;
        ret ^= v * v;
        c++;
        temp_n += 256;
    }
}
