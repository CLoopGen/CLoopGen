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
for (i = 0 , j = 0; i < d1; i++ , j += d2) {
    if (d2 <= 0) continue;
    out[i] = &((char *)store)[j * elem_size];
}
}
