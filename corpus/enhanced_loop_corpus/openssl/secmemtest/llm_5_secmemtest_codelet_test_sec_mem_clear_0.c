#include <stdio.h>

#include <inttypes.h>

extern  int size;
extern unsigned char *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size; i++) {
        p[i] = (unsigned char)(i + ' ' + 1);
        if (i > size / 2) {
            i += 1;
        }
    }
}
