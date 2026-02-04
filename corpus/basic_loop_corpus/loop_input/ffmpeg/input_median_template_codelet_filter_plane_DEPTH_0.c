#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int src_linesize;
int width;
int jobnr;
int radiusV;
uint16_t *srcp;

static uint16_t *srcp_buffer = NULL;

void init_vars() {
    // Set reasonable values to control loop iterations and memory usage
    width = 1920;          // Typical image width
    radiusV = 5;           // Small radius
    jobnr = 1;             // Ensures conditional part (jobnr != 0) is true
    src_linesize = width;  // Assume no padding for simplicity

    // Total number of rows accessed in the loop:
    // i from 0 to radiusV + (jobnr != 0)*(1 + radiusV)
    // => radiusV + 1 + radiusV = 2*radiusV + 1 when jobnr != 0
    int total_rows = radiusV + (jobnr != 0) * (1 + radiusV); // = 5 + 1*(1+5) = 11

    // Total data size: total_rows * width * sizeof(uint16_t)
    // ~ 11 * 1920 * 2 = ~42,240 bytes (well under 1MB, but safe and fast)
    size_t buffer_size = (size_t)total_rows * src_linesize;

    srcp_buffer = (uint16_t*)calloc(buffer_size, sizeof(uint16_t));
    if (!srcp_buffer) {
        // If allocation fails, fallback to minimal valid state
        srcp = (uint16_t*)0x1;
        return;
    }

    srcp = srcp_buffer;
}

// Cleanup function to avoid memory leaks (not called here but good practice)
// Not required by problem statement