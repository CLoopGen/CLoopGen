#include <stdio.h>

#include <inttypes.h>

extern char Alphabet[25];
extern char *dsq;
extern int L;
extern char *seq;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char temp;
    for (i = 0; i < L; i++) {
        temp = dsq[i + 1];
        seq[i] = Alphabet[(int)temp];
    }
}
