#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AVPicture {
    uint8_t *data[8];
    int linesize[8];
} AVPicture;

enum AVSubtitleType {
    SUBTITLE_NONE,
    SUBTITLE_BITMAP,
    SUBTITLE_TEXT,
    SUBTITLE_ASS
};

typedef struct AVSubtitleRect {
    int x;
    int y;
    int w;
    int h;
    int nb_colors;
    AVPicture pict;
    uint8_t *data[4];
    int linesize[4];
    enum AVSubtitleType type;
    char *text;
    char *ass;
    int flags;
} AVSubtitleRect;

uint8_t *dst;
int dst_linesize;
AVSubtitleRect *r;
uint32_t *pal;
uint32_t *dst2;
uint8_t *src;
uint8_t *src2;
int x;
int y;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;
static uint32_t *pal_buffer;
static AVSubtitleRect r_storage;

void init_vars() {
    const int width = 1600;
    const int height = 1000;
    const int bytes_per_pixel = 4;
    const int src_linesize = width;
    const int dst_linesize_val = width * bytes_per_pixel;

    dst_buffer = (uint8_t*)malloc(height * dst_linesize_val);
    src_buffer = (uint8_t*)malloc(height * src_linesize);
    pal_buffer = (uint32_t*)malloc(256 * sizeof(uint32_t));

    if (!dst_buffer || !src_buffer || !pal_buffer) {
        exit(1);
    }

    for (int i = 0; i < 256; i++) {
        pal_buffer[i] = ((i & 0xFF) << 16) | ((i & 0x7F) << 8) | (i >> 1);
    }

    for (int i = 0; i < height * src_linesize; i++) {
        src_buffer[i] = rand() % 256;
    }

    dst = dst_buffer;
    dst_linesize = dst_linesize_val;
    src = src_buffer;
    pal = pal_buffer;
    r = &r_storage;

    r->x = 0;
    r->y = 0;
    r->w = width;
    r->h = height;
    r->nb_colors = 256;
    r->data[0] = src_buffer;
    r->linesize[0] = src_linesize;
    r->type = SUBTITLE_BITMAP;
    r->text = NULL;
    r->ass = NULL;
    r->flags = 0;
}