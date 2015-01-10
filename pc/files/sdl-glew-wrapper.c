#include<stdlib.h>
#include<stdio.h>

#include<SDL2/SDL.h>
#include<GL/glew.h>
#include<GL/glu.h>

void view_init();
void view_close();
void view_resize(int width, int height);
void view_render();

struct __Context
{
	SDL_Window *window;
	SDL_GLContext context;
};
static struct __Context __context;

static int initGraphics()
{
	__context.window =
		SDL_CreateWindow(
			"$header",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			800, 600,
			SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
		);

	__context.context =
		SDL_GL_CreateContext(__context.window);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE,5);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,6);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,5);
	SDL_GL_SetSwapInterval(1);

	GLenum glew_status = glewInit();
	if(GLEW_OK != glew_status)
	{
		printf("%s\n",glewGetErrorString(glew_status));
		return -1;
	}
	if(!GLEW_VERSION_2_0)
	{
		printf("%s\n","No support for OpenGL 2.0 found");
		return -2;
	}

	view_init();
	
	return 0;
}

static int disposeGraphics()
{
	view_close();
	SDL_GL_DeleteContext(__context.context);
	SDL_DestroyWindow(__context.window);
	return 0;
}

static void resizeGraphics(int width, int height)
{
	view_resize(width,height);
}

static void __flip()
{
	SDL_GL_SwapWindow(__context.window);
}

static void renderGraphics()
{
	view_render();
	__flip();
}

static int handleEvents()
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case SDL_QUIT:
			return 1;
			
		case SDL_WINDOWEVENT:
			switch(event.window.event) 
			{
				case SDL_WINDOWEVENT_RESIZED:
					resizeGraphics(event.window.data1,event.window.data2);
					break;
					
				default:
					break;
			}
			break;
			
		default:
			break;
		}
	}
	return 0;
}

int main(int argc, char *argv[])
{
	int status = initGraphics();
	if(status != 0)
	{
		return status;
	}
	
	resizeGraphics(800,600);
	
	while(!handleEvents())
	{
		renderGraphics();
	}
	
	disposeGraphics();
	
	return 0;
}
