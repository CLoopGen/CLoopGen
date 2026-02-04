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
    int limit = ctx->ibuf_len * 3;
    for (i = 0; i < limit; i++) {
        int idx = (i / 3);
        if (i % 3 == 0 && p1[ctx->ibuf_off + idx] == '\n') {
            ret++;
        }
    }
}
