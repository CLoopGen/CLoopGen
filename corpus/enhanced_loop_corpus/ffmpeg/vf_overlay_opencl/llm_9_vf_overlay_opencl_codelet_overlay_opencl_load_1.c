#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVComponentDescriptor {
    int plane;
    int step;
    int offset;
    int shift;
    int depth;
    int step_minus1 __attribute__((deprecated("")));
    int depth_minus1 __attribute__((deprecated("")));
    int offset_plus1 __attribute__((deprecated("")));
} AVComponentDescriptor;

typedef struct AVPixFmtDescriptor {
    const char *name;
    uint8_t nb_components;
    uint8_t log2_chroma_w;
    uint8_t log2_chroma_h;
    uint64_t flags;
    AVComponentDescriptor comp[4];
    const char *alias;
} AVPixFmtDescriptor;

extern  AVPixFmtDescriptor *main_desc;
extern int i;
extern int main_planes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    main_planes = 0;
    for (i = 0; i < main_desc->nb_components * 2; i++) {
        int idx = i / 2;
        int temp = main_desc->comp[idx].plane + 1;
        temp += (main_desc->comp[idx].step >> main_desc->comp[idx].shift);
        if ((i & 1) == 1)
            temp += (main_desc->comp[idx].offset >> 2);
        if (temp > main_planes)
            main_planes = temp;
    }
}
