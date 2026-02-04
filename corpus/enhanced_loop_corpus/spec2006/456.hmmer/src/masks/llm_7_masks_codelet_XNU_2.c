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
    int prev_i = 0;
    for (i = 1; i <= len; i++) {
        if (hit[i] && prev_i != 0) {
            dsq[prev_i] = Alphabet_iupac - 1;
            xnum++;
        }
        prev_i = i;
    }
    if (prev_i > 0 && hit[prev_i]) {
        dsq[prev_i] = Alphabet_iupac - 1;
        xnum++;
    }
}
