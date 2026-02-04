#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;

int R = 255;
int G = 128;
int B = 64;
int ncolors = 1 << 20; // ~1M entries, approx 3MB total data
int _usr_index;

JSAMPROW colormap0;
JSAMPROW colormap1;
JSAMPROW colormap2;

void init_vars() {
    colormap0 = (JSAMPROW)malloc(ncolors * sizeof(JSAMPLE));
    colormap1 = (JSAMPROW)malloc(ncolors * sizeof(JSAMPLE));
    colormap2 = (JSAMPROW)malloc(ncolors * sizeof(JSAMPLE));

    if (!colormap0 || !colormap1 || !colormap2) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    srand(0);
    for (int i = 0; i < ncolors; i++) {
        colormap0[i] = rand() % 256;
        colormap1[i] = rand() % 256;
        colormap2[i] = rand() % 256;
    }

    R = 255;
    G = 128;
    B = 64;

    colormap0[ncolors - 1] = R;
    colormap1[ncolors - 1] = G;
    colormap2[ncolors - 1] = B;

    _usr_index = 0;
}