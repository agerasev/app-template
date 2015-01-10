#include <jni.h>

void view_init();
// void view_close();
void view_resize(int width, int height);
void view_render();

JNIEXPORT void JNICALL Java_com_$author_$name_Renderer_init(JNIEnv *env, jobject *obj)
{
	view_init();
}

JNIEXPORT void JNICALL Java_com_$author_$name_Renderer_resize(JNIEnv *env, jobject *obj, jint width, jint height)
{
	view_resize(width,height);
}

JNIEXPORT void JNICALL Java_com_$author_$name_Renderer_render(JNIEnv *env, jobject *obj)
{
	view_render();
}
