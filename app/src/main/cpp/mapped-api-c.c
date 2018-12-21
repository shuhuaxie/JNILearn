#include <jni.h>

jdouble Java_jeep_jniLearn_JNIMethodNonStatic_methodOfC(
        JNIEnv *env,        /* interface pointer */
        jobject obj,        /* "this" pointer */
        jint i,             /* argument #1 */
        jstring s)          /* argument #2 */
{

    if (s == NULL || i == NULL) {
        return 0;
    }
    const char *str = (*env)->GetStringUTFChars(env, s, 0);

    /* process the string */

    /* Now we are done with str */
    (*env)->ReleaseStringUTFChars(env, s, str);

    return i;

}





