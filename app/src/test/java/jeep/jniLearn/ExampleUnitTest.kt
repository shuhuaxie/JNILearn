package jeep.jniLearn

import org.junit.Test

import org.junit.Assert.*

/**
 * Example local unit test, which will execute on the development machine (host).
 *
 * See [testing documentation](http://d.android.com/tools/testing).
 */
class ExampleUnitTest {
    @Test
    fun addition_isCorrect() {
        assertEquals(4, 2 + 2)
    }

    val lazyValue: String by lazy {
        println("computed!")
        "Hello"
    }
//    val xx: String = (
//        println("computed! __")
//    )

    @Test
    fun main() {
        println("xx")
//        println(xx)
//        println(lazyValue)
        println(lazyValue)
//        println(xx)
    }
}
