#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;

JSAMPLE *sample_data_mem;
JSAMPARRAY sample_data;
JDIMENSION start_col;
float *workspaceptr;
JSAMPROW elemptr;
int elemr;

void init_vars() {
    const int total_rows = 8;
    const int row_size = 256 * 1024; // 256KB per row -> 2MB total, enough for ~0.01s
    const int workspace_size = total_rows * 8; // 8 writes per row

    // Allocate large block for sample data
    sample_data_mem = (JSAMPLE*)calloc(row_size, total_rows);
    if (!sample_data_mem) exit(1);

    // Allocate and initialize sample_data array (array of 8 pointers)
    sample_data = (JSAMPARRAY)calloc(total_rows, sizeof(JSAMPROW));
    if (!sample_data) exit(1);

    for (int i = 0; i < total_rows; i++) {
        sample_data[i] = &sample_data_mem[i * row_size];
        // Initialize with non-zero pattern to avoid all-zero effects
        for (int j = 0; j < row_size; j++) {
            sample_data[i][j] = (JSAMPLE)((i * 31 + j * 7) % 256);
        }
    }

    // Set start_col such that we can safely read 8 elements after it
    start_col = 100;

    // Allocate workspace
    workspaceptr = (float*)calloc(workspace_size, sizeof(float));
    if (!workspaceptr) exit(1);
}