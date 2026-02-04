#include <stdio.h>
#include <inttypes.h>
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

BIO_F_BUFFER_CTX *ctx;
long ret;
char *p1;
int i;

void init_vars() {
    const int data_size = 512 * 1024; // 512 KB input data

    ctx = (BIO_F_BUFFER_CTX *)malloc(sizeof(BIO_F_BUFFER_CTX));
    ctx->ibuf_size = data_size;
    ctx->ibuf_len = data_size / 2; // Use half the buffer
    ctx->ibuf_off = 0;
    ctx->ibuf = (char *)malloc(ctx->ibuf_size);
    
    // Initialize input buffer with random data ending in newlines occasionally
    for (int j = 0; j < ctx->ibuf_len; j++) {
        ctx->ibuf[j] = (rand() % 50 == 0) ? '\n' : 'A' + (rand() % 26);
    }

    p1 = ctx->ibuf; // Point p1 to the beginning of ibuf
    ret = 0;
}