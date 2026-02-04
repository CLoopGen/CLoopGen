#include <stdio.h>

#include <inttypes.h>

struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};


typedef struct asn1_string_st ASN1_OCTET_STRING;

extern  unsigned char *opp;
extern ASN1_OCTET_STRING *os;
extern int i;
extern int printable;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    for (i = 0; i < os->length; i += stride) {
        if (((opp[i] < ' ') && (opp[i] != '\n') && (opp[i] != '\r') && (opp[i] != '\t')) || (opp[i] > '~')) {
            printable = 0;
            break;
        }
        if (i + 1 < os->length) {
            if (((opp[i + 1] < ' ') && (opp[i + 1] != '\n') && (opp[i + 1] != '\r') && (opp[i + 1] != '\t')) || (opp[i + 1] > '~')) {
                printable = 0;
                break;
            }
        }
    }
}
