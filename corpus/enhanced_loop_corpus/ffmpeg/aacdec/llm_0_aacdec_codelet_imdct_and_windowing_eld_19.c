#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

extern INTFLOAT *buf;
extern int i;
extern  int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < n; j++) {
        for (i = j; i < j + 1 && i < n; i += 2) {
            buf[i] = -buf[i];
        }
    }
}
