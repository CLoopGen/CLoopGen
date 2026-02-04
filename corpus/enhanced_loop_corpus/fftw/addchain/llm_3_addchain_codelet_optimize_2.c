#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int mulcost;
extern int reflcost;
extern int n;
extern int *A;
extern int i;
extern int j;
extern int k;
extern int changed;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Change memory access to strided pattern: process every 2nd element in A
// and modify indexing to simulate strided memory behavior.
int stride = 2;
int offset = 1;
int *B = A;  // Use B as alias to emphasize access pattern change

for (i = 0; i < n; i += stride) {
    for (j = 0; j <= i; j += stride) {
        k = i + j;
        if (k < n) {
            int idx_i = (i + offset) % n;
            int idx_j = (j + offset) % n;
            int idx_k = (k + offset) % n;
            int c = B[idx_i] + B[idx_j] + mulcost;
            if (c < B[idx_k]) {
                B[idx_k] = c;
                changed = 1;
            }
        }
        ;
        k = i - j;
        if (k >= 0 && k < n) {
            int idx_i = (i + offset) % n;
            int idx_j = (j + offset) % n;
            int idx_k = (k + offset) % n;
            int c = B[idx_i] + B[idx_j] + mulcost;
            if (c < B[idx_k]) {
                B[idx_k] = c;
                changed = 1;
            }
        }
        ;
        k = i + j;
        if (k < n && i >= j) {
            int idx_i = (i + offset) % n;
            int idx_j = (j + offset) % n;
            int idx_imj = ((i - j) + offset) % n;
            int idx_k = (k + offset) % n;
            int c = B[idx_i] + B[idx_j] + B[idx_imj] + reflcost;
            if (c < B[idx_k]) {
                B[idx_k] = c;
                changed = 1;
            }
        }
        ;
    }
}
}
