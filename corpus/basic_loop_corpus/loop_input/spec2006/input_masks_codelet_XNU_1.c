#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

int xpam120[23][23];
char *dsq;
int len;
int i;
int k;
int off;
int sum;
int beg;
int end;
int top;
int topcut;
int fallcut;
int noff;
int mcut;
int *hit;

void init_vars() {
    // Initialize xpam120 with small integer values to simulate a PAM scoring matrix
    for (int row = 0; row < 23; ++row) {
        for (int col = 0; col < 23; ++col) {
            xpam120[row][col] = (row == col) ? 2 : -1;
        }
    }

    // Set sequence length to ~1MB to ensure loop runtime around 0.01s on modern CPU
    len = 1 << 20;  // 1,048,576 elements

    dsq = (char*)calloc(len + 1, sizeof(char));
    if (!dsq) exit(1);
    // Fill dsq with valid indices in range [0,22] to match xpam120 indexing
    for (int idx = 0; idx < len; ++idx) {
        dsq[idx] = rand() % 23;
    }

    // Allocate hit array with extra padding to prevent out-of-bounds access
    // Maximum index accessed: k and k-off, where k <= len, so need up to len + max_off
    int max_off = 1000;  // Conservative estimate for noff
    hit = (int*)calloc(len + max_off + 1, sizeof(int));
    if (!hit) exit(1);

    // Set loop control parameters
    mcut = 1;
    noff = 500;  // Must be <= 500 to avoid accessing dsq[i-off] out of bounds
    topcut = 20;
    fallcut = 10;

    // Initialize scalar loop variables to zero (will be set in loop anyway)
    off = i = k = sum = beg = end = top = 0;
}