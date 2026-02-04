#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *text;
char *p;
size_t lines;

static char *generated_text = NULL;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB to target ~0.01s runtime on modern CPU
    generated_text = (char *)malloc(data_size);
    if (!generated_text) {
        text = (char *)"";
        p = text;
        lines = 0;
        return;
    }

    // Fill with mostly printable characters and about 1% newlines
    for (size_t i = 0; i < data_size - 1; i++) {
        if (rand() % 100 == 0) {
            generated_text[i] = '\n';
        } else {
            generated_text[i] = 'a' + (i % 26);
        }
    }
    generated_text[data_size - 1] = '\x00'; // null terminate

    text = generated_text;
    p = text;
    lines = 0;
}

__attribute__((destructor))
static void cleanup() {
    free(generated_text);
}