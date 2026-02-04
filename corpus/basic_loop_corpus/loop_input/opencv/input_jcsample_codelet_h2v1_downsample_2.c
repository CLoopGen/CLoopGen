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

static JSAMPROW *g_input_data = NULL;
static JSAMPROW *g_output_data = NULL;
static jpeg_component_info *g_compptr = NULL;

jpeg_component_info *compptr = NULL;
JSAMPARRAY input_data = NULL;
JSAMPARRAY output_data = NULL;
int outrow;
JDIMENSION outcol;
JDIMENSION output_cols;
JSAMPROW inptr;
JSAMPROW outptr;
int bias;

void init_vars() {
    const size_t total_data_size = 128 * 1024 * 1024; // 128 MB target
    const int block_rows = 2048;
    const int block_cols = 32768 / sizeof(JSAMPLE*); 

    g_compptr = (jpeg_component_info*)calloc(1, sizeof(jpeg_component_info));
    g_input_data = (JSAMPROW*)calloc(block_rows, sizeof(JSAMPROW));
    g_output_data = (JSAMPROW*)calloc(block_rows, sizeof(JSAMPROW));

    if (!g_compptr || !g_input_data || !g_output_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    const int row_stride = block_cols * 2;
    const size_t row_size = row_stride * sizeof(JSAMPLE);

    for (int i = 0; i < block_rows; i++) {
        g_input_data[i] = (JSAMPROW)calloc(row_stride, sizeof(JSAMPLE));
        g_output_data[i] = (JSAMPROW)calloc(block_cols, sizeof(JSAMPLE));
        if (!g_input_data[i] || !g_output_data[i]) {
            fprintf(stderr, "Row allocation failed\n");
            exit(1);
        }
        for (int j = 0; j < row_stride; j++) {
            g_input_data[i][j] = (JSAMPLE)(j & 0xFF);
        }
    }

    compptr = g_compptr;
    input_data = g_input_data;
    output_data = g_output_data;

    compptr->v_samp_factor = block_rows;
    output_cols = block_cols;
}