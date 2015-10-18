// LEON

#include "libavutil/avassert.h"
#include "libavutil/display.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/stereo3d.h"
#include "libavutil/timer.h"
#include "avcodec.h"

/*
#include "internal.h"
#include "cabac.h"
#include "cabac_functions.h"
#include "error_resilience.h"
*/
/*#include "h264.h"
#include "h264data.h"
#include "h264chroma.h"
#include "h264_mvpred.h"
#include "golomb.h"
#include "mathops.h"
#include "me_cmp.h"
#include "mpegutils.h"
#include "rectangle.h"
#include "svq3.h"
#include "thread.h"
#include "vdpau_compat.h"
*/

// LEON

av_cold int ff_vims_decode_init(AVCodecContext *avctx);

av_cold int ff_vims_decode_init(AVCodecContext *avctx)
{
	return 0;
}

static av_cold int vims_decode_end(AVCodecContext *avctx)
{
	/*
	H264Context *h = avctx->priv_data;

	ff_h264_remove_all_refs(h);
	ff_h264_free_context(h);

	ff_h264_unref_picture(h, &h->cur_pic);
	av_frame_free(&h->cur_pic.f);
	ff_h264_unref_picture(h, &h->last_pic_for_ec);
	av_frame_free(&h->last_pic_for_ec.f);
	*/
	return 0;
}

static int vims_decode_data(AVCodecContext *avctx, void *data,
	int *got_frame, AVPacket *avpkt)
{
	return 0;
}

typedef struct VIMSContext {
	int len;
	char* data;
} VIMSContext;

AVCodec ff_vims_decoder = {
	.name = "vims",
	.long_name = NULL_IF_CONFIG_SMALL("Video metadata stream (VIMS)"),
	.type = AVMEDIA_TYPE_DATA,
	.id = AV_CODEC_ID_VIMS,
	.priv_data_size = sizeof(VIMSContext),
	.init = ff_vims_decode_init,
	.close = vims_decode_end,
	.decode = vims_decode_data,
};
