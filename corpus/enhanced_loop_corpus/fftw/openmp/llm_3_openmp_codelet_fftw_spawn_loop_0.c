#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int min;
    int max;
    int thr_num;
    void *data;
} spawn_data;

extern int loopmax;
extern int nthr;
extern void *data;
extern int block_size;
extern int i;
extern spawn_data *sdata;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern - process every second element forward, then fill in the gaps (interleaved access)
    int stride = 2;
    // First pass: even indices
    for (i = 0; i < nthr; i += stride) {
        spawn_data *d = &sdata[i];
        d->min = i * block_size;
        d->max = d->min + block_size;
        if (d->max > loopmax)
            d->max = loopmax;
        d->thr_num = i;
        d->data = data;
    }
    // Second pass: odd indices
    for (i = 1; i < nthr; i += stride) {
        spawn_data *d = &sdata[i];
        d->min = i * block_size;
        d->max = d->min + block_size;
        if (d->max > loopmax)
            d->max = loopmax;
        d->thr_num = i;
        d->data = data;
    }
}
