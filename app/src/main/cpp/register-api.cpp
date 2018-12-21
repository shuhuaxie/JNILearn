#include <jni.h>
#include <cstdio>
#include <android/log.h>

JavaVM *g_jvm;

jstring getString() {
    va_list list;
    JNIEnv *env = NULL;
//    va_start(list, 1);
//    va_end(list);
    g_jvm->AttachCurrentThread(&env, NULL); //g_jvm为JavaVM指针
    __android_log_vprint(2, "test _ log", "say something", list);
    return env->NewStringUTF("This string is from method by register!");
}

static JNINativeMethod methods[] = {
        {"methodByRegister", "()Ljava/lang/String;", reinterpret_cast<void *>(getString)}
};


JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env = NULL;
    g_jvm = vm;
    if (JNI_OK != vm->GetEnv(reinterpret_cast<void **> (&env), JNI_VERSION_1_4)) {
//        LOGW("JNI_OnLoad could not get JNI env");
        return JNI_ERR;
    }
    jclass clazz = env->FindClass("jeep/jniLearn/JNIMethods");

    env->RegisterNatives(clazz, methods, sizeof(methods) / sizeof((methods)[0]));
    return JNI_VERSION_1_4;
}
