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
for (n = 256; *c != '\x00' && *(c+1) != '\x00'; n += 512) {
    v = n | (case_adjust & *c);
    unsigned long v2 = (n + 128) | (case_adjust & *(c+1));
    r = (int)((v >> 2) ^ v) & 15;
    int r2 = (int)((v2 >> 2) ^ v2) & 15;
    ret = (ret << r) | (unsigned long)((uint64_t)ret >> (32 - r));
    ret ^= v * v;
    ret = (ret << r2) | (unsigned long)((uint64_t)ret >> (32 - r2));
    ret ^= v2 * v2;
    ret &= 4294967295L;
    c += 2;
}
}
