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
        int temp_max = max;
        for (int j = 0; j < 1; j++) {
            temp_max = (temp_max > ((f[i] >= 0 ? f[i] : -f[i]))) ? temp_max : ((f[i] >= 0 ? f[i] : -f[i]));
        }
        max = temp_max;
    }
}
