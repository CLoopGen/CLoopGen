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
    for (i = 0; i < num_chapters && i < (num_chapters - i - 1); i++) {
        ID3v2ExtraMetaCHAP *right;
        int right_index = (num_chapters - 1) - i;
        if (chapters[i] == NULL || chapters[right_index] == NULL) {
            continue;
        }
        right = chapters[right_index];
        chapters[right_index] = chapters[i];
        chapters[i] = right;
    }
}
