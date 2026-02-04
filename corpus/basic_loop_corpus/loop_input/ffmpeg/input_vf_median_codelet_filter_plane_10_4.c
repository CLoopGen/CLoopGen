#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int src_linesize;
int width;
int jobnr;
uint16_t *ccoarse;
uint16_t *cfine;
int radiusV;
uint16_t *srcp;

static uint16_t *ccoarse_data;
static uint16_t *cfine_data;
static uint16_t *srcp_data;

void init_vars() {
    // Set parameters to control data sizes and loop bounds
    width = 1024;
    radiusV = 5;
    jobnr = 1;  // ensures the loop runs radiusV + 1 + radiusV = 11 iterations

    src_linesize = width;  // stride in elements per row

    // Allocate source data: we'll have (radiusV + (jobnr != 0) * (1 + radiusV)) rows
    int src_rows = radiusV + (jobnr != 0) * (1 + radiusV);  // evaluates to 5 + 1*(1+5) = 11
    size_t src_size = src_rows * src_linesize;

    srcp_data = (uint16_t*)calloc(src_size, sizeof(uint16_t));
    if (!srcp_data) exit(1);

    // Each element in srcp is used as an index component. We must ensure that:
    //   (srcp[j] >> shift) < some bound, and (srcp[j] & mask) is within range.
    // Let shift = (10 + 1) / 2 = 5, so mask = (1 << 5) - 1 = 31.
    // So each srcp[j] must be less than 1 << 10? Actually, only the top 5 bits and bottom 5 bits are used.

    // Initialize srcp_data with values such that indexing into cfine and ccoarse stays in bounds.
    for (size_t i = 0; i < src_size; i++) {
        srcp_data[i] = rand() & 0x3FF;  // 10-bit values: safe for shift=5 and mask=31
    }

    // Define constants based on code logic
    int shift = (10 + 1) / 2;  // 5
    int coarse_stride = width;
    int coarse_size = coarse_stride * (1 << shift);  // width * 32
    ccoarse_data = (uint16_t*)calloc(coarse_size, sizeof(uint16_t));
    if (!ccoarse_data) exit(1);

    int fine_stride = width;
    int fine_scale = (1 << shift);  // 32
    // Index: fine_scale * (width * ((srcp[j] >> shift) + j) + (srcp[j] & mask))
    // Maximum j: width - 1
    // Maximum (srcp[j] >> shift): 31
    // So max index: 32 * (width * 31 + width - 1) + 31
    //             = 32 * (width * 32 - 1) + 31
    //             ≈ 32 * 32 * width = 1024 * width
    int max_fine_index = fine_scale * (width * ((1 << shift) - 1 + width - 1)) + ((1 << shift) - 1);
    int total_fine_size = max_fine_index + 1;

    cfine_data = (uint16_t*)calloc(total_fine_size, sizeof(uint16_t));
    if (!cfine_data) exit(1);

    // Assign pointers
    srcp = srcp_data;
    ccoarse = ccoarse_data;
    cfine = cfine_data;
}

// Declarations of externs (definitions above)
extern int src_linesize;
extern int width;
extern int jobnr;
extern uint16_t *ccoarse;
extern uint16_t *cfine;
extern int radiusV;
extern uint16_t *srcp;