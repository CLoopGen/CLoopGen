#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVDictionary AVDictionary;

typedef struct ID3v2ExtraMetaCHAP {
    uint8_t *element_id;
    uint32_t start;
    uint32_t end;
    AVDictionary *meta;
} ID3v2ExtraMetaCHAP;

extern ID3v2ExtraMetaCHAP **chapters;
extern int num_chapters;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < num_chapters; i += 4) {
        int indices[4] = {i, i+1, num_chapters-1-i, num_chapters-2-i};
        if (indices[0] >= num_chapters / 2) break;
        if (indices[1] < num_chapters / 2) {
            ID3v2ExtraMetaCHAP *right1 = chapters[num_chapters - 1 - i];
            chapters[num_chapters - 1 - i] = chapters[i];
            chapters[i] = right1;
        }
        if (indices[1] < num_chapters && indices[1] < num_chapters / 2) {
            int right_index2 = num_chapters - 2 - i;
            if (right_index2 > i + 1) {
                ID3v2ExtraMetaCHAP *right2 = chapters[right_index2];
                chapters[right_index2] = chapters[i + 1];
                chapters[i + 1] = right2;
            }
        }
    }
}
