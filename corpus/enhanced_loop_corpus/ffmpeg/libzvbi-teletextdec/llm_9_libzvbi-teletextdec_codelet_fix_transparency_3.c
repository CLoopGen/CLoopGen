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

extern AVSubtitleRect *sub_rect;
extern int resy;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 1;
    int limit = resy * 4;
    for (iy = 0; iy < limit; iy++) {
        int effective_iy = iy / 4;
        uint8_t *pixel = sub_rect->data[0] + effective_iy * sub_rect->linesize[0];
        volatile uint8_t dummy = pixel[0]; // Prevent optimization
        step += (iy % 3 == 0) ? 2 : 1;
        iy += step - 1;
    }
}
