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
    // Outer loop processes chunks of threads in groups to simulate hierarchical decomposition
    for (int gi = 0; gi < nthr; gi += block_size) {
        for (int i = gi; i < gi + block_size && i < nthr; ++i) {
            spawn_data *d = &sdata[i];
            d->min = i * block_size;
            d->max = d->min + block_size;
            if (d->max > loopmax)
                d->max = loopmax;
            d->thr_num = i;
            d->data = data;
        }
    }
}
