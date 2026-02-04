#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
enum AVOptionType {
    AV_OPT_TYPE_FLAGS,
    AV_OPT_TYPE_INT,
    AV_OPT_TYPE_INT64,
    AV_OPT_TYPE_DOUBLE,
    AV_OPT_TYPE_FLOAT,
    AV_OPT_TYPE_STRING,
    AV_OPT_TYPE_RATIONAL,
    AV_OPT_TYPE_BINARY,
    AV_OPT_TYPE_DICT,
    AV_OPT_TYPE_UINT64,
    AV_OPT_TYPE_CONST,
    AV_OPT_TYPE_IMAGE_SIZE,
    AV_OPT_TYPE_PIXEL_FMT,
    AV_OPT_TYPE_SAMPLE_FMT,
    AV_OPT_TYPE_VIDEO_RATE,
    AV_OPT_TYPE_DURATION,
    AV_OPT_TYPE_COLOR,
    AV_OPT_TYPE_CHANNEL_LAYOUT,
    AV_OPT_TYPE_BOOL
};


typedef struct AVRational {
    int num;
    int den;
} AVRational;

union {
    int64_t i64;
    double dbl;
    const char *str;
    AVRational q;
};


struct AVOption {
    const char *name;
    const char *help;
    int offset;
    enum AVOptionType type;
    union {
        int64_t i64;
        double dbl;
        const char *str;
        AVRational q;
    } default_val;
    double min;
    double max;
    int flags;
    const char *unit;
};


typedef enum {
    AV_CLASS_CATEGORY_NA = 0,
    AV_CLASS_CATEGORY_INPUT,
    AV_CLASS_CATEGORY_OUTPUT,
    AV_CLASS_CATEGORY_MUXER,
    AV_CLASS_CATEGORY_DEMUXER,
    AV_CLASS_CATEGORY_ENCODER,
    AV_CLASS_CATEGORY_DECODER,
    AV_CLASS_CATEGORY_FILTER,
    AV_CLASS_CATEGORY_BITSTREAM_FILTER,
    AV_CLASS_CATEGORY_SWSCALER,
    AV_CLASS_CATEGORY_SWRESAMPLER,
    AV_CLASS_CATEGORY_DEVICE_VIDEO_OUTPUT = 40,
    AV_CLASS_CATEGORY_DEVICE_VIDEO_INPUT,
    AV_CLASS_CATEGORY_DEVICE_AUDIO_OUTPUT,
    AV_CLASS_CATEGORY_DEVICE_AUDIO_INPUT,
    AV_CLASS_CATEGORY_DEVICE_OUTPUT,
    AV_CLASS_CATEGORY_DEVICE_INPUT,
    AV_CLASS_CATEGORY_NB
} AVClassCategory;

typedef struct AVClass {
    const char *class_name;
    const char *(*item_name)(void *);
    const struct AVOption *option;
    int version;
    int log_level_offset_offset;
    int parent_log_context_offset;
    void *(*child_next)(void *, void *);
    const struct AVClass *(*child_class_next)(const struct AVClass *);
    AVClassCategory category;
    AVClassCategory (*get_category)(void *);
    int (*query_ranges)(struct AVOptionRanges **, void *, const char *, int);
} AVClass;

typedef struct AVBuffer AVBuffer;

typedef struct AVBufferRef {
    AVBuffer *buffer;
    uint8_t *data;
    int size;
} AVBufferRef;

typedef struct AVHWDeviceInternal AVHWDeviceInternal;

enum AVHWDeviceType {
    AV_HWDEVICE_TYPE_NONE,
    AV_HWDEVICE_TYPE_VDPAU,
    AV_HWDEVICE_TYPE_CUDA,
    AV_HWDEVICE_TYPE_VAAPI,
    AV_HWDEVICE_TYPE_DXVA2,
    AV_HWDEVICE_TYPE_QSV,
    AV_HWDEVICE_TYPE_VIDEOTOOLBOX,
    AV_HWDEVICE_TYPE_D3D11VA,
    AV_HWDEVICE_TYPE_DRM,
    AV_HWDEVICE_TYPE_OPENCL,
    AV_HWDEVICE_TYPE_MEDIACODEC,
    AV_HWDEVICE_TYPE_VULKAN
};


typedef struct AVHWDeviceContext {
    const AVClass *av_class;
    AVHWDeviceInternal *internal;
    enum AVHWDeviceType type;
    void *hwctx;
    void (*free)(struct AVHWDeviceContext *);
    void *user_opaque;
} AVHWDeviceContext;

typedef struct AVOpenCLDeviceContext {
    int device_id;
    int context;
    int command_queue;
} AVOpenCLDeviceContext;

enum AVPixelFormat {
    AV_PIX_FMT_NONE = -1,
    AV_PIX_FMT_YUV420P,
    AV_PIX_FMT_YUYV422,
    AV_PIX_FMT_RGB24,
    AV_PIX_FMT_BGR24,
    AV_PIX_FMT_YUV422P,
    AV_PIX_FMT_YUV444P,
    AV_PIX_FMT_YUV410P,
    AV_PIX_FMT_YUV411P,
    AV_PIX_FMT_GRAY8,
    AV_PIX_FMT_MONOWHITE,
    AV_PIX_FMT_MONOBLACK,
    AV_PIX_FMT_PAL8,
    AV_PIX_FMT_YUVJ420P,
    AV_PIX_FMT_YUVJ422P,
    AV_PIX_FMT_YUVJ444P,
    AV_PIX_FMT_UYVY422,
    AV_PIX_FMT_UYYVYY411,
    AV_PIX_FMT_BGR8,
    AV_PIX_FMT_BGR4,
    AV_PIX_FMT_BGR4_BYTE,
    AV_PIX_FMT_RGB8,
    AV_PIX_FMT_RGB4,
    AV_PIX_FMT_RGB4_BYTE,
    AV_PIX_FMT_NV12,
    AV_PIX_FMT_NV21,
    AV_PIX_FMT_ARGB,
    AV_PIX_FMT_RGBA,
    AV_PIX_FMT_ABGR,
    AV_PIX_FMT_BGRA,
    AV_PIX_FMT_GRAY16BE,
    AV_PIX_FMT_GRAY16LE,
    AV_PIX_FMT_YUV440P,
    AV_PIX_FMT_YUVJ440P,
    AV_PIX_FMT_YUVA420P,
    AV_PIX_FMT_RGB48BE,
    AV_PIX_FMT_RGB48LE,
    AV_PIX_FMT_RGB565BE,
    AV_PIX_FMT_RGB565LE,
    AV_PIX_FMT_RGB555BE,
    AV_PIX_FMT_RGB555LE,
    AV_PIX_FMT_BGR565BE,
    AV_PIX_FMT_BGR565LE,
    AV_PIX_FMT_BGR555BE,
    AV_PIX_FMT_BGR555LE,
    AV_PIX_FMT_VAAPI_MOCO,
    AV_PIX_FMT_VAAPI_IDCT,
    AV_PIX_FMT_VAAPI_VLD,
    AV_PIX_FMT_VAAPI = AV_PIX_FMT_VAAPI_VLD,
    AV_PIX_FMT_YUV420P16LE,
    AV_PIX_FMT_YUV420P16BE,
    AV_PIX_FMT_YUV422P16LE,
    AV_PIX_FMT_YUV422P16BE,
    AV_PIX_FMT_YUV444P16LE,
    AV_PIX_FMT_YUV444P16BE,
    AV_PIX_FMT_DXVA2_VLD,
    AV_PIX_FMT_RGB444LE,
    AV_PIX_FMT_RGB444BE,
    AV_PIX_FMT_BGR444LE,
    AV_PIX_FMT_BGR444BE,
    AV_PIX_FMT_YA8,
    AV_PIX_FMT_Y400A = AV_PIX_FMT_YA8,
    AV_PIX_FMT_GRAY8A = AV_PIX_FMT_YA8,
    AV_PIX_FMT_BGR48BE,
    AV_PIX_FMT_BGR48LE,
    AV_PIX_FMT_YUV420P9BE,
    AV_PIX_FMT_YUV420P9LE,
    AV_PIX_FMT_YUV420P10BE,
    AV_PIX_FMT_YUV420P10LE,
    AV_PIX_FMT_YUV422P10BE,
    AV_PIX_FMT_YUV422P10LE,
    AV_PIX_FMT_YUV444P9BE,
    AV_PIX_FMT_YUV444P9LE,
    AV_PIX_FMT_YUV444P10BE,
    AV_PIX_FMT_YUV444P10LE,
    AV_PIX_FMT_YUV422P9BE,
    AV_PIX_FMT_YUV422P9LE,
    AV_PIX_FMT_GBRP,
    AV_PIX_FMT_GBR24P = AV_PIX_FMT_GBRP,
    AV_PIX_FMT_GBRP9BE,
    AV_PIX_FMT_GBRP9LE,
    AV_PIX_FMT_GBRP10BE,
    AV_PIX_FMT_GBRP10LE,
    AV_PIX_FMT_GBRP16BE,
    AV_PIX_FMT_GBRP16LE,
    AV_PIX_FMT_YUVA422P,
    AV_PIX_FMT_YUVA444P,
    AV_PIX_FMT_YUVA420P9BE,
    AV_PIX_FMT_YUVA420P9LE,
    AV_PIX_FMT_YUVA422P9BE,
    AV_PIX_FMT_YUVA422P9LE,
    AV_PIX_FMT_YUVA444P9BE,
    AV_PIX_FMT_YUVA444P9LE,
    AV_PIX_FMT_YUVA420P10BE,
    AV_PIX_FMT_YUVA420P10LE,
    AV_PIX_FMT_YUVA422P10BE,
    AV_PIX_FMT_YUVA422P10LE,
    AV_PIX_FMT_YUVA444P10BE,
    AV_PIX_FMT_YUVA444P10LE,
    AV_PIX_FMT_YUVA420P16BE,
    AV_PIX_FMT_YUVA420P16LE,
    AV_PIX_FMT_YUVA422P16BE,
    AV_PIX_FMT_YUVA422P16LE,
    AV_PIX_FMT_YUVA444P16BE,
    AV_PIX_FMT_YUVA444P16LE,
    AV_PIX_FMT_VDPAU,
    AV_PIX_FMT_XYZ12LE,
    AV_PIX_FMT_XYZ12BE,
    AV_PIX_FMT_NV16,
    AV_PIX_FMT_NV20LE,
    AV_PIX_FMT_NV20BE,
    AV_PIX_FMT_RGBA64BE,
    AV_PIX_FMT_RGBA64LE,
    AV_PIX_FMT_BGRA64BE,
    AV_PIX_FMT_BGRA64LE,
    AV_PIX_FMT_YVYU422,
    AV_PIX_FMT_YA16BE,
    AV_PIX_FMT_YA16LE,
    AV_PIX_FMT_GBRAP,
    AV_PIX_FMT_GBRAP16BE,
    AV_PIX_FMT_GBRAP16LE,
    AV_PIX_FMT_QSV,
    AV_PIX_FMT_MMAL,
    AV_PIX_FMT_D3D11VA_VLD,
    AV_PIX_FMT_CUDA,
    AV_PIX_FMT_0RGB,
    AV_PIX_FMT_RGB0,
    AV_PIX_FMT_0BGR,
    AV_PIX_FMT_BGR0,
    AV_PIX_FMT_YUV420P12BE,
    AV_PIX_FMT_YUV420P12LE,
    AV_PIX_FMT_YUV420P14BE,
    AV_PIX_FMT_YUV420P14LE,
    AV_PIX_FMT_YUV422P12BE,
    AV_PIX_FMT_YUV422P12LE,
    AV_PIX_FMT_YUV422P14BE,
    AV_PIX_FMT_YUV422P14LE,
    AV_PIX_FMT_YUV444P12BE,
    AV_PIX_FMT_YUV444P12LE,
    AV_PIX_FMT_YUV444P14BE,
    AV_PIX_FMT_YUV444P14LE,
    AV_PIX_FMT_GBRP12BE,
    AV_PIX_FMT_GBRP12LE,
    AV_PIX_FMT_GBRP14BE,
    AV_PIX_FMT_GBRP14LE,
    AV_PIX_FMT_YUVJ411P,
    AV_PIX_FMT_BAYER_BGGR8,
    AV_PIX_FMT_BAYER_RGGB8,
    AV_PIX_FMT_BAYER_GBRG8,
    AV_PIX_FMT_BAYER_GRBG8,
    AV_PIX_FMT_BAYER_BGGR16LE,
    AV_PIX_FMT_BAYER_BGGR16BE,
    AV_PIX_FMT_BAYER_RGGB16LE,
    AV_PIX_FMT_BAYER_RGGB16BE,
    AV_PIX_FMT_BAYER_GBRG16LE,
    AV_PIX_FMT_BAYER_GBRG16BE,
    AV_PIX_FMT_BAYER_GRBG16LE,
    AV_PIX_FMT_BAYER_GRBG16BE,
    AV_PIX_FMT_XVMC,
    AV_PIX_FMT_YUV440P10LE,
    AV_PIX_FMT_YUV440P10BE,
    AV_PIX_FMT_YUV440P12LE,
    AV_PIX_FMT_YUV440P12BE,
    AV_PIX_FMT_AYUV64LE,
    AV_PIX_FMT_AYUV64BE,
    AV_PIX_FMT_VIDEOTOOLBOX,
    AV_PIX_FMT_P010LE,
    AV_PIX_FMT_P010BE,
    AV_PIX_FMT_GBRAP12BE,
    AV_PIX_FMT_GBRAP12LE,
    AV_PIX_FMT_GBRAP10BE,
    AV_PIX_FMT_GBRAP10LE,
    AV_PIX_FMT_MEDIACODEC,
    AV_PIX_FMT_GRAY12BE,
    AV_PIX_FMT_GRAY12LE,
    AV_PIX_FMT_GRAY10BE,
    AV_PIX_FMT_GRAY10LE,
    AV_PIX_FMT_P016LE,
    AV_PIX_FMT_P016BE,
    AV_PIX_FMT_D3D11,
    AV_PIX_FMT_GRAY9BE,
    AV_PIX_FMT_GRAY9LE,
    AV_PIX_FMT_GBRPF32BE,
    AV_PIX_FMT_GBRPF32LE,
    AV_PIX_FMT_GBRAPF32BE,
    AV_PIX_FMT_GBRAPF32LE,
    AV_PIX_FMT_DRM_PRIME,
    AV_PIX_FMT_OPENCL,
    AV_PIX_FMT_GRAY14BE,
    AV_PIX_FMT_GRAY14LE,
    AV_PIX_FMT_GRAYF32BE,
    AV_PIX_FMT_GRAYF32LE,
    AV_PIX_FMT_YUVA422P12BE,
    AV_PIX_FMT_YUVA422P12LE,
    AV_PIX_FMT_YUVA444P12BE,
    AV_PIX_FMT_YUVA444P12LE,
    AV_PIX_FMT_NV24,
    AV_PIX_FMT_NV42,
    AV_PIX_FMT_VULKAN,
    AV_PIX_FMT_Y210BE,
    AV_PIX_FMT_Y210LE,
    AV_PIX_FMT_NB
};


typedef struct OpenCLFilterContext {
    const AVClass *class;
    AVBufferRef *device_ref;
    AVHWDeviceContext *device;
    AVOpenCLDeviceContext *hwctx;
    int program;
    enum AVPixelFormat output_format;
    int output_width;
    int output_height;
} OpenCLFilterContext;

typedef struct FilterParam {
    int radius;
    int power;
    char *radius_expr;
} FilterParam;

typedef struct AverageBlurOpenCLContext {
    OpenCLFilterContext ocf;
    int initialised;
    int kernel_horiz;
    int kernel_vert;
    int command_queue;
    int radiusH;
    int radiusV;
    int planes;
    FilterParam luma_param;
    FilterParam chroma_param;
    FilterParam alpha_param;
    int radius[4];
    int power[4];
} AverageBlurOpenCLContext;

extern AverageBlurOpenCLContext *s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int depth = 0; depth < 2; depth++) {
        for (i = 0; i < 4; i++) {
            if (s->power[i] == 0) {
                s->power[i] = 1;
                s->radius[i] = 0;
            }
        }
    }
}
