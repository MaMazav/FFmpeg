#include <stdlib.h>
#include <stdio.h>
#include "ffplay_entrypoint.h"

const char program_name[] = "ffplay_vims_extractor";
const int program_birth_year = 2015;

void print_metadata(uint8_t service_id, int64_t pts, char *arr, int arr_size);

int main(int argc, char **argv) {
    int returnCode;

    printf("******************************* IDAN\'s ffmpeg *******************************\n");
    set_data_callback_func(print_metadata);
    returnCode = entryPoint(argc, argv, /*is_leon=*/1, /*show_video=*/0);
    printf("******************************* IDAN\'s ffmpeg *******************************\n");

    if (returnCode < 0)
        exit(1);

    return 0;
}

void print_metadata(uint8_t service_id, int64_t pts, char *arr, int arr_size) {
    printf("Packet: service_id=%d, pts=%" PRId64 ", data: %s\n\n", service_id, pts, arr);
}
