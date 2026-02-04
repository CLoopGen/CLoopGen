#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

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

ssize_t type;
OptionInfo *option_info;
ssize_t i;

static char **generated_strings;
static size_t data_size = 1 << 20; // ~1MB of data

void init_vars() {
    type = 42; // Arbitrary target type to control early/late break
    size_t num_elements = data_size / sizeof(OptionInfo);

    generated_strings = malloc(num_elements * sizeof(char*));
    option_info = malloc(num_elements * sizeof(OptionInfo));

    for (size_t idx = 0; idx < num_elements - 1; idx++) {
        generated_strings[idx] = malloc(16);
        sprintf(generated_strings[idx], "key%" PRIuPTR, idx);
        option_info[idx].mnemonic = generated_strings[idx];
        option_info[idx].type = (ssize_t)(idx + 1); 
        option_info[idx].flags = (ssize_t)rand();
        option_info[idx].stealth = (idx % 2) ? MagickTrue : MagickFalse;
    }

    // Last element: null mnemonic to terminate loop
    option_info[num_elements - 1].mnemonic = NULL;
    option_info[num_elements - 1].type = 0;
    option_info[num_elements - 1].flags = 0;
    option_info[num_elements - 1].stealth = MagickFalse;

    // Ensure the loop runs long enough (~tens of millions of iterations) but eventually terminates
    // by placing match near end if needed. Here we let it break only at null unless matched earlier.
    // To force full scan almost every time, set type to non-existing value until last check.
    // But for timing stability, place a match around 90% through.
    size_t match_index = (size_t)(num_elements * 0.9);
    if (match_index < num_elements - 1) {
        option_info[match_index].type = type;
    }
}

void cleanup_vars() {
    size_t num_elements = data_size / sizeof(OptionInfo);
    for (size_t idx = 0; idx < num_elements - 1; idx++) {
        free(generated_strings[idx]);
    }
    free(generated_strings);
    free(option_info);
}