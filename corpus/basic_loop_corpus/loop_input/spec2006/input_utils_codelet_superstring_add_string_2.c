#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int *num_my_stones;
int *my_stones;
int *num_stones;
int *stones;
int do_add;
int new_stones;
int k;

#define STONES_ARRAY_SIZE (1 << 20)  // 1MB of data: 262144 integers (assuming 4 bytes per int)
#define MY_STONES_ARRAY_SIZE (1 << 19) // ~512KB: 131072 integers

void init_vars() {
    // Allocate and initialize counters
    num_my_stones = (int*)calloc(1, sizeof(int));
    num_stones = (int*)calloc(1, sizeof(int));
    
    // Allocate arrays
    stones = (int*)malloc(STONES_ARRAY_SIZE * sizeof(int));
    my_stones = (int*)malloc(MY_STONES_ARRAY_SIZE * sizeof(int));
    
    // Initialize array contents
    for (int i = 0; i < MY_STONES_ARRAY_SIZE; i++) {
        my_stones[i] = i;  // Arbitrary initialization
    }
    for (int i = 0; i < STONES_ARRAY_SIZE; i++) {
        stones[i] = -1;  // Sentinel value
    }

    // Set control variables
    do_add = 1;  // Enable the addition path
    new_stones = MY_STONES_ARRAY_SIZE / 2;  // Ensure we don't exceed bounds

    // Initialize counters to valid values within array bounds
    *num_my_stones = MY_STONES_ARRAY_SIZE - new_stones;  // Ensure index + k is valid
    *num_stones = 0;  // Start from beginning
}