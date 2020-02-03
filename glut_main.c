#include <stdio.h>
#include <stdlib.h>
#include <GLUT/glut.h>

#include "pony.h"
#include "pony_glut_example.h"

static MainThreadActor* mainThreadActor;

// required to compile, the runtime is looking for this which is generated off of
// Main actor (which doesn't exist when compiled as a library)
void Main_runtime_override_defaults_oo(void* opt)
{
	(void)opt;
	return;
}

/*
void redraw(void)
{
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glutSwapBuffers();
}

void reshape(int width, int height)
{
    glutPostRedisplay();
}*/

void idle()
{
	// during our glut idle we will poll the mainThreadActor, allowing it
	// to process messages (ie behaviour calls) on this thread.
	pony_ctx_t * ctx = pony_ctx();
    pony_become(ctx, (pony_actor_t *)mainThreadActor);
	
	// Note: stock pony only provides pony_poll(), which will process exactly one
	// message for this actor.  My fork of pony exposes pony_poll_many(), which will
	// have it process a full "run" of messages.  With simply pony_poll() we
	// don't know how many times we *should* call it. ::shrug::
	for (int i = 0; i < 100; i++) {
		pony_poll(ctx);
	}
}

int main(int argc, char **argv)
{
    glutInitWindowSize(512, 512);
    glutInit(&argc, argv);
    glutInitDisplayString("rgb double depth");
	
    glutCreateWindow("GLUT Window");
	
	// 1. start pony up
	int exit_code = 0;
	pony_init(argc, argv);
	pony_start(true, &exit_code, NULL);
	
	// 2. create the actor which is only going to run on this thread
	// Allocate a new messenger actor.  We will unschedule it and then
    // become it, allowing us to handle its messages manually by calling
    // pony_poll().
    mainThreadActor = MainThreadActor_Alloc();
    MainThreadActor_tag_create_o__send(mainThreadActor);	

    pony_ctx_t * ctx = pony_ctx();
    pony_unschedule(ctx, (pony_actor_t *)mainThreadActor);
    pony_become(ctx, (pony_actor_t *)mainThreadActor);
	
	// 3. register our glut idle. this will be responsible for allowing 
	// the actor to run in this thread
	glutIdleFunc(idle);
	
	// kick off our glut main loop
    glutMainLoop();
	
	pony_stop();
	
    return 0;
}
