#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int f[12];
extern int max;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 10 + 2; i++) {
        for (int j = i; j <= i; j++) {
            max = (max > ((f[j] >= 0 ? f[j] : -f[j]))) ? max : ((f[j] >= 0 ? f[j] : -f[j]));
        }
    }
}
