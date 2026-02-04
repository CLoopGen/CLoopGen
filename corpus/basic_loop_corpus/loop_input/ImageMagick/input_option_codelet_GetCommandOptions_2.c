#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef enum {
    MagickFalse = 0,
    MagickTrue = 1
} MagickBooleanType;

typedef struct _OptionInfo {
    const char *mnemonic;
    ssize_t type;
    ssize_t flags;
    MagickBooleanType stealth;
} OptionInfo;

static const char* generate_string(ssize_t id) {
    char* str = (char*)malloc(16);
    sprintf(str, "option%" PRIdPTR, id);
    return (const char*)str;
}

OptionInfo* option_info = NULL;
ssize_t i;

void init_vars() {
    const size_t num_elements = 131072; // ~1.3MB of data: 131072 * (sizeof(void*) + 2*ssize_t + bool)
    option_info = (OptionInfo*)calloc(num_elements + 1, sizeof(OptionInfo));

    for (size_t idx = 0; idx < num_elements; ++idx) {
        option_info[idx].mnemonic = generate_string(idx);
        option_info[idx].type = idx % 4;
        option_info[idx].flags = (ssize_t)(1000 + idx);
        option_info[idx].stealth = (idx % 10 == 0) ? MagickTrue : MagickFalse;
    }

    option_info[num_elements].mnemonic = (const char*)((void*)0);
    option_info[num_elements].type = 0;
    option_info[num_elements].flags = 0;
    option_info[num_elements].stealth = MagickFalse;
}