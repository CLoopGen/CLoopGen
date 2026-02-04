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
    int temp_order[24];
    for (i = 0; section->fields[i].name; i++) {
        temp_order[i] = i;
    }
    for (i = 0; section->fields[i].name; i++) {
        order[i] = temp_order[i];
    }
}
