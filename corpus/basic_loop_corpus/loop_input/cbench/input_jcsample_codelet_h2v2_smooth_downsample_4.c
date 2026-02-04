#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int JDIMENSION;
typedef int boolean;
typedef unsigned short UINT16;
typedef unsigned char JSAMPLE;
typedef long INT32;

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
JDIMENSION colctr;
JDIMENSION output_cols;
JSAMPROW inptr0;
JSAMPROW inptr1;
JSAMPROW above_ptr;
JSAMPROW below_ptr;
JSAMPROW outptr;
INT32 membersum;
INT32 neighsum;
INT32 memberscale;
INT32 neighscale;

#define INPUT_ROWS 2048
#define OUTPUT_COLS 4096
#define DATA_SIZE (INPUT_ROWS * OUTPUT_COLS * sizeof(JSAMPLE))

static JSAMPLE *input_buffer;
static JSAMPLE *output_buffer;
static JSAMPROW *input_array;
static JSAMPROW *output_array;
static JQUANT_TBL quant_table;

void init_vars() {
    // Allocate buffers
    input_buffer = (JSAMPLE*)calloc(DATA_SIZE, 1);
    output_buffer = (JSAMPLE*)calloc(DATA_SIZE, 1);
    input_array = (JSAMPROW*)malloc(INPUT_ROWS * sizeof(JSAMPROW));
    output_array = (JSAMPROW*)malloc(INPUT_ROWS * sizeof(JSAMPROW));

    // Initialize row pointers
    for (int i = 0; i < INPUT_ROWS; i++) {
        input_array[i] = &input_buffer[i * OUTPUT_COLS];
        output_array[i] = &output_buffer[i * OUTPUT_COLS];
    }

    // Initialize quant table
    memset(&quant_table, 0, sizeof(JQUANT_TBL));
    quant_table.sent_table = 1;

    // Allocate and initialize compptr
    compptr = (jpeg_component_info*)malloc(sizeof(jpeg_component_info));
    compptr->component_id = 1;
    compptr->component_index = 0;
    compptr->h_samp_factor = 1;
    compptr->v_samp_factor = 2;
    compptr->quant_tbl_no = 0;
    compptr->dc_tbl_no = 0;
    compptr->ac_tbl_no = 0;
    compptr->width_in_blocks = OUTPUT_COLS / 8;
    compptr->height_in_blocks = INPUT_ROWS / 8;
    compptr->DCT_scaled_size = 8;
    compptr->downsampled_width = OUTPUT_COLS;
    compptr->downsampled_height = INPUT_ROWS;
    compptr->component_needed = 1;
    compptr->MCU_width = 1;
    compptr->MCU_height = 2;
    compptr->MCU_blocks = 2;
    compptr->MCU_sample_width = 8;
    compptr->last_col_width = 1;
    compptr->last_row_height = 1;
    compptr->quant_table = &quant_table;
    compptr->dct_table = NULL;

    // Set global pointers
    input_data = input_array;
    output_data = output_array;
    inrow = 2;
    outrow = 0;
    output_cols = OUTPUT_COLS / 2;
    memberscale = 8192;
    neighscale = 4096;

    // Ensure valid memory access by filling boundary regions
    for (int i = 0; i < INPUT_ROWS; i++) {
        for (int j = 0; j < OUTPUT_COLS; j++) {
            input_buffer[i * OUTPUT_COLS + j] = (JSAMPLE)(i + j) % 256;
        }
    }
}