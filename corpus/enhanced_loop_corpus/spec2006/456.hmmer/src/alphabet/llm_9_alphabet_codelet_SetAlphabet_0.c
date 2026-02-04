#include <stdio.h>

#include <inttypes.h>

extern int Alphabet_size;
extern char Degenerate[24][20];
extern int DegenCount[24];
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < Alphabet_size * Alphabet_size; x++) {
        int i = x / Alphabet_size;
        int j = x % Alphabet_size;
        if (i == j) {
            Degenerate[i][j] = 1;
            DegenCount[i] = 1;
        }
    }
}
