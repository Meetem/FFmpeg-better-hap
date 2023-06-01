# You can't build anything with this file
# It's there for provide intellisense for CLion

cmake_minimum_required(VERSION 3.0)

project(FFmpegExamples)

include_directories(.)
include_directories(fftools)
include_directories(libavcodec)
include_directories(libavdevice)
include_directories(libavformat)
include_directories(libavfilter)
include_directories(libavutil)
include_directories(libpostproc)
include_directories(libswscale)
include_directories(libswresample)

file(GLOB SOURCES CONFIGURE_DEPENDS "fftools/*.c")
file(GLOB AVCODEC CONFIGURE_DEPENDS "libavcodec/*.c")
file(GLOB AVDEVICE CONFIGURE_DEPENDS "libavdevice/*.c")
file(GLOB AVFORMAT CONFIGURE_DEPENDS "libavformat/*.c")
file(GLOB AVFILTER CONFIGURE_DEPENDS "libavfilter/*.c")
file(GLOB AVUTIL CONFIGURE_DEPENDS "libavutil/*.c")
file(GLOB AVPOSTPROC CONFIGURE_DEPENDS "libpostproc/*.c")
file(GLOB SWSCALE CONFIGURE_DEPENDS "libswscale/*.c")
file(GLOB SWRESAMPLE CONFIGURE_DEPENDS "libswresample/*.c")

add_executable(ffmpeg_tools ${SOURCES} ${AVCODEC} ${AVDEVICE} ${AVFORMAT} ${AVFILTER} ${AVUTIL} ${AVPOSTPROC} ${SWSCALE} ${SWRESAMPLE}
        libavcodec/bc7enc/bcenc_compat.cpp
        libavcodec/bc7enc/bc7decomp.cpp
        libavcodec/bc7enc/bc7enc.c
        libavcodec/bc7enc/rgbcx.h
        )