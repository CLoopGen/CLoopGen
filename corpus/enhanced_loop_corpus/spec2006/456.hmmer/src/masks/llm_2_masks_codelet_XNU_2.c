#include <stdio.h>

#include <inttypes.h>

extern int Alphabet_iupac;
extern char *dsq;
extern int len;
extern int i;
extern int *hit;
extern int xnum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step by 2, process even indices only)
    for (i = 2; i <= len; i += 2)
        if (hit[i]) {
            xnum++;
            dsq[i] = Alphabet_iupac - 1;
        }
}
