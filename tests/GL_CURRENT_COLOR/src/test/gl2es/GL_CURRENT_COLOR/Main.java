package test.gl2es.GL_CURRENT_COLOR;

public class Main extends android.app.NativeActivity {
    static {
        System.loadLibrary("olvm");  // Ol Virtual Machine
        System.loadLibrary("ol");    // Android JNI + REPL
        System.loadLibrary("gl2es"); // OpenGL 2 over GLES
        System.loadLibrary("main");  // Native Android App
    }
}
