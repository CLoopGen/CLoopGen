#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <inttypes.h>

typedef unsigned int JDIMENSION;
typedef int boolean;
typedef unsigned short UINT16;
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;

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

static JSAMPLE *input_buffer = NULL;
static JSAMPLE *output_buffer = NULL;
static jpeg_component_info comp_info;
static JQUANT_TBL quant_table;

void init_vars() {
    const int total_input_rows = 8192;
    const int row_width = 1024;
    
    output_cols = row_width;
    
    input_buffer = (JSAMPLE*)calloc(total_input_rows * row_width, sizeof(JSAMPLE));
    output_buffer = (JSAMPLE*)calloc(total_input_rows * row_width, sizeof(JSAMPLE));
    
    if (!input_buffer || !output_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    for (int i = 0; i < total_input_rows * row_width; i++) {
        input_buffer[i] = (JSAMPLE)(i % 256);
    }
    
    input_data = (JSAMPARRAY)calloc(total_input_rows, sizeof(JSAMPROW));
    output_data = (JSAMPARRAY)calloc(total_input_rows, sizeof(JSAMPROW));
    
    for (int i = 0; i < total_input_rows; i++) {
        input_data[i] = &input_buffer[i * row_width];
        output_data[i] = &output_buffer[i * row_width];
    }
    
    comp_info.v_samp_factor = 4096;
    comp_info.h_samp_factor = 1;
    comp_info.downsampled_width = row_width;
    comp_info.width_in_blocks = row_width / 8;
    comp_info.height_in_blocks = total_input_rows / 8;
    comp_info.DCT_scaled_size = 8;
    comp_info.MCU_width = 8;
    comp_info.MCU_height = 8;
    comp_info.MCU_blocks = 1;
    comp_info.MCU_sample_width = 8;
    comp_info.last_col_width = 8;
    comp_info.last_row_height = 8;
    comp_info.component_needed = 1;
    comp_info.quant_tbl_no = 0;
    comp_info.dc_tbl_no = 0;
    comp_info.ac_tbl_no = 0;
    comp_info.component_id = 1;
    comp_info.component_index = 0;
    
    memset(&quant_table, 0, sizeof(quant_table));
    quant_table.sent_table = 0;
    for (int i = 0; i < 64; i++) {
        quant_table.quantval[i] = (UINT16)(i + 1);
    }
    
    comp_info.quant_table = &quant_table;
    comp_info.dct_table = NULL;
    
    compptr = &comp_info;
    
    inrow = 0;
}