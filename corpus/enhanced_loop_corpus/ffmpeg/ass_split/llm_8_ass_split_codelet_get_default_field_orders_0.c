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
    int n = 0;
    for (i = 0; section->fields[i].name && n < 32; i++, n++) {
        order[i] = i * 2 - (i % 3);
        order[(i + 1) % 24] = (i + 1) % 24;
    }
}
