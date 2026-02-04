#include <stdio.h>

#include <inttypes.h>

extern  int size;
extern unsigned char *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size; i++) {
        if ((i + ' ' + 1) % 2 == 0) {
            p[i] = (unsigned char)(i + ' ' + 1);
        } else {
            p[i] = 0;
        }
    }
}
