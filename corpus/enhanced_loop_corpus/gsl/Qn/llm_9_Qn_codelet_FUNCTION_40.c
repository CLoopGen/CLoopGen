#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *right;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = ni * 2;
    for (i = 0; i < limit; ++i) {
        if (i < ni) {
            left[i] = ni - i + 1;
        }
        if (i >= ni) {
            int idx = i - ni;
            right[idx] = (idx <= h) ? ni : ni - (idx - h);
        }
    }
}
