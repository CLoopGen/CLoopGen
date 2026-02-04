#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *code_lengths;
extern int alphabet_size;
extern int sym;
extern int max_code_length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *indices = (int*)alloca(alphabet_size * sizeof(int));
    for (int i = 0; i < alphabet_size; i++) {
        indices[i] = i;
    }
    for (int i = 0; i < alphabet_size; i++) {
        int idx = indices[i]; // Indirect access via index array
        max_code_length = (max_code_length > code_lengths[idx]) ? max_code_length : code_lengths[idx];
    }
}
