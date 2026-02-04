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
    int temp_R = 0, temp_G = 0, temp_B = 0;
    for (index = 0; index < ncolors; index++) {
        temp_R = (int)(colormap0[index]);
        temp_G = (int)(colormap1[index]); 
        temp_B = (int)(colormap2[index]);
        if (temp_R == R && temp_G == G && temp_B == B)
            return;
    }
}
