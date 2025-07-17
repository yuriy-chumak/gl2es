package lib.gl2es.matrices;

public class Main extends android.app.NativeActivity {
    static {
        System.loadLibrary("olvm");  // Ol Virtual Machine
        System.loadLibrary("ol");    // Android JNI + REPL
        System.loadLibrary("gl2es"); // OpenGL 2 over GLES
        System.loadLibrary("GLU");
        System.loadLibrary("main");  // Native Android App
    }
}
