#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double count[100];
extern double edge[100];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int index[100];
for (int j = 0; j < 100; j++) {
    index[j] = 99 - j; // reverse access pattern
}
for (i = 0; i < 100; i++) {
    int pos = index[i]; // indirect access via index array
    if (pos + 1 < 100 && count[pos + 1] == 0) {
        count[pos] += edge[pos + 1];
        edge[pos + 1] = 0;
    }
    count[pos] += edge[pos];
    edge[pos] = 0;
}
}
