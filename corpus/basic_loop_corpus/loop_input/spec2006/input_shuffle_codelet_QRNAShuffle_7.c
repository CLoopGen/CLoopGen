#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *x;
char *y;
int L;
int *xycol;
int *xcol;
int *ycol;
int nxy;
int nx;
int ny;
int i;

void init_vars() {
    // Set data size to achieve ~0.01 seconds runtime on modern CPU
    // Empirical testing suggests ~64M iterations provides appropriate timing
    L = 64 * 1024 * 1024; // 64 million elements

    // Allocate memory for x and y arrays
    x = (char*)malloc(L * sizeof(char));
    y = (char*)malloc(L * sizeof(char));

    // Allocate output index arrays (worst-case size: all indices could be stored)
    xycol = (int*)malloc(L * sizeof(int));
    xcol = (int*)malloc(L * sizeof(int));
    ycol = (int*)malloc(L * sizeof(int));

    // Initialize counters
    nxy = 0;
    nx = 0;
    ny = 0;
    i = 0;

    // Initialize x and y with mixed character patterns to ensure diverse branching
    // Use deterministic seed for reproducibility
    srand(12345);
    const char valid_chars[] = " ._~-";
    const char invalid_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()+=[]{}|;:,<>/?";

    for (int idx = 0; idx < L; idx++) {
        if (rand() % 4 == 0) {
            // 25% chance of valid character
            x[idx] = valid_chars[rand() % 5];
        } else {
            // 75% chance of invalid character
            x[idx] = invalid_chars[rand() % 70];
        }

        if (rand() % 4 == 0) {
            // 25% chance of valid character
            y[idx] = valid_chars[rand() % 5];
        } else {
            // 75% chance of invalid character
            y[idx] = invalid_chars[rand() % 70];
        }
    }
}