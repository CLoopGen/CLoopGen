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

extern  AVSubtitleRect *r;
extern unsigned int count[256];
extern int x;
extern int y;
extern uint8_t *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < r->h; y++) {
        x = 0;
        for (; x < r->w; x++)
            count[*(p++)]++;
        p += r->linesize[0] - r->w;
    }
}
