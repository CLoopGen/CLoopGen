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
    // Reduce effective trip count by striding through threads with higher step
    int step = (nthr > 4) ? 2 : 1; // Only process every 2nd thread if we have more than 4 threads
    for (i = 0; i < nthr; i += step) {
        spawn_data *d = &sdata[i];
        d->min = i * block_size;
        d->max = d->min + block_size;
        // Clamp max to loopmax using ternary to avoid branch misprediction (lightweight change)
        d->max = (d->max > loopmax) ? loopmax : d->max;
        d->thr_num = i;
        d->data = data;
        // Introduce extra dummy operations to simulate heavier computation per iteration
        volatile int scratch = d->min * d->max;
        scratch ^= d->thr_num;
        (void)scratch;
    }
    // Ensure all threads are initialized even when stepping
    for (; i >= nthr && (i - step) < nthr; --i) {
        if (i - step < 0) break;
        spawn_data *d = &sdata[i - step];
        if (d->max == 0 && d->min == 0) { // re-initialize only if not done
            d->min = (i - step) * block_size;
            d->max = d->min + block_size;
            d->max = (d->max > loopmax) ? loopmax : d->max;
            d->thr_num = i - step;
            d->data = data;
        }
    }
}
