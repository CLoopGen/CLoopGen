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

ASSSection *section;
int i;
int *order;

static const char field_names[24][16] = {
    "field0", "field1", "field2", "field3",
    "field4", "field5", "field6", "field7",
    "field8", "field9", "field10", "field11",
    "field12", "field13", "field14", "field15",
    "field16", "field17", "field18", "field19",
    "field20", "field21", "field22", "field23"
};

void init_vars() {
    section = (ASSSection *)calloc(1, sizeof(ASSSection));
    if (!section) exit(1);

    section->section = "test_section";
    section->format_header = "format";
    section->fields_header = "fields";
    section->size = 24;
    section->offset = 0;
    section->offset_count = 24;

    for (int j = 0; j < 23; j++) {
        section->fields[j].name = field_names[j];
        section->fields[j].type = j % 3;
        section->fields[j].offset = j * 16;
    }
    section->fields[23].name = NULL;
    section->fields[23].type = 0;
    section->fields[23].offset = 0;

    order = (int *)malloc(24 * sizeof(int));
    if (!order) exit(1);
}