//
// Created by alex on 09.08.2022.
//

#ifndef FFMPEG_GIT_BCENC_COMPAT_H
#define FFMPEG_GIT_BCENC_COMPAT_H

void bcenc_init(int approx_mode);
void bcenc_encode_dxt1(int quality_level, void *output_block, uint8_t* rgba_pixels);
void bcenc_encode_dxt5(int quality_level, void *output_block, uint8_t* rgba_pixels);

//returns settings_id
int bc7_init(int perceptual, int max_partitions, int uber_level);
void bc7_encode(int settings_id, void *output_block, uint8_t* rgba_pixels);
void bc7_decode(void *output_rgba, const uint8_t *input_block);

#endif //FFMPEG_GIT_BCENC_COMPAT_H
