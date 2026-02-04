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



void loop(){
    int step = 2;
    for (j = length - 1; j >= 1; j -= step) {
        newv = old - tenl * dig[j];
        newv = newv * 10 + dig[j];
        if (newv < *chr)
            *chr = newv;
        old = newv;
        if (j == 2) break; // Prevent underflow when step=2 and j reaches 2
    }
}
