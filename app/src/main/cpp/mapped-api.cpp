#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_jeep_jniLearn_JNIMethods_methodByMapped(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "This string is from static method by mapped!";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_jeep_jniLearn_JNIMethodNonStatic_methodNotStatic(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "This string is from normal method by mapped!";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT jstring  JNICALL
Java_jeep_jniLearn_JNIMethodNonStatic_methodWithTwoArgu(
        JNIEnv *env,        /* interface pointer */
        jobject obj,        /* "this" pointer */
        jint i,             /* argument #1 */
        jstring s)          /* argument #2 */
{
//    std::string hello = ;
    if (s == NULL) {
        return env->NewStringUTF("null...");
    } else {
        const char *str = env->GetStringUTFChars(s, 0);

        return env->NewStringUTF(str);
    }

}





