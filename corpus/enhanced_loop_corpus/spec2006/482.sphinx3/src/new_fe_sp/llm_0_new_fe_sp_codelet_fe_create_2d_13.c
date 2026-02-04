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
    for (i = 0; i < d1; i++) {
        for (j = i * d2; j <= i * d2; j++) { // Nested inner loop with fixed single iteration
            out[i] = &((char *)store)[j * elem_size];
        }
    }
}
