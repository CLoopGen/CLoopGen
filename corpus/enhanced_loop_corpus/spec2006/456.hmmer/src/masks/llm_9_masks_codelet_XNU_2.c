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
    for (i = 1; i <= len; i++) {
        if (hit[i] && (i % 2 == 1)) {
            xnum++;
            dsq[i] = Alphabet_iupac - 1;
        }
        if (hit[i] && (i % 2 == 0)) {
            xnum += 2;
            dsq[i] = Alphabet_iupac - 2;
        }
    }
}
