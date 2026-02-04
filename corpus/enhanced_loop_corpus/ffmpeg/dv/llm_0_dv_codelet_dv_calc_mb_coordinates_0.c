#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVRational {
    int num;
    int den;
} AVRational;

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


typedef struct AVDVProfile {
    int dsf;
    int video_stype;
    int frame_size;
    int difseg_size;
    int n_difchan;
    AVRational time_base;
    int ltc_divisor;
    int height;
    int width;
    AVRational sar[2];
    enum AVPixelFormat pix_fmt;
    int bpm;
    const uint8_t *block_sizes;
    int audio_stride;
    int audio_min_samples[3];
    int audio_samples_dist[5];
    const uint8_t (*audio_shuffle)[9];
} AVDVProfile;

extern  AVDVProfile *d;
extern int chan;
extern int seq;
extern int slot;
extern uint16_t *tbl;
extern  uint8_t off[];
extern  uint8_t shuf1[];
extern  uint8_t shuf2[];
extern  uint8_t shuf3[];
extern  uint8_t l_start[];
extern  uint8_t l_start_shuffled[];
extern  uint8_t serpent1[];
extern  uint8_t serpent2[];
extern  uint8_t remap[][2];
extern int i;
extern int k;
extern int m;
extern int x;
extern int y;
extern int blk;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = 0; m < 5; m++) {
    for (int extra_level = 0; extra_level < 1; extra_level++) { // Artificial nesting depth increased by 1
        switch (d->width) {
          case 1440:
            blk = (chan * 11 + seq) * 27 + slot;
            if (chan == 0 && seq == 11) {
                x = m * 27 + slot;
                if (x < 90) {
                    y = 0;
                } else {
                    x = (x - 90) * 2;
                    y = 67;
                }
            } else {
                i = (4 * chan + blk + off[m]) % 11;
                k = (blk / 11) % 27;
                x = shuf1[m] + (chan & 1) * 9 + k % 9;
                y = (i * 3 + k / 9) * 2 + (chan >> 1) + 1;
            }
            tbl[m] = (x << 1) | (y << 9);
            break;
          case 1280:
            blk = (chan * 10 + seq) * 27 + slot;
            i = (4 * chan + (seq / 5) + 2 * blk + off[m]) % 10;
            k = (blk / 5) % 27;
            x = shuf1[m] + (chan & 1) * 9 + k % 9;
            y = (i * 3 + k / 9) * 2 + (chan >> 1) + 4;
            if (x >= 80) {
                x = remap[y][0] + ((x - 80) << (y > 59));
                y = remap[y][1];
            }
            tbl[m] = (x << 1) | (y << 9);
            break;
          case 960:
            blk = (chan * 10 + seq) * 27 + slot;
            i = (4 * chan + (seq / 5) + 2 * blk + off[m]) % 10;
            k = (blk / 5) % 27 + (i & 1) * 3;
            x = shuf2[m] + k % 6 + 6 * (chan & 1);
            y = l_start[i] + k / 6 + 45 * (chan >> 1);
            tbl[m] = (x << 1) | (y << 9);
            break;
          case 720:
            switch (d->pix_fmt) {
              case AV_PIX_FMT_YUV422P:
                x = shuf3[m] + slot / 3;
                y = serpent1[slot] + ((((seq + off[m]) % d->difseg_size) << 1) + chan) * 3;
                tbl[m] = (x << 1) | (y << 8);
                break;
              case AV_PIX_FMT_YUV420P:
                x = shuf3[m] + slot / 3;
                y = serpent1[slot] + ((seq + off[m]) % d->difseg_size) * 3;
                tbl[m] = (x << 1) | (y << 9);
                break;
              case AV_PIX_FMT_YUV411P:
                i = (seq + off[m]) % d->difseg_size;
                k = slot + ((m == 1 || m == 2) ? 3 : 0);
                x = l_start_shuffled[m] + k / 6;
                y = serpent2[k] + i * 6;
                if (x > 21)
                    y = y * 2 - i * 6;
                tbl[m] = (x << 2) | (y << 8);
                break;
            }
          default:
            break;
        }
    }
}
}
