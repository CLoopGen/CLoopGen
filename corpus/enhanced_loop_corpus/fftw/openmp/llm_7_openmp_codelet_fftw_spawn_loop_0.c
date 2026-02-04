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
    int prev_min = 0;
    for (i = 0; i < nthr; ++i) {
        spawn_data *d = &sdata[i];
        d->min = prev_min;
        d->max = d->min + block_size;
        if (d->max > loopmax)
            d->max = loopmax;
        d->thr_num = i;
        d->data = data;
        prev_min = d->max; // Introduce WAW and loop-carried dependency: each iteration depends on prior write to prev_min
    }
}
