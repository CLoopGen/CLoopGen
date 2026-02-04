#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    const char *name;
    int type;
    int offset;
} ASSFields;

typedef struct {
    const char *section;
    const char *format_header;
    const char *fields_header;
    int size;
    int offset;
    int offset_count;
    ASSFields fields[24];
} ASSSection;

extern  ASSSection *section;
extern int i;
extern int *order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int idx = 0;
    for (i = 0; section->fields[i].name != NULL; i++) {
        if (section->fields[i].type != 0) {
            order[idx] = i;
            idx++;
        }
    }
    for (; i < section->size && idx < section->offset_count; i++) {
        order[idx++] = i;
    }
}
