#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};

typedef struct asn1_string_st ASN1_UNIVERSALSTRING;

ASN1_UNIVERSALSTRING *s;
int i;
unsigned char *p;

void init_vars() {
    const int data_size = 512 * 1024; // 512 KB of data

    s = (ASN1_UNIVERSALSTRING *)malloc(sizeof(ASN1_UNIVERSALSTRING));
    s->data = (unsigned char *)malloc(data_size * sizeof(unsigned char));
    s->length = data_size;
    s->type = 0;
    s->flags = 0;

    p = (unsigned char *)malloc(data_size * sizeof(unsigned char));

    for (int j = 0; j < data_size; ++j) {
        s->data[j] = (unsigned char)(j & 0xFF);
    }
}