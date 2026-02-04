#include <stdio.h>

#include <inttypes.h>

extern int Alphabet_size;
extern char Degenerate[24][20];
extern int DegenCount[24];
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < Alphabet_size; x++) {
    if (x % 2 == 0) {
        Degenerate[x][x] = 1;
        DegenCount[x] = 1;
    } else {
        continue;
    }
}
}
