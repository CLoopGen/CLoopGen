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
    for (index = 0; index < ncolors; index++) {
        if (((int)(colormap0[index])) != R) continue;
        if (((int)(colormap1[index])) != G) continue;
        if (((int)(colormap2[index])) == B)
            return;
    }
}
