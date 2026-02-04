#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union {
    int toff_short;
    int toff_long;
    int toff_long8;
};

typedef struct {
    int tdir_tag;
    int tdir_type;
    int tdir_count;
    union {
        int toff_short;
        int toff_long;
        int toff_long8;
    } tdir_offset;
    int tdir_ignore;
} TIFFDirEntry;

typedef enum {
    TIFF_NOTYPE = 0,
    TIFF_BYTE = 1,
    TIFF_ASCII = 2,
    TIFF_SHORT = 3,
    TIFF_LONG = 4,
    TIFF_RATIONAL = 5,
    TIFF_SBYTE = 6,
    TIFF_UNDEFINED = 7,
    TIFF_SSHORT = 8,
    TIFF_SLONG = 9,
    TIFF_SRATIONAL = 10,
    TIFF_FLOAT = 11,
    TIFF_DOUBLE = 12,
    TIFF_IFD = 13,
    TIFF_LONG8 = 16,
    TIFF_SLONG8 = 17,
    TIFF_IFD8 = 18
} TIFFDataType;

typedef enum {
    TIFF_SETGET_UNDEFINED = 0,
    TIFF_SETGET_ASCII = 1,
    TIFF_SETGET_UINT8 = 2,
    TIFF_SETGET_SINT8 = 3,
    TIFF_SETGET_UINT16 = 4,
    TIFF_SETGET_SINT16 = 5,
    TIFF_SETGET_UINT32 = 6,
    TIFF_SETGET_SINT32 = 7,
    TIFF_SETGET_UINT64 = 8,
    TIFF_SETGET_SINT64 = 9,
    TIFF_SETGET_FLOAT = 10,
    TIFF_SETGET_DOUBLE = 11,
    TIFF_SETGET_IFD8 = 12,
    TIFF_SETGET_INT = 13,
    TIFF_SETGET_UINT16_PAIR = 14,
    TIFF_SETGET_C0_ASCII = 15,
    TIFF_SETGET_C0_UINT8 = 16,
    TIFF_SETGET_C0_SINT8 = 17,
    TIFF_SETGET_C0_UINT16 = 18,
    TIFF_SETGET_C0_SINT16 = 19,
    TIFF_SETGET_C0_UINT32 = 20,
    TIFF_SETGET_C0_SINT32 = 21,
    TIFF_SETGET_C0_UINT64 = 22,
    TIFF_SETGET_C0_SINT64 = 23,
    TIFF_SETGET_C0_FLOAT = 24,
    TIFF_SETGET_C0_DOUBLE = 25,
    TIFF_SETGET_C0_IFD8 = 26,
    TIFF_SETGET_C16_ASCII = 27,
    TIFF_SETGET_C16_UINT8 = 28,
    TIFF_SETGET_C16_SINT8 = 29,
    TIFF_SETGET_C16_UINT16 = 30,
    TIFF_SETGET_C16_SINT16 = 31,
    TIFF_SETGET_C16_UINT32 = 32,
    TIFF_SETGET_C16_SINT32 = 33,
    TIFF_SETGET_C16_UINT64 = 34,
    TIFF_SETGET_C16_SINT64 = 35,
    TIFF_SETGET_C16_FLOAT = 36,
    TIFF_SETGET_C16_DOUBLE = 37,
    TIFF_SETGET_C16_IFD8 = 38,
    TIFF_SETGET_C32_ASCII = 39,
    TIFF_SETGET_C32_UINT8 = 40,
    TIFF_SETGET_C32_SINT8 = 41,
    TIFF_SETGET_C32_UINT16 = 42,
    TIFF_SETGET_C32_SINT16 = 43,
    TIFF_SETGET_C32_UINT32 = 44,
    TIFF_SETGET_C32_SINT32 = 45,
    TIFF_SETGET_C32_UINT64 = 46,
    TIFF_SETGET_C32_SINT64 = 47,
    TIFF_SETGET_C32_FLOAT = 48,
    TIFF_SETGET_C32_DOUBLE = 49,
    TIFF_SETGET_C32_IFD8 = 50,
    TIFF_SETGET_OTHER = 51
} TIFFSetGetFieldType;

typedef enum {
    tfiatImage,
    tfiatExif,
    tfiatGps,
    tfiatOther
} TIFFFieldArrayType;

typedef struct _TIFFField TIFFField;

struct _TIFFFieldArray {
    TIFFFieldArrayType type;
    int allocated_size;
    int count;
    TIFFField *fields;
};

typedef struct _TIFFFieldArray TIFFFieldArray;

struct _TIFFField {
    int field_tag;
    short field_readcount;
    short field_writecount;
    TIFFDataType field_type;
    int field_anonymous;
    TIFFSetGetFieldType set_get_field_type;
    unsigned short field_bit;
    unsigned char field_oktochange;
    unsigned char field_passcount;
    char *field_name;
    TIFFFieldArray *field_subfields;
};

typedef struct {
    const TIFFField *info;
    int count;
    void *value;
} TIFFTagValue;

typedef struct {
    int offset;
    int length;
} TIFFEntryOffsetAndLength;

typedef struct {
    int td_fieldsset[4];
    int td_imagewidth;
    int td_imagelength;
    int td_imagedepth;
    int td_tilewidth;
    int td_tilelength;
    int td_tiledepth;
    int td_subfiletype;
    int td_bitspersample;
    int td_sampleformat;
    int td_compression;
    int td_photometric;
    int td_threshholding;
    int td_fillorder;
    int td_orientation;
    int td_samplesperpixel;
    int td_rowsperstrip;
    int td_minsamplevalue;
    int td_maxsamplevalue;
    double *td_sminsamplevalue;
    double *td_smaxsamplevalue;
    float td_xresolution;
    float td_yresolution;
    int td_resolutionunit;
    int td_planarconfig;
    float td_xposition;
    float td_yposition;
    int td_pagenumber[2];
    int *td_colormap[3];
    int td_halftonehints[2];
    int td_extrasamples;
    int *td_sampleinfo;
    int td_stripsperimage;
    int td_nstrips;
    int *td_stripoffset_p;
    int *td_stripbytecount_p;
    int td_stripoffsetbyteallocsize;
    TIFFDirEntry td_stripoffset_entry;
    TIFFDirEntry td_stripbytecount_entry;
    int td_nsubifd;
    int *td_subifd;
    int td_ycbcrsubsampling[2];
    int td_ycbcrpositioning;
    int *td_transferfunction[3];
    float *td_refblackwhite;
    int td_inknameslen;
    char *td_inknames;
    int td_numberofinks;
    int td_customValueCount;
    TIFFTagValue *td_customValues;
    unsigned char td_deferstrilearraywriting;
    unsigned char td_iswrittentofile;
    int td_dirdatasize_write;
    int td_dirdatasize_read;
    int td_dirdatasize_Noffsets;
    TIFFEntryOffsetAndLength *td_dirdatasize_offsets;
} TIFFDirectory;

static TIFFDirectory td_instance;
static TIFFTagValue* custom_values_buffer;
static int iCustom2_value;
static int iC2_value;

TIFFDirectory *td = &td_instance;
int iCustom2 = 0;
int iC2 = 0;

void init_vars() {
    iCustom2_value = 1000;
    iCustom2 = iCustom2_value;

    int value_count = 2000000;
    custom_values_buffer = (TIFFTagValue*)calloc(value_count + 1, sizeof(TIFFTagValue));
    
    for (int i = 0; i <= value_count; i++) {
        custom_values_buffer[i].info = NULL;
        custom_values_buffer[i].count = 0;
        custom_values_buffer[i].value = NULL;
    }

    td->td_customValueCount = value_count;
    td->td_customValues = custom_values_buffer;

    td->td_fieldsset[0] = 0;
    td->td_fieldsset[1] = 0;
    td->td_fieldsset[2] = 0;
    td->td_fieldsset[3] = 0;
    td->td_imagewidth = 1;
    td->td_imagelength = 1;
    td->td_imagedepth = 1;
    td->td_tilewidth = 1;
    td->td_tilelength = 1;
    td->td_tiledepth = 1;
    td->td_subfiletype = 0;
    td->td_bitspersample = 8;
    td->td_sampleformat = 1;
    td->td_compression = 1;
    td->td_photometric = 1;
    td->td_threshholding = 0;
    td->td_fillorder = 1;
    td->td_orientation = 1;
    td->td_samplesperpixel = 1;
    td->td_rowsperstrip = 1;
    td->td_minsamplevalue = 0;
    td->td_maxsamplevalue = 255;
    td->td_sminsamplevalue = NULL;
    td->td_smaxsamplevalue = NULL;
    td->td_xresolution = 1.0f;
    td->td_yresolution = 1.0f;
    td->td_resolutionunit = 1;
    td->td_planarconfig = 1;
    td->td_xposition = 0.0f;
    td->td_yposition = 0.0f;
    td->td_pagenumber[0] = 0;
    td->td_pagenumber[1] = 1;
    td->td_colormap[0] = NULL;
    td->td_colormap[1] = NULL;
    td->td_colormap[2] = NULL;
    td->td_halftonehints[0] = 0;
    td->td_halftonehints[1] = 0;
    td->td_extrasamples = 0;
    td->td_sampleinfo = NULL;
    td->td_stripsperimage = 1;
    td->td_nstrips = 1;
    td->td_stripoffset_p = NULL;
    td->td_stripbytecount_p = NULL;
    td->td_stripoffsetbyteallocsize = 0;
    td->td_stripoffset_entry.tdir_tag = 0;
    td->td_stripoffset_entry.tdir_type = 0;
    td->td_stripoffset_entry.tdir_count = 0;
    td->td_stripoffset_entry.tdir_offset.toff_long = 0;
    td->td_stripoffset_entry.tdir_ignore = 0;
    td->td_stripbytecount_entry.tdir_tag = 0;
    td->td_stripbytecount_entry.tdir_type = 0;
    td->td_stripbytecount_entry.tdir_count = 0;
    td->td_stripbytecount_entry.tdir_offset.toff_long = 0;
    td->td_stripbytecount_entry.tdir_ignore = 0;
    td->td_nsubifd = 0;
    td->td_subifd = NULL;
    td->td_ycbcrsubsampling[0] = 2;
    td->td_ycbcrsubsampling[1] = 2;
    td->td_ycbcrpositioning = 1;
    td->td_transferfunction[0] = NULL;
    td->td_transferfunction[1] = NULL;
    td->td_transferfunction[2] = NULL;
    td->td_refblackwhite = NULL;
    td->td_inknameslen = 0;
    td->td_inknames = NULL;
    td->td_numberofinks = 0;
    td->td_deferstrilearraywriting = 0;
    td->td_iswrittentofile = 0;
    td->td_dirdatasize_write = 0;
    td->td_dirdatasize_read = 0;
    td->td_dirdatasize_Noffsets = 0;
    td->td_dirdatasize_offsets = NULL;
}