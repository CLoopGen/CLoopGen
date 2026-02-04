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
for (i = i0; i < i1; i++)
    for (j = j0; j < j1; j++) {
        if (i % 2 == 0) {
            resY_tmp[j][i] = 0;
        }
    }
}
