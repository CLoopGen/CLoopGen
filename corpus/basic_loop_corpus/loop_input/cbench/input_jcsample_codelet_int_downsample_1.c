#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef unsigned int JDIMENSION;
typedef int boolean;
typedef unsigned short UINT16;
typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef long INT32;

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
INT32 outvalue;

static JSAMPLE *input_buffer = NULL;
static JSAMPLE *output_buffer = NULL;
static jpeg_component_info comp_info;
static JQUANT_TBL quant_table;

void init_vars() {
    const int width = 2048;
    const int height = 2048;

    const size_t input_size = (size_t)width * height;
    const size_t output_size = (size_t)width * height;

    input_buffer = (JSAMPLE*)calloc(input_size, sizeof(JSAMPLE));
    output_buffer = (JSAMPLE*)calloc(output_size, sizeof(JSAMPLE));

    if (!input_buffer || !output_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < input_size; i++) {
        input_buffer[i] = (JSAMPLE)(i % 256);
    }

    input_data = (JSAMPROW*)malloc(height * sizeof(JSAMPROW));
    output_data = (JSAMPROW*)malloc(height * sizeof(JSAMPROW));

    if (!input_data || !output_data) {
        fprintf(stderr, "JSAMPARRAY allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < height; i++) {
        input_data[i] = input_buffer + i * width;
        output_data[i] = output_buffer + i * width;
    }

    comp_info.v_samp_factor = 2;
    comp_info.h_samp_factor = 2;
    comp_info.width_in_blocks = width / 8;
    comp_info.height_in_blocks = height / 8;
    comp_info.downsampled_width = width;
    comp_info.downsampled_height = height;
    comp_info.component_needed = 1;
    comp_info.MCU_width = 16;
    comp_info.MCU_height = 16;
    comp_info.MCU_blocks = 4;
    comp_info.MCU_sample_width = 16;
    comp_info.last_col_width = 1;
    comp_info.last_row_height = 1;
    comp_info.quant_table = &quant_table;
    comp_info.dct_table = NULL;

    compptr = &comp_info;

    h_expand = 2;
    v_expand = 2;
    numpix = h_expand * v_expand;
    numpix2 = numpix / 2;

    output_cols = width;

    inrow = 0;
    outrow = 0;
    h = 0;
    v = 0;
    outcol = 0;
    outcol_h = 0;

    outptr = NULL;
    inptr = NULL;
}