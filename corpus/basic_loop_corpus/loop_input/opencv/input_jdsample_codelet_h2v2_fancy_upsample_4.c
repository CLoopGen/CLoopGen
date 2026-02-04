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
typedef long JLONG;

jpeg_component_info *compptr;
JSAMPARRAY input_data;
JSAMPARRAY output_data;
JSAMPROW inptr0;
JSAMPROW inptr1;
JSAMPROW outptr;
JLONG thiscolsum;
JLONG lastcolsum;
JLONG nextcolsum;
JDIMENSION colctr;
int inrow;
int outrow;
int v;

static JSAMPLE *input_buffer;
static JSAMPLE *output_buffer;
static jpeg_component_info comp_info;
static JQUANT_TBL quant_table;

void init_vars() {
    const size_t total_input_size = 128 * 1024 * 1024; // ~128MB for sufficient workload
    const JDIMENSION width = 8192;
    const JDIMENSION height = 8192;
    
    input_buffer = (JSAMPLE*)calloc(total_input_size, sizeof(JSAMPLE));
    output_buffer = (JSAMPLE*)calloc(total_input_size * 2, sizeof(JSAMPLE)); // output is larger due to processing

    if (!input_buffer || !output_buffer) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    // Initialize quant table
    quant_table.sent_table = 0;
    for (int i = 0; i < 64; i++) {
        quant_table.quantval[i] = (UINT16)(i + 1);
    }

    // Initialize component info
    comp_info.component_id = 1;
    comp_info.component_index = 0;
    comp_info.h_samp_factor = 1;
    comp_info.v_samp_factor = 1;
    comp_info.quant_tbl_no = 0;
    comp_info.dc_tbl_no = 0;
    comp_info.ac_tbl_no = 0;
    comp_info.width_in_blocks = width / 8;
    comp_info.height_in_blocks = height / 8;
    comp_info.DCT_scaled_size = 8;
    comp_info.downsampled_width = width;
    comp_info.downsampled_height = height;
    comp_info.component_needed = 1;
    comp_info.MCU_width = 8;
    comp_info.MCU_height = 8;
    comp_info.MCU_blocks = 1;
    comp_info.MCU_sample_width = 8;
    comp_info.last_col_width = 8;
    comp_info.last_row_height = 8;
    comp_info.quant_table = &quant_table;
    comp_info.dct_table = NULL;

    compptr = &comp_info;

    // Setup input and output data arrays
    input_data = (JSAMPARRAY)calloc(height + 2, sizeof(JSAMPROW));
    output_data = (JSAMPARRAY)calloc(height, sizeof(JSAMPROW));

    if (!input_data || !output_data) {
        fprintf(stderr, "Failed to allocate array pointers\n");
        exit(1);
    }

    // Initialize row pointers with padding for boundary access
    for (int i = 0; i < height + 2; i++) {
        input_data[i] = input_buffer + i * width;
    }

    for (int i = 0; i < height; i++) {
        output_data[i] = output_buffer + i * width * 2; // conservative estimate of output stride
    }

    // Initialize other loop variables
    inrow = 1;  // ensure inrow-1 is valid
    outrow = 0;
    v = 0;
    thiscolsum = 0;
    lastcolsum = 0;
    nextcolsum = 0;
    colctr = 0;

    // Ensure input has some data to process
    for (size_t i = 0; i < total_input_size; i++) {
        input_buffer[i] = (JSAMPLE)(i % 251);
    }
}