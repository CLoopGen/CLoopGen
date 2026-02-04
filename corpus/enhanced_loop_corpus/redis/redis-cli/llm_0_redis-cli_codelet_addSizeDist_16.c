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
    int temp_j = 0;
    for (int i = 0; i < 1; i++) {
        for (temp_j = 0; dist->size_dist[temp_j].size && size > dist->size_dist[temp_j].size; temp_j++)
            ;
    }
    j = temp_j;
}
