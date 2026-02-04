#include <stdio.h>

#include <inttypes.h>

extern int **ip;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int j = 0; j < 6400; j++) {
    int i = j * 5;
    (*ip)[i] = (i + 4);
    (*ip)[i + 1] = (i + 2);
    (*ip)[i + 2] = (i);
    (*ip)[i + 3] = (i + 3);
    (*ip)[i + 4] = (i + 1);
}
}
