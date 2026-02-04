#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int *dig;
int *chr;
int length;
int j;
int tenl;
int newv;
int old;

void init_vars() {
    // Set data size to achieve approximately 0.01 seconds runtime
    // Based on typical performance, ~64M iterations gives around 0.01s on modern CPUs
    length = 64 * 1024 * 1024 / sizeof(int);  // Scale to about 64M elements
    
    // Ensure j starts at valid index: loop runs from length-1 down to 1
    if (length < 2) {
        length = 2;  // Minimum length for loop to execute at least one iteration
    }

    // Allocate arrays
    dig = (int*)aligned_alloc(32, length * sizeof(int));
    chr = (int*)malloc(sizeof(int));

    // Initialize array contents
    for (int i = 0; i < length; i++) {
        dig[i] = i % 10;  // Small values 0-9 to mimic digit-like behavior
    }

    // Initialize scalar variables
    j = length - 1;
    tenl = 7;           // Arbitrary non-zero value
    old = 100;          // Initial value for recurrence
    newv = 0;
    
    // Initialize chr to a large value so that updates are likely
    *chr = 1000000;
}