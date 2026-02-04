#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct size_dist_entry {
    unsigned long long size;
    unsigned long long count;
} size_dist_entry;

typedef struct size_dist {
    unsigned long long total_count;
    unsigned long long total_size;
    unsigned long long max_size;
    size_dist_entry *size_dist;
} size_dist;

extern size_dist *dist;
extern unsigned long long size;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access with prefetching and unrolling (unroll factor 2)
    int idx = 0;
    for (; ; idx += 2) {
        unsigned long long size0 = dist->size_dist[idx].size;
        unsigned long long size1 = dist->size_dist[idx + 1].size;

        if (size0 == 0 || size > size0) {
            j = idx;
            if (size1 == 0 || size > size1) {
                j = idx + 1;
            } else {
                break;
            }
        } else {
            break;
        }
    }
    // Final adjustment to match original loop exit condition
    while (dist->size_dist[j].size && size > dist->size_dist[j].size) {
        j++;
    }
}
