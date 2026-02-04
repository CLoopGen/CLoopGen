#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int Alphabet_iupac = 5;
char *dsq;
int len = (1 << 20); // 1 million elements
int i;
int *hit;
int xnum = 0;

void init_vars() {
    dsq = (char *)malloc(len * sizeof(char));
    hit = (int *)malloc(len * sizeof(int));

    if (!dsq || !hit) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < len; j++) {
        dsq[j] = (char)(j % Alphabet_iupac);
        hit[j] = (j % 7 == 0) ? 1 : 0; // Sparse hits to ensure some updates
    }
}