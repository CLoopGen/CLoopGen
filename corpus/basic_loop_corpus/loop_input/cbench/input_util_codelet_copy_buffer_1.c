#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bit_stream_struc {
    unsigned char *pbtOutBuf;
    int nOutBufPos;
    FILE *pt;
    unsigned char *buf;
    int buf_size;
    unsigned long totbit;
    int buf_byte_idx;
    int buf_bit_idx;
} Bit_stream_struc;

char *buffer;
Bit_stream_struc *bs;
int i;
int j;

void init_vars() {
    const size_t data_size = 134217728; // 128MB for ~0.01s runtime on modern CPU

    buffer = (char *)malloc(data_size);
    bs = (Bit_stream_struc *)malloc(sizeof(Bit_stream_struc));
    bs->buf = (unsigned char *)malloc(data_size);
    bs->buf_size = data_size;
    bs->buf_byte_idx = data_size / 2; // Ensure buf_byte_idx is less than buf_size
    bs->pbtOutBuf = NULL;
    bs->nOutBufPos = 0;
    bs->pt = NULL;
    bs->totbit = 0;
    bs->buf_bit_idx = 0;

    j = 0;

    // Initialize buf with dummy data
    for (size_t idx = 0; idx < data_size; ++idx) {
        bs->buf[idx] = (unsigned char)(idx % 256);
    }

    // Ensure buffer has valid memory to write into
    memset(buffer, 0, data_size);
}