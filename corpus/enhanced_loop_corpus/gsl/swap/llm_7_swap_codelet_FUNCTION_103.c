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
        int segment_start = Ap[i];
        int segment_end = Ap[i + 1];
        int count = 0;
        for (p = segment_start; p < segment_end; ++p) {
            count++;
        }
        size_t k = w[Aj[segment_start]]++;
        ATj[k] = i;
        w[Aj[segment_start]] += (count - 1);
    }
}
