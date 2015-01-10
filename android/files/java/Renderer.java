package $package;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.opengl.GLSurfaceView;

class Renderer implements GLSurfaceView.Renderer 
{
	static {
		System.loadLibrary("$name");
	}
	
	public native void init();
	public native void resize(int width, int height);
	public native void render();
	
	public void onSurfaceCreated(GL10 gl, EGLConfig config) 
	{
		init();
	}

	public void onSurfaceChanged(GL10 gl, int width, int height) 
	{		
		resize(width, height);
	}
	
	public void onDrawFrame(GL10 gl) 
	{
		render();
	}

}
