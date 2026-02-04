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
        int *in = &in_map[i * n];
        int limit = (n >> 1);
        for (int j = 0; j < limit; j++) {
            int temp = in[j];
            in[j] = in[n - 1 - j];
            in[n - 1 - j] = temp;
        }
    }
}
