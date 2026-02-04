#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};

typedef struct asn1_string_st ASN1_IA5STRING;

ASN1_IA5STRING *str;
int c;
int i;

static unsigned char *data_buffer;
static const int DATA_SIZE = 512 * 1024; // 512 KB

void init_vars() {
    data_buffer = (unsigned char *)calloc(DATA_SIZE, sizeof(unsigned char));
    if (!data_buffer) {
        exit(1);
    }

    for (int j = 0; j < DATA_SIZE - 1; j++) {
        data_buffer[j] = 'A'; // Fill with non-matching character
    }
    data_buffer[DATA_SIZE - 1] = 'B'; // Ensure last character is different

    str = (ASN1_IA5STRING *)malloc(sizeof(ASN1_IA5STRING));
    if (!str) {
        free(data_buffer);
        exit(1);
    }

    str->length = DATA_SIZE;
    str->type = 0;
    str->data = data_buffer;
    str->flags = 0;

    c = 'B'; // Set search character to match the last one
    i = 0;
}