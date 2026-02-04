#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE (512 * 1024)  // 512 KB of data

static unsigned char min_data[DATA_SIZE];
static unsigned char max_data[DATA_SIZE];

unsigned char *min = min_data;
unsigned char *max = max_data;
int length = DATA_SIZE;
int i;

void init_vars() {
    // Initialize arrays to be identical for most of the range to ensure loop runs through large portion
    memset(min_data, 0xAA, DATA_SIZE);
    memset(max_data, 0xAA, DATA_SIZE);

    // Introduce a difference at the end to prevent infinite loop and ensure termination
    if (DATA_SIZE > 0) {
        min_data[DATA_SIZE - 1] = 0xBB;
        // Ensure length is within bounds
        length = DATA_SIZE;
    }
}