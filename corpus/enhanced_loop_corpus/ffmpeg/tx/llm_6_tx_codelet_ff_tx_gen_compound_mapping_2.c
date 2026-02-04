#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *in_map;
extern  int n;
extern  int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < m; i++) {
    int *in = &in_map[i * n + 1];
    for (int j = 0; j < ((n - 1) >> 1); j++) {
        int index1 = j;
        int index2 = n - j - 2;
        int temp1 = in[index1];
        int temp2 = in[index2];
        in[index1] = temp2;
        in[index2] = temp1;
    }
}
}
