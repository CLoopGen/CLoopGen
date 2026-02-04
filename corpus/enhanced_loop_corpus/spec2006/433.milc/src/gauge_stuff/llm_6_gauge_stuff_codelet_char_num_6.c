#include <stdio.h>

#include <inttypes.h>

extern int *chr;
extern int length;
extern int j;
extern int bdig[6];
extern int tenl;
extern int newv;
extern int old;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int temp_old = old;
    for (j = length - 1; j >= 1; j--) {
        int temp_newv = temp_old - tenl * bdig[j];
        temp_newv = temp_newv * 10 + bdig[j];
        if (temp_newv < *chr)
            *chr = temp_newv;
        temp_old = temp_newv;
    }
    old = temp_old;
}
