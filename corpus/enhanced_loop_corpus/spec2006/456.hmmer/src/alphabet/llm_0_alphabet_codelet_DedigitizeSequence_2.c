#include <stdio.h>

#include <inttypes.h>

extern char Alphabet[25];
extern char *dsq;
extern int L;
extern char *seq;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1; j++)
        for (i = 0; i < L; i++)
            seq[i] = Alphabet[(int)dsq[i + 1]];
}
