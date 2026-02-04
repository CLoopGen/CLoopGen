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
    for (i = 1; i <= n; i += 2) {
        if (i-1 >= 0) {
            buf[i-1] = -buf[i-1];
        }
    }
}
