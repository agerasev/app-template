package $package;

import android.app.Activity;
import android.os.Bundle;
import android.view.Window;
import android.view.WindowManager;
import android.opengl.GLSurfaceView;

public class $activity extends Activity
{
	private GLSurfaceView view;

	@Override
	public void onCreate(Bundle savedInstanceState) 
	{
		super.onCreate(savedInstanceState);
		
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		getWindow().setFlags(
		  WindowManager.LayoutParams.FLAG_FULLSCREEN,
		  WindowManager.LayoutParams.FLAG_FULLSCREEN
		);
		
		view = new GLSurfaceView(getApplication());
		
		view.setEGLContextClientVersion(2);
		
		view.setEGLConfigChooser(8,8,8,8,16,0);
		
		view.setRenderer(new Renderer());
		
		setContentView(view);
	}

	@Override
	protected void onPause() 
	{
		super.onPause();
		view.onPause();
	}

	@Override
	protected void onResume() 
	{
		super.onResume();
		view.onResume();
	}
}
