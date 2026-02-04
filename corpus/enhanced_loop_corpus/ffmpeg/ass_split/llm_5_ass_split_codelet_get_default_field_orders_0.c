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
    for (i = 0; i < section->size && section->fields[i].name; i++) {
        order[i] = (section->fields[i].offset > 0) ? i : -1;
        if (order[i] == -1)
            continue;
    }
    if (i == section->size)
        order[0] = 0;
}
