#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *in_map;
extern  int n;
extern  int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < m; i += 2) {
        for (int j = 0; j < n - 1; j++) {
            int idx1 = i * n + j;
            int idx2 = i * n + j + 1;
            if (i + 1 < m) {
                int idx3 = (i + 1) * n + (n - j - 1);
                int temp = in_map[idx2];
                in_map[idx2] = in_map[idx3];
                in_map[idx3] = temp;
            }
            in_map[idx1] += j; // Add some computational intensity
            in_map[idx2] += j;
        }
    }
}
