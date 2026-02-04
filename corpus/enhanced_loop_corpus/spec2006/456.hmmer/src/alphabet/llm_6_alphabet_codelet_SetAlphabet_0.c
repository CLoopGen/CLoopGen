#include <stdio.h>

#include <inttypes.h>

extern int Alphabet_size;
extern char Degenerate[24][20];
extern int DegenCount[24];
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < Alphabet_size; i++) {
        Degenerate[i][i] = 1;
        DegenCount[i] = (i > 0) ? DegenCount[i-1] + 1 : 1;
    }
}
