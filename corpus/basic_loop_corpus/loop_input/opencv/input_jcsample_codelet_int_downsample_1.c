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
int inrow;
int outrow;
int h_expand;
int v_expand;
int numpix;
int numpix2;
int h;
int v;
JDIMENSION outcol;
JDIMENSION outcol_h;
JDIMENSION output_cols;
JSAMPROW inptr;
JSAMPROW outptr;
JLONG outvalue;

static JSAMPLE *input_buffer;
static JSAMPLE *output_buffer;
static jpeg_component_info comp_info;
static JQUANT_TBL quant_table;

void init_vars() {
    // Set parameters to achieve ~100ms runtime
    // Target: about 64MB of input data
    const int total_input_rows = 2048;
    const int block_width = 2048;
    
    h_expand = 2;
    v_expand = 2;
    numpix = h_expand * v_expand;  // 4
    numpix2 = numpix / 2;           // 2

    comp_info.v_samp_factor = 16;
    comp_info.h_samp_factor = 16;
    output_cols = block_width;
    compptr = &comp_info;

    // Total MCU rows we'll process per component
    int total_output_rows = total_input_rows * comp_info.v_samp_factor / v_expand;
    input_data = (JSAMPARRAY)malloc(total_input_rows * sizeof(JSAMPROW));
    output_data = (JSAMPARRAY)malloc(total_output_rows * sizeof(JSAMPROW));

    size_t input_size = total_input_rows * block_width * sizeof(JSAMPLE);
    size_t output_size = total_output_rows * block_width * sizeof(JSAMPLE);
    input_buffer = (JSAMPLE*)malloc(input_size);
    output_buffer = (JSAMPLE*)malloc(output_size);

    for (int i = 0; i < total_input_rows; i++) {
        input_data[i] = input_buffer + i * block_width;
    }
    for (int i = 0; i < total_output_rows; i++) {
        output_data[i] = output_buffer + i * block_width;
    }

    comp_info.width_in_blocks = block_width / 8;
    comp_info.height_in_blocks = total_input_rows / 8;
    comp_info.downsampled_width = block_width;
    comp_info.downsampled_height = total_input_rows;
    comp_info.DCT_scaled_size = 8;
    comp_info.MCU_width = comp_info.h_samp_factor;
    comp_info.MCU_height = comp_info.v_samp_factor;
    comp_info.MCU_blocks = comp_info.h_samp_factor * comp_info.v_samp_factor;
    comp_info.MCU_sample_width = comp_info.h_samp_factor * 8;
    comp_info.last_col_width = 8;
    comp_info.last_row_height = 8;
    comp_info.component_needed = 1;
    comp_info.quant_table = &quant_table;
    comp_info.dct_table = NULL;

    // Initialize quant table
    for (int i = 0; i < 64; i++) {
        quant_table.quantval[i] = 16;
    }
    quant_table.sent_table = 0;

    // Initialize input data with non-zero values
    for (size_t i = 0; i < input_size; i++) {
        input_buffer[i] = (JSAMPLE)(i % 251);
    }

    // Zero output buffer
    for (size_t i = 0; i < output_size; i++) {
        output_buffer[i] = 0;
    }

    // Initial state
    inrow = 0;
}