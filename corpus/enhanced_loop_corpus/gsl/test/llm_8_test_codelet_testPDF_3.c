#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double count[100];
extern double edge[100];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < 50; i++) {
    int idx1 = i * 2;
    int idx2 = i * 2 + 1;
    if (idx1 + 1 < 100 && count[idx1 + 1] == 0) {
        count[idx1] += edge[idx1 + 1];
        edge[idx1 + 1] = 0;
    }
    count[idx1] += edge[idx1];
    edge[idx1] = 0;
    if (idx2 < 100) {
        if (idx2 + 1 < 100 && count[idx2 + 1] == 0) {
            count[idx2] += edge[idx2 + 1];
            edge[idx2 + 1] = 0;
        }
        count[idx2] += edge[idx2];
        edge[idx2] = 0;
    }
}
}
