//
// Created by alex on 09.08.2022.
//

#define RGBCX_IMPLEMENTATION
#include "rgbcx.h"
#include "bc7enc.h"
#include "bc7decomp.h"
#include <math.h>
#include <atomic>

extern "C"{
    #define MAX_CONCURRENT_PARAMS 128

    static bc7enc_compress_block_params compress_params[128];
    static std::atomic<int> current_params(0);
    static bool bc7enc_initialized = false;

    int bc7_init(int perceptual, int max_partitions, int uber_level){
        //Interlocked.Increment should be here.
        auto was = current_params++;
        auto v = std::abs(was % MAX_CONCURRENT_PARAMS);

        bc7enc_compress_block_params *params = compress_params + v;
        bc7enc_compress_block_params_init(params);

        if (!perceptual)
            bc7enc_compress_block_params_init_linear_weights(params);

        params->m_max_partitions_mode = std::max(std::min(max_partitions, BC7ENC_MAX_PARTITIONS1), 0);
        params->m_uber_level = std::max(std::min(BC7ENC_MAX_UBER_LEVEL, uber_level), 0);

        if(!bc7enc_initialized){
            bc7enc_initialized = true;
            bc7enc_compress_block_init();
        }

        return v;
    }

    void bc7_decode(void *output_rgba, const uint8_t *input_block){
        bc7decomp::unpack_bc7(input_block, (bc7decomp::color_rgba*)output_rgba);
    }

    void bc7_encode(int settings_id, void *output_block, uint8_t* rgba_pixels){
        auto v = std::abs(settings_id % MAX_CONCURRENT_PARAMS);
        bc7enc_compress_block_params *settings = compress_params + v;

        bc7enc_compress_block(output_block, rgba_pixels, settings);
    }

    void bcenc_init(int approx_mode){
        rgbcx::init((rgbcx::bc1_approx_mode)approx_mode);
    }

    void bcenc_encode_dxt1(int quality_level, void *output_block, uint8_t *rgba_pixels){
        rgbcx::encode_bc1(quality_level, output_block, rgba_pixels, false, true);
    }

    void bcenc_encode_dxt5(int quality_level, void *output_block, uint8_t *rgba_pixels){
        rgbcx::encode_bc3(quality_level, output_block, rgba_pixels);
    }
}