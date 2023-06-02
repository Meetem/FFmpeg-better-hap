This fork README
=============

This is modified version of ffmpeg which allows to decode/encode hap with the BC7 GPU format support. BC7 compressor is bc7enc https://github.com/richgel999/bc7enc 
Check ffmpeg help command to get descriptions for the new options.
It's also planned to implement LZ4 compression instead of snappy.

## Build
It should be possible to build this repo with slighly modified https://github.com/m-ab-s/media-autobuild_suite/ 
1. Change the ffmpegPath to https://github.com/Meetem/FFmpeg-better-hap.git#branch=better-hap
2. Highly recommended to set ffmpegUpdate to 3 (only update ffmpeg)
3. Apply those changes to media-suite_compile.sh:
    Line 1556:             do_vcs "$ffmpegPath" ffmpeg
    Line 2114:     if do_vcs "$ffmpegPath" ffmpeg; then
    Line 2306:         ! git clone "$ffmpegPath" ffmpeg; then
    Line 2589:         if flavor=cyan do_vcs "$ffmpegPath" ffmpeg; then
    
    Basic idea here is to fix clone behaviour to force cloning into ffmpeg-git folder instead of reponame-git folder.
4. Compile as usual.
# If you don't want to bother with setting this stuff up, just use [ff-build.7z](https://github.com/Meetem/FFmpeg-better-hap/blob/better-hap/ff-build-mod.7z)

FFmpeg README
=============

FFmpeg is a collection of libraries and tools to process multimedia content
such as audio, video, subtitles and related metadata.

## Libraries

* `libavcodec` provides implementation of a wider range of codecs.
* `libavformat` implements streaming protocols, container formats and basic I/O access.
* `libavutil` includes hashers, decompressors and miscellaneous utility functions.
* `libavfilter` provides means to alter decoded audio and video through a directed graph of connected filters.
* `libavdevice` provides an abstraction to access capture and playback devices.
* `libswresample` implements audio mixing and resampling routines.
* `libswscale` implements color conversion and scaling routines.

## Tools

* [ffmpeg](https://ffmpeg.org/ffmpeg.html) is a command line toolbox to
  manipulate, convert and stream multimedia content.
* [ffplay](https://ffmpeg.org/ffplay.html) is a minimalistic multimedia player.
* [ffprobe](https://ffmpeg.org/ffprobe.html) is a simple analysis tool to inspect
  multimedia content.
* Additional small tools such as `aviocat`, `ismindex` and `qt-faststart`.

## Documentation

The offline documentation is available in the **doc/** directory.

The online documentation is available in the main [website](https://ffmpeg.org)
and in the [wiki](https://trac.ffmpeg.org).

### Examples

Coding examples are available in the **doc/examples** directory.

## License

FFmpeg codebase is mainly LGPL-licensed with optional components licensed under
GPL. Please refer to the LICENSE file for detailed information.

## Contributing

Patches should be submitted to the ffmpeg-devel mailing list using
`git format-patch` or `git send-email`. Github pull requests should be
avoided because they are not part of our review process and will be ignored.
