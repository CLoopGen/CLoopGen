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
    // Variant 2: Strided memory access with reverse traversal
    int stride = 2;
    int j;
    for (j = 0; j < nthr; j++) {
        int idx = (nthr - 1 - j) % nthr; // Reverse index
        spawn_data *d = &sdata[idx];
        d->min = (idx * block_size * stride); // Strided min
        d->max = d->min + block_size * stride;
        if (d->max > loopmax)
            d->max = loopmax;
        d->thr_num = idx;
        d->data = (char*)data + d->min; // Data pointer follows strided access
    }
}
