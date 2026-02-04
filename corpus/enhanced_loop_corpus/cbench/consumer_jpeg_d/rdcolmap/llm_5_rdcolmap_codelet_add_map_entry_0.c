#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

extern int R;
extern int G;
extern int B;
extern JSAMPROW colormap0;
extern JSAMPROW colormap1;
extern JSAMPROW colormap2;
extern int ncolors;
extern int _usr_index;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    int found = 0;
    for (index = 0; index < ncolors; index++) {
        int matchR = (((int)(colormap0[index])) == R);
        int matchG = (((int)(colormap1[index])) == G);
        int matchB = (((int)(colormap2[index])) == B);
        if (matchR && matchG && matchB) {
            found = 1;
        } else {
            continue;
        }
        if (found) return;
    }
}
