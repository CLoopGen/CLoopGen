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
    int step = 2;
    for (index = 0; index < ncolors; index += step) {
        if (((int)(colormap0[index])) == R && ((int)(colormap1[index])) == G && ((int)(colormap2[index])) == B)
            return;
        if (index + 1 < ncolors) {
            if (((int)(colormap0[index + 1])) == R && ((int)(colormap1[index + 1])) == G && ((int)(colormap2[index + 1])) == B)
                return;
        }
    }
}
