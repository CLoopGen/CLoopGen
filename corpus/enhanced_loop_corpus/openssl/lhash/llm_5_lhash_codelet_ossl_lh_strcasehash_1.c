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
    for (n = 256; *c != '\x00' && (v = n | (case_adjust & *c), (v % 3) != 0); n += 256) {
        r = (int)((v >> 2) ^ v) & 15;
        ret = (ret << r) | (unsigned long)((uint64_t)ret >> (32 - r));
        ret &= 4294967295L;
        ret ^= v * v;
        c++;
    }
}
