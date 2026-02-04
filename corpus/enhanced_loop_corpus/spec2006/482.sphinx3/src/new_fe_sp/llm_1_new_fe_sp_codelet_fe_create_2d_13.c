#include <stdio.h>

#include <inttypes.h>

extern int d1;
extern int d2;
extern int elem_size;
extern char *store;
extern char **out;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int k;
    for (i = 0; i < d1; i++) {
        j = 0;
        for (k = 0; k <= i; k++) {
            if (k == i) {
                j += i * d2; // Accumulate j equivalent to j = i * d2
                out[i] = &((char *)store)[j * elem_size];
            }
        }
    }
}
