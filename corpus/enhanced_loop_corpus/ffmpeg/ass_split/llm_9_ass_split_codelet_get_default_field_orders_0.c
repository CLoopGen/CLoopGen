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
    for (i = 0; i < section->size && i < 24; i += 2) {
        order[i] = i;
        if (i + 1 < 24 && section->fields[i + 1].name) {
            order[i + 1] = i + 1;
        }
    }
    for (int j = 0; j < 5; j++) {
        order[(i + j) % 24] ^= j * 3;
    }
}
