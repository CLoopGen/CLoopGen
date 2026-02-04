#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char Intersection;

Intersection board[421];
int string_number[400];
int str2 = 100;
int maxlib = 100;
int *libs;
int *libs1;
int liberties1 = 50;
int commonlibs = 0;
int k;

void init_vars() {
    // Allocate and initialize board with valid data
    for (int i = 0; i < 421; i++) {
        board[i] = (i % 3) ? 1 : 2;
    }

    // Initialize string_number array
    for (int i = 0; i < 400; i++) {
        string_number[i] = i % 50;
    }

    // Set str2 within valid range
    str2 = 199;

    // Allocate large enough arrays to meet performance target (~0.01s runtime)
    // We'll make libs and libs1 point to large buffers to ensure measurable runtime
    libs = (int*)malloc(64 * 1024 * sizeof(int));
    libs1 = (int*)malloc(64 * 1024 * sizeof(int));

    // Initialize libs1 with values that won't cause out-of-bounds access
    // Ensure all (libs1[k] ± 1, ±20) are within [0,420] for board indexing
    liberties1 = 50000;  // Increase iteration count for timing
    maxlib = 50000;
    commonlibs = 0;

    for (int i = 0; i < liberties1; i++) {
        // Choose positions safely away from edges: between 20 and 399
        libs1[i] = 20 + (i % 380);
    }

    // Pre-initialize libs to avoid undefined behavior
    for (int i = 0; i < 64 * 1024; i++) {
        libs[i] = -1;
    }
}