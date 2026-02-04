#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;
typedef long INT32;

JSAMPARRAY output_buf;
JDIMENSION output_col;
INT32 tmp0;
INT32 tmp2;
INT32 tmp10;
INT32 tmp12;
INT32 z1;
INT32 z2;
INT32 z3;
int *wsptr;
JSAMPROW outptr;
JSAMPLE *range_limit;
int ctr;

static JSAMPLE *sample_buffer;
static int *workspace;

void init_vars() {
    const int data_size = 16 * 1024 * 1024; // ~16MB of workspace
    const int num_rows = 8;
    const int row_width = 1024;
    const int range_limit_size = (128 << 2) * 2;

    // Allocate range_limit: used with mask ((128<<2)*2 - 1)
    range_limit = (JSAMPLE*)calloc(range_limit_size, sizeof(JSAMPLE));
    for (int i = 0; i < range_limit_size; i++) {
        range_limit[i] = (JSAMPLE)((i & 0xFF) * 0x01); // arbitrary valid mapping
    }

    // Allocate output buffer: 8 rows, each of size row_width
    output_buf = (JSAMPARRAY)calloc(num_rows, sizeof(JSAMPROW));
    sample_buffer = (JSAMPLE*)calloc(num_rows * row_width, sizeof(JSAMPLE));
    for (int i = 0; i < num_rows; i++) {
        output_buf[i] = &sample_buffer[i * row_width];
    }

    // Set output column within bounds
    output_col = row_width / 2; // ensure there's space for +3 offset

    // Allocate workspace: large enough for 8 iterations × 4 ints each
    workspace = (int*)calloc(data_size, sizeof(int));
    wsptr = workspace;

    // Initialize workspace data to prevent undefined behavior
    for (int i = 0; i < data_size; i++) {
        workspace[i] = (i % 256) - 128;
    }

    // Initialize temporary variables to avoid undefined use
    tmp0 = tmp2 = tmp10 = tmp12 = z1 = z2 = z3 = 0;
    outptr = output_buf[0];
    ctr = 0;
}