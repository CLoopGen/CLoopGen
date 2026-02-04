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
    int start = 0;
    int end = num_chapters - 1;
    while (start < end) {
        ID3v2ExtraMetaCHAP *temp = chapters[start];
        chapters[start] = chapters[end];
        chapters[end] = temp;
        start++;
        end--;
    }
}
