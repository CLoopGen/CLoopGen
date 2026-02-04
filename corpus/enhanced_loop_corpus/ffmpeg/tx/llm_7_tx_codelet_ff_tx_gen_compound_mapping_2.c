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
    int limit = (n - 1) >> 1;
    int offset = n - 2;
    for (int j = 0; j < limit; j++) {
        int rev_index = offset - j;
        int forward_val = in[j];
        int reverse_val = in[rev_index];
        in[j] = reverse_val;
        in[rev_index] = forward_val;
    }
}
}
