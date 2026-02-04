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

typedef struct asn1_string_st ASN1_OCTET_STRING;

unsigned char *opp;
ASN1_OCTET_STRING *os;
int i;
int printable;

void init_vars() {
    const size_t data_size = 512 * 1024; // 512 KB of data

    opp = (unsigned char *)malloc(data_size);
    if (!opp) {
        exit(1);
    }

    os = (ASN1_OCTET_STRING *)malloc(sizeof(ASN1_OCTET_STRING));
    if (!os) {
        free(opp);
        exit(1);
    }

    os->data = opp;
    os->length = data_size;
    os->type = 0;
    os->flags = 0;

    for (size_t idx = 0; idx < data_size; idx++) {
        opp[idx] = (unsigned char)(' ' + (idx % (('~' - ' ') + 1)));
    }

    i = 0;
    printable = 1;
}