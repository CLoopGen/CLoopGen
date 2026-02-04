#include <stdio.h>

#include <inttypes.h>

extern int n;
extern char *p;
extern char *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int stride = 1; stride <= 2; stride *= 2) {
        for (; *p == '0' || *p == ' '; p += stride) {
            if (*p == '0' && stride == 1) {
                q = p;
                *p = ' ';
                n -= stride;
            }
        }
    }
}
