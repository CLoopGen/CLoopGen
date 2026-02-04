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
    uint32_t *temp_dst;
    uint8_t *temp_src;
    int i, j;
    for (i = 0; i < r->h; i++) {
        temp_dst = (uint32_t *)(dst + i * dst_linesize);
        temp_src = src + i * r->linesize[0];
        for (j = 0; j < r->w; j++) {
            temp_dst[j] = pal[temp_src[j]];
        }
    }
}
