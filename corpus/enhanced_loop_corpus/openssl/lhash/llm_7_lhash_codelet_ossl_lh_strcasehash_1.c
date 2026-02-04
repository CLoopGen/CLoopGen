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
    for (n = 256; *c != '\x00'; ) {
        long next_n = n + 256;
        unsigned long local_v = n | (case_adjust & *c);
        int local_r = (int)((local_v >> 2) ^ local_v) & 15;
        unsigned long shifted = (ret << local_r) | (unsigned long)((uint64_t)ret >> (32 - local_r));
        shifted &= 4294967295L;
        shifted ^= local_v * local_v;
        c++;
        n = next_n;
        ret = shifted;
    }
}
