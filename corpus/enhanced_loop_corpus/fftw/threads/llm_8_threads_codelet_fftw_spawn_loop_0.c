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
    for (i = 0; i < nthr; ++i) {
        spawn_data *d = &sdata[i];
        int base = i * block_size;
        d->min = base;
        d->max = base + block_size;
        if (d->max > loopmax) {
            d->max = loopmax;
        }
        d->thr_num = i;
        d->data = data;
        // Additional arithmetic to increase computational intensity
        int offset = (base * 2 + d->max) / (d->thr_num + 1);
        d->min += offset % block_size;
    }
}
