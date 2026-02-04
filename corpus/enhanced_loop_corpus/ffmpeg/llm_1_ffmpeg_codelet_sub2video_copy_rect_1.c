#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVPicture {
    uint8_t *data[8] __attribute__((deprecated("")));
    int linesize[8] __attribute__((deprecated("")));
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
    AVPicture pict __attribute__((deprecated("")));
    uint8_t *data[4];
    int linesize[4];
    enum AVSubtitleType type;
    char *text;
    char *ass;
    int flags;
} AVSubtitleRect;

extern uint8_t *dst;
extern int dst_linesize;
extern AVSubtitleRect *r;
extern uint32_t *pal;
extern uint32_t *dst2;
extern uint8_t *src;
extern uint8_t *src2;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int total_pixels = r->h * r->w;
    dst2 = (uint32_t *)dst;
    src2 = src;
    for (int block_y = 0; block_y < r->h; block_y++) {
        uint32_t *row_dst = dst2;
        uint8_t *row_src = src2;
        for (x = 0; x < r->w; x++) {
            row_dst[x] = pal[row_src[x]];
        }
        dst2 = (uint32_t *)((uint8_t *)dst2 + dst_linesize);
        src2 += r->linesize[0];
    }
}
