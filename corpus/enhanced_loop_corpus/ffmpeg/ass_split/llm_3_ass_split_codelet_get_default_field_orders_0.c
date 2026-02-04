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
    // Use indirect access via a pointer array to create non-consecutive, indirect memory access pattern
    ASSFields *field_ptrs[24];
    int count = 0;
    
    for (i = 0; section->fields[i].name; i++) {
        field_ptrs[count++] = &(section->fields[i]);
    }
    
    for (i = 0; i < count; i++) {
        // Indirect access: use stored pointers to assign original index
        order[(int)(field_ptrs[i] - section->fields)] = (int)(field_ptrs[i] - section->fields);
    }
}
