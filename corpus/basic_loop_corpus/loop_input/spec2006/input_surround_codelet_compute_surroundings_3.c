#include <stdio.h>
#include <inttypes.h>

int n;
int left_corner[19] = {10};
int right_corner[19] = {28};
int top_row = 1;
char mn[400];

void init_vars() {
    for (int i = 0; i < 19; i++) {
        if (i >= 1) {
            left_corner[i] = (left_corner[i-1] * 31 + 17) % 100;
            right_corner[i] = left_corner[i] + 18;
        }
    }

    top_row = 1;

    for (int i = 0; i < 400; i++) {
        mn[i] = 0;
    }
}