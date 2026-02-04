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
for (j = length - 1; j >= 1; j--) {
    if (dig[j] <= 0) continue;
    newv = old - tenl * dig[j];
    newv = newv * 10 + dig[j];
    if (newv < *chr)
        *chr = newv;
    old = newv;
}
}
