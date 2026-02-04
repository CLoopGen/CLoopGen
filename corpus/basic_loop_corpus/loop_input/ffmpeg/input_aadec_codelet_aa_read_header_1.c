#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

struct toc_entry {
    uint32_t offset;
    uint32_t size;
};

int i;
int largest_idx;
uint32_t toc_size;
int64_t largest_size;
int64_t current_size;
struct toc_entry TOC[16];

void init_vars() {
    toc_size = 16;
    largest_idx = 0;
    largest_size = 0;
    i = 0;

    for (int idx = 0; idx < 16; idx++) {
        TOC[idx].offset = idx * 65536;
        TOC[idx].size = rand() % 1000000;
    }

    current_size = 0;

    if (toc_size > 0) {
        largest_size = TOC[0].size;
        for (int j = 1; j < toc_size; j++) {
            if (TOC[j].size > largest_size) {
                largest_size = TOC[j].size;
                largest_idx = j;
            }
        }
    }
}