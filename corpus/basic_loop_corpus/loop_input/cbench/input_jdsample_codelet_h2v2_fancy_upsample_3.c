#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int JDIMENSION;
typedef int boolean;
typedef unsigned short UINT16;
typedef unsigned char JSAMPLE;

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

typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;

jpeg_component_info *compptr;
JSAMPARRAY input_data;
JSAMPARRAY output_data;
JSAMPROW inptr0;
JSAMPROW inptr1;
JSAMPROW outptr;
int thiscolsum;
int lastcolsum;
int nextcolsum;
JDIMENSION colctr;
int inrow;
int outrow;
int v;

static JSAMPLE *input_buffer;
static JSAMPLE *output_buffer;
static jpeg_component_info comp_info;
static JQUANT_TBL quant_table;

void init_vars() {
    const JDIMENSION width = 2048;
    const JDIMENSION height = 2048;
    
    size_t input_size = width * (height + 2);
    size_t output_size = width * height * 2;
    
    input_buffer = (JSAMPLE*)calloc(input_size, sizeof(JSAMPLE));
    output_buffer = (JSAMPLE*)calloc(output_size, sizeof(JSAMPLE));
    
    if (!input_buffer || !output_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    for (size_t i = 0; i < input_size; i++) {
        input_buffer[i] = (JSAMPLE)(i % 251);
    }
    
    input_data = (JSAMPARRAY)calloc(height + 2, sizeof(JSAMPROW));
    output_data = (JSAMPARRAY)calloc(height, sizeof(JSAMPROW));
    
    if (!input_data || !output_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    for (JDIMENSION i = 0; i < height + 2; i++) {
        input_data[i] = &input_buffer[i * width];
    }
    
    for (JDIMENSION i = 0; i < height; i++) {
        output_data[i] = &output_buffer[i * width * 2];
    }
    
    memset(&comp_info, 0, sizeof(comp_info));
    comp_info.downsampled_width = width;
    comp_info.downsampled_height = height;
    comp_info.component_needed = 1;
    comp_info.DCT_scaled_size = 8;
    comp_info.MCU_sample_width = width;
    comp_info.last_col_width = 1;
    comp_info.last_row_height = 1;
    comp_info.quant_table = &quant_table;
    
    compptr = &comp_info;
    
    inptr0 = NULL;
    inptr1 = NULL;
    outptr = NULL;
    thiscolsum = 0;
    lastcolsum = 0;
    nextcolsum = 0;
    colctr = 0;
    inrow = 1;
    outrow = 0;
    v = 0;
    
    memset(&quant_table, 0, sizeof(quant_table));
    for (int i = 0; i < 64; i++) {
        quant_table.quantval[i] = (UINT16)(i + 1);
    }
}