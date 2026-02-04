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
    for (n = 256; *c != '\x00' && *(c+1) != '\x00'; n += 512) {  // Decreased effective loop depth by processing two iterations at once
        v = n | (case_adjust & *c);
        r = (int)((v >> 2) ^ v) & 15;
        ret = (ret << r) | (unsigned long)((uint64_t)ret >> (32 - r));
        ret &= 4294967295L;
        ret ^= v * v;
        c++;

        v = n + 256 | (case_adjust & *c);
        r = (int)((v >> 2) ^ v) & 15;
        ret = (ret << r) | (unsigned long)((uint64_t)ret >> (32 - r));
        ret &= 4294967295L;
        ret ^= v * v;
        c++;
    }
    // Handle potential last character if odd length
    if (*c != '\x00') {
        v = n | (case_adjust & *c);
        r = (int)((v >> 2) ^ v) & 15;
        ret = (ret << r) | (unsigned long)((uint64_t)ret >> (32 - r));
        ret &= 4294967295L;
        ret ^= v * v;
        c++;
    }
}
