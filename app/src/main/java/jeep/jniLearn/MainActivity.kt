package jeep.jniLearn

import android.app.Activity
import android.os.Bundle
import android.util.Log
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : Activity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // Example of a call to a native method
        sample_text_1.text = JNIMethods.methodByMapped()
        sample_text_2.text = JNIMethods.methodByRegister()
        sample_text_3.text = JNIMethodNonStatic().methodNotStatic()
        sample_text_4.text = JNIMethodNonStatic().methodWithTwoArgu(12, "hello")
        sample_text_5.text = JNIMethodNonStatic().methodOfC(12, "hello")
        Log.e("xie", "ofC:" + JNIMethodNonStatic().methodOfC(12, "hello"))
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */

    companion object {

        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib")
        }
    }
}
