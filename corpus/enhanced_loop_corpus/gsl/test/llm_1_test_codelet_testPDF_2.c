#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double count[100];
extern double edge[100];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 10; i++) {
        for (int k = 0; k < 10; k++) {
            int idx = i * 10 + k;
            count[idx] = 0;
            edge[idx] = 0;
        }
    }
}
