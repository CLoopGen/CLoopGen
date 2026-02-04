#include <stdio.h>

#include <inttypes.h>

extern int **ip;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *p = *ip;
    for (int i = 0; i < 32000; i += 5) {
        p[i] = (i + 4);
        p[i + 1] = (i + 2);
        p[i + 2] = (i);
        p[i + 3] = (i + 3);
        p[i + 4] = (i + 1);
    }
}
