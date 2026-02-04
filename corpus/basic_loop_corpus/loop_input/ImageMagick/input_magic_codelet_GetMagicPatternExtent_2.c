#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

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

ElementInfo *p;
MagickOffsetType max_offset;
MagickOffsetType offset;

#define NUM_ELEMENTS 100000

static MagicInfo magic_infos[NUM_ELEMENTS];
static ElementInfo elements[NUM_ELEMENTS];

void init_vars() {
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        // Allocate small magic pattern
        unsigned char *magic = malloc(8);
        for (int j = 0; j < 8; j++) {
            magic[j] = (unsigned char)(i ^ j);
        }
        
        // Setup MagicInfo
        magic_infos[i].name = NULL;
        magic_infos[i].magic = magic;
        magic_infos[i].length = (i % 16) + 1;  // 1 to 16
        magic_infos[i].offset = (MagickOffsetType)(i * 32);  // Increasing offsets
        magic_infos[i].skip_spaces = (i % 2 == 0) ? MagickTrue : MagickFalse;
        magic_infos[i].signature = 0x12345678;
        
        // Setup ElementInfo
        elements[i].value = &magic_infos[i];
        if (i == NUM_ELEMENTS - 1) {
            elements[i].next = NULL;
        } else {
            elements[i].next = &elements[i + 1];
        }
    }
    
    // Initialize global p to point to first element
    p = &elements[0];
    max_offset = 0;
    offset = 0;
}