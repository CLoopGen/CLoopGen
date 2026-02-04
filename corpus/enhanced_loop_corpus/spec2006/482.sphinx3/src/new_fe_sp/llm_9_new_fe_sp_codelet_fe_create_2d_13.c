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
    int limit = d1 * 2;
    for (i = 0, j = 0; i < limit; i += 2, j += d2 * 2 * elem_size) {
        if (i < d1) out[i] = &((char *)store)[j];
        if (i + 1 < d1) out[i + 1] = &((char *)store)[j + elem_size];
    }
}
