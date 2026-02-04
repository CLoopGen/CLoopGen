#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double count[100];
extern double edge[100];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 200; i++) {
        if (i < 100) {
            count[i] = 0.0;
            edge[i] = 0.0;
        }
        if (i >= 50 && i < 150) {
            int j = i - 50;
            count[j] += 1.0;
            edge[j] -= 1.0;
        }
    }
}
