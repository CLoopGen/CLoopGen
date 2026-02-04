#include <stdio.h>
#include <inttypes.h>

int Alphabet_size = 2000;
char Degenerate[24][20];
int DegenCount[24];
int x;

void init_vars() {
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 20; j++) {
            Degenerate[i][j] = 0;
        }
        DegenCount[i] = 0;
    }
    Alphabet_size = 20; // Ensure it does not exceed array bounds: max 20 due to inner loop index
}