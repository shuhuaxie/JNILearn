#include <jni.h>
#include <cstdio>

JavaVM *g_jvm;

jstring getString()
{
    JNIEnv *env = NULL;
    g_jvm->AttachCurrentThread(&env, NULL); //g_jvm为JavaVM指针

    return env->NewStringUTF("This string is from method by register!");
}

static JNINativeMethod methods[] = {
        {"methodByRegister", "()Ljava/lang/String;", reinterpret_cast<void*>(getString)}
};


JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
    JNIEnv* env = NULL;
    g_jvm = vm;
    if (JNI_OK != vm->GetEnv(reinterpret_cast<void**> (&env),JNI_VERSION_1_4)) {
//        LOGW("JNI_OnLoad could not get JNI env");
        return JNI_ERR;
    }
    jclass clazz = env->FindClass("jeep/jniLearn/JNIMethods");

    env->RegisterNatives(clazz, methods, sizeof(methods)/sizeof((methods)[0]) );
    return JNI_VERSION_1_4;
}
