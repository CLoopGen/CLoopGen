#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

struct cpp_string {
    unsigned int len;
    const unsigned char *text;
};

struct cpp_string *in;
unsigned char *src;
unsigned char *limit;
char *dest;

void init_vars() {
    // Allocate input data of approximately 64MB to achieve around 0.01s runtime on modern CPUs
    size_t input_size = 64 * 1024 * 1024;
    unsigned char *input_data = (unsigned char *)malloc(input_size);
    if (!input_data) exit(1);

    // Initialize with printable characters, include some \\ and \" sequences
    for (size_t i = 0; i < input_size; i++) {
        if (i < input_size - 1 && rand() % 32 == 0) {
            input_data[i] = '\\';
            i++;
            input_data[i] = (rand() % 2) ? '\\' : '"';
        } else {
            input_data[i] = 'a' + (rand() % 26);
        }
    }

    // Allocate output buffer (same size is safe because output <= input)
    dest = (char *)malloc(input_size);
    if (!dest) exit(1);

    // Initialize in structure
    in = (struct cpp_string *)malloc(sizeof(struct cpp_string));
    if (!in) exit(1);

    in->len = (unsigned int)input_size;
    in->text = input_data;

    // Initialize src and limit to valid values (though loop will set them)
    src = NULL;
    limit = NULL;
}