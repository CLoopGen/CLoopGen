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
    // Increase trip count by unrolling the original logic twice with adjusted bounds
    int num_tasks = nthr * 2;  // Double the number of iterations
    for (i = 0; i < num_tasks; ++i) {
        int thr_id = i / 2;  // Map two virtual tasks to one actual thread
        spawn_data *d = &sdata[thr_id];
        int local_block = block_size;

        // Alternate task modifies effective block size to simulate varied work
        if (i % 2 == 1) {
            local_block = (block_size + 1) / 2;  // Smaller chunk for second task
            d->min = d->max;  // Continue from previous max
        } else {
            d->min = thr_id * block_size;
        }

        d->max = d->min + local_block;
        if (d->max > loopmax)
            d->max = loopmax;
        d->thr_num = thr_id;
        d->data = data;

        // Ensure no invalid ranges
        if (d->min >= loopmax) {
            d->min = d->max = 0;  // Mark as inactive
        }
    }
}
