#include <stdio.h>

#include <inttypes.h>

extern char Alphabet[25];
extern char *dsq;
extern int L;
extern char *seq;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < L; i += 2) {
        seq[i] = Alphabet[(int)dsq[i + 1]];
        if (i + 1 < L) {
            seq[i + 1] = Alphabet[(int)dsq[i + 2]];
        }
    }
}
