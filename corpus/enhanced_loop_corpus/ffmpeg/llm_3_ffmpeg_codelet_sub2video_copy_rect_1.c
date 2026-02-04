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
uint8_t **indices = (uint8_t**)alloca(r->w * sizeof(uint8_t*));
for (int i = 0; i < r->w; i++)
    indices[i] = &src[i * r->linesize[0]]; // simulate indirect access pattern

for (y = 0; y < r->h; y++) {
    dst2 = (uint32_t *)dst;
    for (x = 0; x < r->w; x++) {
        size_t idx = (size_t)(indices[x] - src + y * r->linesize[0]);
        *(dst2++) = pal[src[idx]];
    }
    dst += dst_linesize;
}
}
