#include <stdio.h>

#include <inttypes.h>

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

extern BIO_F_BUFFER_CTX *ctx;
extern long ret;
extern char *p1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolling (accessing two elements per iteration)
    int n = ctx->ibuf_len;
    int off = ctx->ibuf_off;
    for (i = 0; i < n - 1; i += 2) {
        if (p1[off + i] == '\n')
            ret++;
        if (p1[off + i + 1] == '\n')
            ret++;
    }
    // Handle remaining element if ibuf_len is odd
    if (i < n && p1[off + i] == '\n')
        ret++;
}
