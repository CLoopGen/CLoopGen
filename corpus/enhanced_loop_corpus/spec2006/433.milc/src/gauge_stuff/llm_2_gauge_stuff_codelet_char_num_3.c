#include <stdio.h>

#include <inttypes.h>

extern int *dig;
extern int *chr;
extern int length;
extern int j;
extern int tenl;
extern int newv;
extern int old;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access (access every second element in reverse, then handle remainder)
    int stride = 2;
    int j;
    // First pass: strided access from the highest valid index downward
    for (j = length - 1; j >= 1; j -= stride) {
        int newv = old - tenl * dig[j];
        newv = newv * 10 + dig[j];
        if (newv < *chr)
            *chr = newv;
        old = newv;
    }
    // Second pass: handle offset start for remaining elements
    for (j = length - 2; j >= 1; j -= stride) {
        int newv = old - tenl * dig[j];
        newv = newv * 10 + dig[j];
        if (newv < *chr)
            *chr = newv;
        old = newv;
    }
}
