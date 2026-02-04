#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

int *num_libs;
int *libs;
int maxlibs;
int liberty_cap;
char ml[400];
int do_add;
int num_my_libs;
int my_libs[241];
int k;

void init_vars() {
    // Allocate and initialize num_libs
    num_libs = (int*)calloc(1, sizeof(int));
    *num_libs = 0;

    // Set maxlibs to a reasonable size (~64MB of int data)
    maxlibs = 16777216; // ~64MB / sizeof(int) = ~16.7M elements
    libs = (int*)malloc(maxlibs * sizeof(int));
    if (!libs) {
        fprintf(stderr, "Failed to allocate libs\n");
        exit(1);
    }

    // Initialize control variables
    liberty_cap = 300;      // Allow up to 300 libraries in the add condition
    do_add = 1;             // Enable adding
    num_my_libs = 240;      // Safe: within declared array size (241)

    // Initialize my_libs with values in valid range for ml[400] indexing
    for (int i = 0; i < num_my_libs; i++) {
        my_libs[i] = (i * 17) % 400;  // Spread across 0-399
    }

    // Clear ml array
    memset(ml, 0, sizeof(ml));

    // Initialize k
    k = 0;
}