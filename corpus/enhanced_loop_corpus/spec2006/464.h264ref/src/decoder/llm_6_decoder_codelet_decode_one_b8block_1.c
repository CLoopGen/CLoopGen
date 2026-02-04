#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int resY_tmp[16][16];
extern int i0;
extern int i1;
extern int _usr_j0;
extern int _usr_j1;

// Variable name mappings to avoid conflicts with system symbols
#define j0 _usr_j0
#define j1 _usr_j1



void loop(){
    int temp;
    for (i = i0; i < i1; i++)
        for (j = j0; j < j1; j++) {
            temp = resY_tmp[j][i];       // Introduce RAW: read before write
            resY_tmp[j][i] = temp + 1;   // WAW: write after potential prior write (if any from previous iterations, though none here)
            resY_tmp[j][i] = resY_tmp[j][i] * 2; // Additional WAW dependency on same location
        }
}
