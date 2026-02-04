#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int v[];
extern  int arbitrary_element;
extern int m;
extern int r;
extern int kj;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 1; i++) {
    for (r = kj + 1; r < m; r++) {
        v[r] = arbitrary_element;
    }
}
}
