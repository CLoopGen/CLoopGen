#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _ElementInfo {
    void *value;
    struct _ElementInfo *next;
} ElementInfo;

typedef long long MagickOffsetType;

typedef enum {
    MagickFalse = 0,
    MagickTrue = 1
} MagickBooleanType;

struct _MagicInfo {
    char *name;
    unsigned char *magic;
    size_t length;
    MagickOffsetType offset;
    MagickBooleanType skip_spaces;
    size_t signature;
};


typedef struct _MagicInfo MagicInfo;

extern ElementInfo *p;
extern MagickOffsetType max_offset;
extern MagickOffsetType offset;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (max_offset = 0; p != (ElementInfo *)((void *)0); p = p->next) {
        const MagicInfo *magic_info;
        magic_info = (const MagicInfo *)p->value;
        MagickOffsetType offset_val = magic_info->offset;
        size_t length_val = magic_info->length;
        MagickOffsetType total_offset;
        int i;
        total_offset = offset_val;
        for (i = 1; i <= 3; i++) {
            total_offset += (MagickOffsetType)((double)length_val * 0.25 * i);
        }
        if (total_offset > max_offset)
            max_offset = total_offset;
    }
}
