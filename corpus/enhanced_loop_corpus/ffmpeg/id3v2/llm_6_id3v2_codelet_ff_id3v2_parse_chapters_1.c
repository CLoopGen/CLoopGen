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
    ID3v2ExtraMetaCHAP *temp;
    int left, right_index;
    for (i = 0; i < (num_chapters / 2); i++) {
        left = i;
        right_index = (num_chapters - 1) - i;
        temp = chapters[left];
        chapters[left] = chapters[right_index];
        chapters[right_index] = temp;
    }
}
