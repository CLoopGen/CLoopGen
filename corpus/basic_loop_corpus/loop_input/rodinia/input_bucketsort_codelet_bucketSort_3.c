#include <stdlib.h>
#include <stdint.h>

unsigned int *h_offsets;
int *sizes;
int *nullElements;

void init_vars() {
    const size_t N = 1 << 10; // 1024 elements as per loop bound

    h_offsets = (unsigned int*)calloc(N, sizeof(unsigned int));
    sizes = (int*)calloc(N, sizeof(int));
    nullElements = (int*)calloc(N, sizeof(int));

    for (size_t i = 0; i < N; i++) {
        h_offsets[i] = (unsigned int)(i * 37); // arbitrary initialization
        nullElements[i] = (int)(i * 13);      // arbitrary initialization
    }
}