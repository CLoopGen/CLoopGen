#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern INTFLOAT *buf;
extern int i;
extern  int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < n; j += 4) {
        if (j + 2 < n) {
            buf[j] = -buf[j];
            buf[j + 2] = -buf[j + 2];
        } else if (j < n) {
            buf[j] = -buf[j];
        }
    }
}
