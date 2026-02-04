#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int i;
int dc0;
int dc1;
int dc2;
int dc3;
int dc4;
uint16_t *src;

void init_vars() {
    // Allocate a sufficiently large buffer to ensure meaningful execution time (~1-4 million elements)
    const size_t total_elements = 1 << 20;  // 1M elements of uint16_t -> 2MB
    src = (uint16_t*)calloc(total_elements, sizeof(uint16_t));
    if (!src) exit(1);

    // Set stride so that all array accesses in the loop stay within bounds
    // Maximum index accessed: -1 + (i + 12)*stride where i=3 => -1 + 15*stride
    // Need: -1 + 15*stride < total_elements
    // So: stride <= (total_elements + 1) / 15
    stride = (total_elements + 1) / 15;

    // Ensure minimum stride to avoid negative indexing issues
    if (stride < 1) stride = 1;

    // Initialize accumulators
    dc0 = 0;
    dc1 = 0;
    dc2 = 0;
    dc3 = 0;
    dc4 = 0;

    // Ensure that negative indices (-1 and -stride) are safe
    // We need at least max(1, stride) padding at the beginning
    ptrdiff_t padding = (stride > 1) ? stride : 1;
    uint16_t *padded_src = (uint16_t*)realloc(src, (total_elements + padding) * sizeof(uint16_t));
    if (!padded_src) exit(1);
    src = padded_src + padding;  // shift pointer forward by 'padding' so that index -stride is valid

    // Now adjust base so that negative indices are safe
    // After shifting, src[-padding..-1] is accessible and zero-initialized by calloc
}