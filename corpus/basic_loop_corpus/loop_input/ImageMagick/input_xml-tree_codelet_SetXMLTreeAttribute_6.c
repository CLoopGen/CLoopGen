#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef struct _XMLTreeInfo XMLTreeInfo;

typedef enum {
    MagickFalse = 0,
    MagickTrue = 1
} MagickBooleanType;

typedef struct SemaphoreInfo SemaphoreInfo;

struct SemaphoreInfo {
    int lock;
};

struct _XMLTreeInfo {
    char *tag;
    char **attributes;
    char *content;
    size_t offset;
    XMLTreeInfo *parent;
    XMLTreeInfo *next;
    XMLTreeInfo *sibling;
    XMLTreeInfo *ordered;
    XMLTreeInfo *child;
    MagickBooleanType debug;
    SemaphoreInfo *semaphore;
    size_t signature;
};

XMLTreeInfo *xml_info;
ssize_t i;
ssize_t j;

#define ATTR_BUFFER_SIZE (1 << 20)  // ~1MB of attribute data

static char **alloc_and_init_attributes(size_t *count) {
    // Each pair is key and value; we'll make 50k pairs to get ~1MB
    const size_t num_pairs = 50000;
    char **attrs = calloc(num_pairs * 2 + 1, sizeof(char *));
    if (!attrs) exit(1);

    for (size_t idx = 0; idx < num_pairs; idx++) {
        attrs[idx * 2] = malloc(16);
        if (!attrs[idx * 2]) exit(1);
        snprintf(attrs[idx * 2], 16, "key%zu", idx);

        attrs[idx * 2 + 1] = malloc(32);
        if (!attrs[idx * 2 + 1]) exit(1);
        snprintf(attrs[idx * 2 + 1], 32, "value%zu_value%zu", idx, idx);
    }
    attrs[num_pairs * 2] = NULL;  // terminate with NULL
    *count = num_pairs * 2;
    return attrs;
}

void init_vars() {
    size_t attr_count;
    char **attrs = alloc_and_init_attributes(&attr_count);

    xml_info = calloc(1, sizeof(XMLTreeInfo));
    if (!xml_info) exit(1);

    xml_info->attributes = attrs;
    xml_info->tag = strdup("root");
    xml_info->content = strdup("sample content");
    xml_info->offset = 0;
    xml_info->parent = NULL;
    xml_info->next = NULL;
    xml_info->sibling = NULL;
    xml_info->ordered = NULL;
    xml_info->child = NULL;
    xml_info->debug = MagickFalse;
    xml_info->semaphore = calloc(1, sizeof(SemaphoreInfo));
    xml_info->signature = 0x12345678;

    i = 0;
    j = 0;
}