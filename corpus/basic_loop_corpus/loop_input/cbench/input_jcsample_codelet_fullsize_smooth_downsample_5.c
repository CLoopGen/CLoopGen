#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int JDIMENSION;
typedef int boolean;
typedef unsigned short UINT16;
typedef unsigned char JSAMPLE;
typedef long INT32;

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
JDIMENSION colctr;
JDIMENSION output_cols;
JSAMPROW inptr;
JSAMPROW above_ptr;
JSAMPROW below_ptr;
JSAMPROW outptr;
INT32 membersum;
INT32 neighsum;
INT32 memberscale;
INT32 neighscale;
int colsum;
int lastcolsum;
int nextcolsum;

#define DATA_SIZE_MB 64
#define TOTAL_PIXELS (DATA_SIZE_MB * 1024 * 1024)
#define COMPONENT_ROWS 8
#define OUTPUT_COLS_PER_ROW (TOTAL_PIXELS / COMPONENT_ROWS)

static JSAMPLE *input_buffer;
static JSAMPLE *output_buffer;
static JSAMPROW *input_rows;
static JSAMPROW *output_rows;
static jpeg_component_info comp_info;
static JQUANT_TBL quant_table;

void init_vars() {
    memberscale = 128;
    neighscale = 64;
    output_cols = OUTPUT_COLS_PER_ROW;

    compptr = &comp_info;
    compptr->v_samp_factor = COMPONENT_ROWS;
    compptr->component_needed = 1;
    compptr->quant_table = &quant_table;
    compptr->dc_tbl_no = 0;
    compptr->ac_tbl_no = 0;
    compptr->h_samp_factor = 1;
    compptr->width_in_blocks = output_cols;
    compptr->height_in_blocks = COMPONENT_ROWS;
    compptr->DCT_scaled_size = 8;
    compptr->downsampled_width = output_cols;
    compptr->downsampled_height = COMPONENT_ROWS;
    compptr->MCU_width = 1;
    compptr->MCU_height = 1;
    compptr->MCU_blocks = 1;
    compptr->MCU_sample_width = 8;
    compptr->last_col_width = 1;
    compptr->last_row_height = 1;
    compptr->dct_table = NULL;

    for (int i = 0; i < 64; i++) {
        quant_table.quantval[i] = 100 + (i % 50);
    }
    quant_table.sent_table = 0;

    size_t row_size = sizeof(JSAMPLE) * (output_cols + 2);

    input_buffer = (JSAMPLE *)calloc(COMPONENT_ROWS + 2, row_size);
    if (!input_buffer) exit(1);

    output_buffer = (JSAMPLE *)calloc(COMPONENT_ROWS, row_size);
    if (!output_buffer) exit(1);

    input_rows = (JSAMPROW *)calloc(COMPONENT_ROWS + 2, sizeof(JSAMPROW));
    if (!input_rows) exit(1);

    output_rows = (JSAMPROW *)calloc(COMPONENT_ROWS, sizeof(JSAMPROW));
    if (!output_rows) exit(1);

    for (int i = 0; i < COMPONENT_ROWS + 2; i++) {
        input_rows[i] = &input_buffer[i * (output_cols + 2)];
    }

    for (int i = 0; i < COMPONENT_ROWS; i++) {
        output_rows[i] = &output_buffer[i * (output_cols + 2)];
    }

    input_data = input_rows + 1;
    output_data = output_rows;

    for (int i = 0; i < COMPONENT_ROWS; i++) {
        for (JDIMENSION j = 0; j < output_cols; j++) {
            input_data[i][j] = (JSAMPLE)((i * output_cols + j) % 256);
        }
    }

    colctr = 0;
    inptr = NULL;
    above_ptr = NULL;
    below_ptr = NULL;
    outptr = NULL;
    membersum = 0;
    neighsum = 0;
    colsum = 0;
    lastcolsum = 0;
    nextcolsum = 0;
}