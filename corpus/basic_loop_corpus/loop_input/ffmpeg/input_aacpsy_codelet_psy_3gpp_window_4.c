#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct FFPsyWindowInfo {
    int window_type[3];
    int window_shape;
    int num_windows;
    int grouping[8];
    float clipping[8];
    int *window_sizes;
} FFPsyWindowInfo;

int prev_type = 1;
int i = 0;
FFPsyWindowInfo wi;

void init_vars() {
    wi.window_shape = 0;
    wi.num_windows = 1;
    for (int j = 0; j < 8; j++) {
        wi.grouping[j] = j;
        wi.clipping[j] = 0.5f + j * 0.1f;
    }
    wi.window_sizes = (int *)malloc(8 * sizeof(int));
    for (int j = 0; j < 8; j++) {
        wi.window_sizes[j] = 256 << j;
    }
}