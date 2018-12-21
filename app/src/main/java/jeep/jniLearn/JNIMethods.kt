package jeep.jniLearn

object JNIMethods {
    external fun methodByMapped(): String

    external fun methodByRegister(): String
}

class JNIMethodNonStatic {

    external fun methodNotStatic(): String
    external fun methodWithTwoArgu(size: Long, name: String): String
    external fun methodOfC(size: Long, name: String): String
}
