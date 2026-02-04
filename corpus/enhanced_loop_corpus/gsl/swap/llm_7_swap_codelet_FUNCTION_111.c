#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern int *Aj;
extern int *Ap;
extern int *ATj;
extern int *w;
extern int p;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < M; ++i) {
        size_t temp_count = 0;
        for (p = Ap[i]; p < Ap[i + 1]; ++p) {
            temp_count++;
        }
        size_t start_index = w[i];
        for (p = 0; p < temp_count; ++p) {
            ATj[start_index + p] = i;
        }
        w[i] = start_index + temp_count;
    }
}
