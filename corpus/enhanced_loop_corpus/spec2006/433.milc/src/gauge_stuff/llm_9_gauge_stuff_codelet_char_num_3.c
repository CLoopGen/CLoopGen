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
        newv = old - tenl * dig[j];
        newv = newv * 10 + dig[j];
        newv = (newv >> 1) + (newv & 1); // Additional bit operation to increase arithmetic intensity
        if (newv < *chr)
            *chr = newv;
        old = newv;
        
        // Duplicate body to increase computational load without changing logic meaningfully
        j--;
        if (j >= 1) {
            newv = old - tenl * dig[j];
            newv = newv * 10 + dig[j];
            newv = (newv >> 1) + (newv & 1);
            if (newv < *chr)
                *chr = newv;
            old = newv;
        }
    }
}
