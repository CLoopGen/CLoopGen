#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bio_f_buffer_ctx_struct {
    int ibuf_size;
    int obuf_size;
    char *ibuf;
    int ibuf_len;
    int ibuf_off;
    char *obuf;
    int obuf_len;
    int obuf_off;
} BIO_F_BUFFER_CTX;

char *buf;
int size;
BIO_F_BUFFER_CTX *ctx;
int num_chars;
int found_newline;
char *p;

static char internal_buf[1024 * 1024];
static char input_data[1024 * 1024];
static BIO_F_BUFFER_CTX context;

void init_vars() {
    const int data_size = 512 * 1024; // 512KB of input data
    
    // Initialize the input data with no newlines initially
    for (int i = 0; i < data_size; i++) {
        input_data[i] = 'A' + (i % 26);
    }
    // Place a newline near the end to trigger the break condition
    input_data[data_size - 100] = '\n';
    
    // Initialize context
    context.ibuf_size = data_size;
    context.obuf_size = data_size;
    context.ibuf = input_data;
    context.ibuf_len = data_size;
    context.ibuf_off = 0;
    context.obuf = NULL;
    context.obuf_len = 0;
    context.obuf_off = 0;
    
    ctx = &context;
    buf = internal_buf;
    size = data_size;
    p = ctx->ibuf;
    num_chars = 0;
    found_newline = 0;
}