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

void loop(){
for (max_offset = 0; p != (ElementInfo *)((void *)0);) {
    const MagicInfo *magic_info;
    magic_info = (const MagicInfo *)p->value;
    offset = magic_info->offset + (MagickOffsetType)magic_info->length;
    if (offset > max_offset)
        max_offset = offset;
    p = p->next;
}

}
