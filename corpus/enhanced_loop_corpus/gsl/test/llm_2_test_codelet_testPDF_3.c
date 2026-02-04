#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double count[100];
extern double edge[100];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 100; i += 2) {
    if (i + 1 < 100 && count[i + 1] == 0) {
        count[i] += edge[i + 1];
        edge[i + 1] = 0;
    }
    count[i] += edge[i];
    edge[i] = 0;

    if (i + 1 < 100) {
        if (i + 2 < 100 && count[i + 2] == 0) {
            count[i + 1] += edge[i + 2];
            edge[i + 2] = 0;
        }
        count[i + 1] += edge[i + 1];
        edge[i + 1] = 0;
    }
}
}
