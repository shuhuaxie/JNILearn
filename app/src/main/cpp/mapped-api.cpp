#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_jeep_jniLearn_JNIMethods_methodByMapped(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "This string is from method by mapped!";
    return env->NewStringUTF(hello.c_str());
}





