#include <stdio.h>

#include <inttypes.h>

extern char *name;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp;
    int stride = 1;
    for (temp = p; temp - name > 2; temp -= stride) {
        *temp = *(temp - stride);
        stride = (stride + 1) % 4 + 1; // Vary stride cyclically between 1 and 4
    }
}
