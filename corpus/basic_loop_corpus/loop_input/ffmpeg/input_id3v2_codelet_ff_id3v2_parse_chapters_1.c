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

ID3v2ExtraMetaCHAP **chapters;
int num_chapters;
int i;

void init_vars() {
    num_chapters = 131072;

    chapters = (ID3v2ExtraMetaCHAP**)calloc(num_chapters, sizeof(ID3v2ExtraMetaCHAP*));
    if (!chapters) exit(1);

    for (int idx = 0; idx < num_chapters; idx++) {
        chapters[idx] = (ID3v2ExtraMetaCHAP*)malloc(sizeof(ID3v2ExtraMetaCHAP));
        if (!chapters[idx]) exit(1);
        chapters[idx]->element_id = (uint8_t*)calloc(16, sizeof(uint8_t));
        if (!chapters[idx]->element_id) exit(1);
        chapters[idx]->start = idx * 100;
        chapters[idx]->end = (idx + 1) * 100;
        chapters[idx]->meta = NULL;
    }

    i = 0;
}