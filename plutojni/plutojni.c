#include "plutojni.h"
#include <plutosvg.h>

JNIEXPORT jlong JNICALL Java_meteordevelopment_pulsar_rendering_Svg_plutojni_1load_1from_1memory
  (JNIEnv* env, jclass class, jlong buffer, jint len, jlong font, jint width, jint height, jdouble dpi)
{
    const char* buffer_ = (const char*) (intptr_t) buffer;
    plutovg_font_t* font_ = (plutovg_font_t*) (intptr_t) font;
    return (jlong) (intptr_t) plutosvg_load_from_memory(buffer_, len, font_, width, height, dpi);
}

JNIEXPORT jlong JNICALL Java_meteordevelopment_pulsar_rendering_Svg_plutojni_1surface_1get_1data
  (JNIEnv* env, jclass class, jlong surface)
{
    plutovg_surface_t* surface_ = (plutovg_surface_t*) (intptr_t) surface;
    return (jlong) (intptr_t) plutovg_surface_get_data(surface_);
}

JNIEXPORT void JNICALL Java_meteordevelopment_pulsar_rendering_Svg_plutojni_1surface_1destroy
  (JNIEnv* env, jclass class, jlong surface)
{
    plutovg_surface_t* surface_ = (plutovg_surface_t*) (intptr_t) surface;
    plutovg_surface_destroy(surface_);
}