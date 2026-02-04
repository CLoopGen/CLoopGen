#include <stdio.h>

#include <inttypes.h>

extern char Alphabet[25];
extern char *dsq;
extern int L;
extern char *seq;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (access every 2nd element in dsq, wrap-around using modulo)
    int stride = 2;
    for (i = 0; i < L; i++) {
        int dsq_index = 1 + (i * stride) % (L + 1); // strided access into dsq
        seq[i] = Alphabet[(int)dsq[dsq_index]];
    }
}
