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

extern AVSubtitleRect *dst;
extern AVSubtitleRect *src;
extern int cmap[];
extern int x;
extern int y;
extern uint8_t *p;
extern uint8_t *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < src->h; y++) {
        x = 0;
        for (; x < src->w; x++)
            *(q++) = cmap[*(p++)];
        p += src->linesize[0] - src->w;
        q += dst->linesize[0] - src->w;
    }
}
