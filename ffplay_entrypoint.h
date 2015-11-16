#ifndef FFPLAY_ENTRYPOINT_H
#define FFPLAY_ENTRYPOINT_H

#include <inttypes.h>

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

#define FFPLAY_WRAPPER_API EXTERNC
#define __stdcall
#define __cdecl

typedef struct {
    //uint8_t *data[AV_NUM_DATA_POINTERS];
    uint8_t **data;
    int width;
    int height;
    int type;
    //int linesize[AV_NUM_DATA_POINTERS];
    int *linesize;
} MyFrame;

typedef void (*data_clbk_ptr)(uint8_t service_id, int64_t pts, char *arr, int arr_size);
typedef void (*frame_clbk_ptr)(int64_t pts, MyFrame* frame);
typedef void (*mouse_click_clbk_ptr)(uint16_t x, uint16_t y, uint8_t button);

FFPLAY_WRAPPER_API void __stdcall start(int argc, char** argv, int show_video);
FFPLAY_WRAPPER_API void __stdcall close(void);
FFPLAY_WRAPPER_API void __cdecl set_data_callback_func(data_clbk_ptr callback_func);
FFPLAY_WRAPPER_API void __cdecl set_frame_callback_func(frame_clbk_ptr frame_callback_func);
FFPLAY_WRAPPER_API void __cdecl set_mouse_click_callback_func(mouse_click_clbk_ptr mouse_click_callback_func);
FFPLAY_WRAPPER_API void __stdcall load(void);
FFPLAY_WRAPPER_API void __stdcall stab_pixel(int x, int y);

int entryPoint(int argc, char **argv, int is_leon, int show_video);

#endif /* FFPLAY_ENTRYPOINT_H */
