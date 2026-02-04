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
    int temp;
    for (j = length - 1; j >= 1; j--) {
        temp = old - tenl * dig[j];
        temp = temp * 10 + dig[j];
        if (temp < *chr) {
            *chr = temp;
        }
        old = temp;
    }
}
