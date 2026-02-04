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

size_dist *dist;
unsigned long long size;
int j;

void init_vars() {
    const int num_entries = 1000000; // ~8MB of data (1M entries * 16 bytes per entry)

    // Allocate memory for size_dist array
    size_dist_entry *entries = (size_dist_entry *)calloc(num_entries + 1, sizeof(size_dist_entry));
    if (!entries) {
        exit(1);
    }

    // Initialize entries: strictly increasing sizes up to a maximum
    for (int i = 0; i < num_entries; i++) {
        entries[i].size = (i + 1) * 1024; // Sizes in KB increments: 1KB, 2KB, ..., ~976MB
        entries[i].count = 1;
    }
    // Sentinel: last element has size 0 to terminate loop
    entries[num_entries].size = 0;
    entries[num_entries].count = 0;

    // Allocate and initialize dist structure
    dist = (size_dist *)malloc(sizeof(size_dist));
    if (!dist) {
        free(entries);
        exit(1);
    }

    dist->total_count = num_entries;
    dist->total_size = (num_entries * (num_entries + 1) / 2) * 1024;
    dist->max_size = entries[num_entries - 1].size;
    dist->size_dist = entries;

    // Set initial search size just below a midpoint to ensure non-trivial loop execution
    size = (num_entries / 2) * 1024 + 512; // Between two entries

    j = 0;
}