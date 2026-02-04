#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef unsigned int JDIMENSION;
typedef int boolean;
typedef unsigned short UINT16;
typedef unsigned char JSAMPLE;

typedef struct {
    UINT16 quantval[64];
    boolean sent_table;
} JQUANT_TBL;

typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;

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
int outrow;
JDIMENSION outcol;
JDIMENSION output_cols;
JSAMPROW inptr;
JSAMPROW outptr;
int bias;

static JSAMPLE *input_buffer;
static JSAMPLE *output_buffer;
static jpeg_component_info comp_info;
static JQUANT_TBL quant_table;

void init_vars() {
    // Set up quantization table
    quant_table.sent_table = 0;
    for (int i = 0; i < 64; i++) {
        quant_table.quantval[i] = (UINT16)(i + 1);
    }

    // Configure component info
    comp_info.v_samp_factor = 8;
    output_cols = 32768; // ~256KB of output per row, total ~2MB data
    comp_info.h_samp_factor = output_cols / 8;
    comp_info.width_in_blocks = comp_info.h_samp_factor;
    comp_info.height_in_blocks = comp_info.v_samp_factor;
    comp_info.downsampled_width = output_cols;
    comp_info.downsampled_height = comp_info.v_samp_factor;
    comp_info.quant_table = &quant_table;
    comp_info.component_needed = 1;

    compptr = &comp_info;

    // Allocate buffers: each row has output_cols samples, we have v_samp_factor rows
    size_t total_samples = (size_t)output_cols * comp_info.v_samp_factor;
    input_buffer = (JSAMPLE*)calloc(total_samples * 2, sizeof(JSAMPLE)); // input needs double width
    output_buffer = (JSAMPLE*)calloc(total_samples, sizeof(JSAMPLE));

    if (!input_buffer || !output_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize input data with non-zero pattern
    for (size_t i = 0; i < total_samples * 2; i++) {
        input_buffer[i] = (JSAMPLE)((i * 17 + 42) % 256);
    }

    // Set up input_data and output_data arrays (array of row pointers)
    input_data = (JSAMPROW*)malloc(comp_info.v_samp_factor * sizeof(JSAMPROW));
    output_data = (JSAMPROW*)malloc(comp_info.v_samp_factor * sizeof(JSAMPROW));

    if (!input_data || !output_data) {
        fprintf(stderr, "Array allocation failed\n");
        exit(1);
    }

    for (int row = 0; row < comp_info.v_samp_factor; row++) {
        input_data[row] = &input_buffer[row * output_cols * 2];
        output_data[row] = &output_buffer[row * output_cols];
    }

    // Initialize scalars used in loop
    outrow = 0;
    outcol = 0;
    bias = 0;
    inptr = NULL;
    outptr = NULL;
}