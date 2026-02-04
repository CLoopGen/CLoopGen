#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double count[100];
extern double edge[100];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 99; i >= 0; i--) {
    count[i] += edge[i];
    if (i + 1 < 100 && count[i + 1] == 0) {
        count[i] += edge[i + 1];
    }
    edge[i] = 0;
}
}
