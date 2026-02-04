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



void loop(){
    for (j = length - 1; j >= 1; j--) {
        newv = old - tenl * bdig[j];
        newv = newv * 10 + bdig[j];
        newv = (newv >> 1) + (newv & 1); // Additional bit operation to increase arithmetic intensity
        if (newv < *chr)
            *chr = newv;
        old = newv;

        // Unroll-like effect with repeated logic on modified index (if possible)
        if (j > 1) {
            int k = j - 1;
            int temp = old - tenl * bdig[k];
            temp = temp * 10 + bdig[k];
            temp = (temp >> 1) + (temp & 1);
            if (temp < *chr)
                *chr = temp;
            old = temp;
            j--; // Compensate for double iteration
        }
    }
}
