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

typedef struct asn1_string_st ASN1_BIT_STRING;

ASN1_BIT_STRING *a;
int len;

static unsigned char *data_buffer;

void init_vars() {
    const int buffer_size = 512 * 1024; // 512 KB data
    data_buffer = (unsigned char *)calloc(buffer_size, sizeof(unsigned char));
    if (!data_buffer) {
        exit(1);
    }

    // Initialize non-zero byte near the end to ensure loop breaks within bounds
    data_buffer[buffer_size - 1] = 1;

    a = (ASN1_BIT_STRING *)malloc(sizeof(ASN1_BIT_STRING));
    if (!a) {
        free(data_buffer);
        exit(1);
    }

    a->length = buffer_size;
    a->type = 0;
    a->data = data_buffer;
    a->flags = 0;

    len = a->length;
}