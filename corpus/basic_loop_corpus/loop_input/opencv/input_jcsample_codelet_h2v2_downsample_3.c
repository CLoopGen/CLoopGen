#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned int JDIMENSION;
typedef int boolean;
typedef unsigned short UINT16;

typedef struct {
    UINT16 quantval[64];
    boolean sent_table;
} JQUANT_TBL;

typedef struct {
    int component_id;
    int component_index;
    int h_samp_factor;
    int v_samp_factor;
    int quant_tbl_no;
    int dc_tbl_no;
    int ac_tbl_no;
    JDIMENSION width_in_blocks;
    JDIMENSION height_in_blocks;
    int DCT_scaled_size;
    JDIMENSION downsampled_width;
    JDIMENSION downsampled_height;
    boolean component_needed;
    int MCU_width;
    int MCU_height;
    int MCU_blocks;
    int MCU_sample_width;
    int last_col_width;
    int last_row_height;
    JQUANT_TBL *quant_table;
    void *dct_table;
} jpeg_component_info;

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;

jpeg_component_info *compptr;
JSAMPARRAY input_data;
JSAMPARRAY output_data;
int inrow;
int outrow;
JDIMENSION outcol;
JDIMENSION output_cols;
JSAMPROW inptr0;
JSAMPROW inptr1;
JSAMPROW outptr;
int bias;

static JSAMPLE *input_buffer;
static JSAMPLE *output_buffer;
static jpeg_component_info comp_info;
static JQUANT_TBL quant_table;

void init_vars() {
    const int buffer_size = 16777216; // ~16MB of total input data for ~0.01s runtime estimate
    const int rows = 4096;
    const int cols = 4096;
    
    input_buffer = (JSAMPLE*)calloc(buffer_size, sizeof(JSAMPLE));
    output_buffer = (JSAMPLE*)calloc(buffer_size, sizeof(JSAMPLE));
    
    if (!input_buffer || !output_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    input_data = (JSAMPROW*)calloc(rows, sizeof(JSAMPROW));
    output_data = (JSAMPROW*)calloc(rows, sizeof(JSAMPROW));
    
    if (!input_data || !output_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    for (int i = 0; i < rows; i++) {
        input_data[i] = &input_buffer[i * cols];
        output_data[i] = &output_buffer[i * cols];
    }
    
    compptr = &comp_info;
    compptr->v_samp_factor = 2;
    compptr->h_samp_factor = 2;
    compptr->downsampled_width = cols;
    compptr->width_in_blocks = cols / 8;
    compptr->height_in_blocks = rows / 8;
    compptr->DCT_scaled_size = 8;
    compptr->MCU_width = 8;
    compptr->MCU_height = 8;
    compptr->MCU_blocks = 1;
    compptr->MCU_sample_width = 8;
    compptr->last_col_width = 1;
    compptr->last_row_height = 1;
    compptr->component_needed = 1;
    compptr->quant_table = &quant_table;
    compptr->dct_table = NULL;
    
    output_cols = cols / 2;
    inrow = 0;
    
    for (int i = 0; i < 64; i++) {
        quant_table.quantval[i] = 1;
    }
    quant_table.sent_table = 0;
    
    for (int i = 0; i < buffer_size; i++) {
        input_buffer[i] = (JSAMPLE)(i % 256);
    }
}