package lib.gl2es.color;

public class Main extends android.app.NativeActivity {
    static {
        System.loadLibrary("olvm");  // Ol Virtual Machine
        System.loadLibrary("ol");    // Android JNI + REPL
        System.loadLibrary("gl2es"); // OpenGL 2 over GLES
        System.loadLibrary("main");  // Native Android App
    }
}
