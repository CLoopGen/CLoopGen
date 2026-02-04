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
    for (index = 0; index < ncolors && !found; index++) {
        int match_r = ((int)(colormap0[index])) == R;
        int match_g = ((int)(colormap1[index])) == G;
        int match_b = ((int)(colormap2[index])) == B;
        found = match_r && match_g && match_b;
    }
    if (found) {
        // Simulate early exit effect without using break or goto
        return;
    }
}
