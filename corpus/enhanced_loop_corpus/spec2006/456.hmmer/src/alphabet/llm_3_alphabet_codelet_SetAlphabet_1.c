#include <stdio.h>

#include <inttypes.h>

extern int Alphabet_size;
extern char Degenerate[24][20];
extern int DegenCount[24];
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < Alphabet_size; x++) {
    int idx = Alphabet_size - 1 - x; // Reverse access pattern
    Degenerate[idx][idx] = 1;
    DegenCount[idx] = 1;
}
}
