#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned short UINT16;
typedef UINT16 histcell;
typedef histcell *histptr;
typedef unsigned int JDIMENSION;

JSAMPARRAY input_buf;
int num_rows;
JSAMPROW ptr;
histptr histp;
int row;
JDIMENSION col;
JDIMENSION width;

#define DATA_SIZE (64 << 20) // ~64 MB of input data for ~0.01 sec runtime

static JSAMPLE *sample_data;
static histcell *hist_data;
static JSAMPROW *row_pointers;

void init_vars() {
    const int pixel_size = 3; // 3 components per pixel (implied by ptr += 3)
    
    width = 1024; // Choose a reasonable width
    num_rows = DATA_SIZE / (width * pixel_size);
    if (num_rows == 0) num_rows = 1;
    
    // Allocate sample data: num_rows * width * 3 bytes
    sample_data = (JSAMPLE*)calloc(num_rows * width * 3, sizeof(JSAMPLE));
    if (!sample_data) exit(1);
    
    // Allocate histogram: at least as many entries as unique byte values (256)
    // But we're doing ++(*histp) in inner loop, so must be large enough to avoid overflow issues
    // Since each pixel updates one histogram cell, and we have up to 256 possible byte values
    hist_data = (histcell*)calloc(256, sizeof(histcell));
    if (!hist_data) exit(1);
    
    // Allocate row pointers
    row_pointers = (JSAMPROW*)malloc(num_rows * sizeof(JSAMPROW));
    if (!row_pointers) exit(1);
    
    // Initialize row pointers to point into sample_data
    for (int i = 0; i < num_rows; i++) {
        row_pointers[i] = &sample_data[i * width * 3];
    }
    
    // Assign external variables
    input_buf = row_pointers;
    histp = hist_data; // Each thread/pixel will update based on value? context implies shared histp
    ptr = NULL;
    row = 0;
    col = 0;
}