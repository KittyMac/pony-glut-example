
use @glClearColor[None](red:F32,green:F32,blue:F32,alpha:F32)
use @glClear[None](mask:I32)
use @glutSwapBuffers[None]()

use @glutDisplayFunc[None](callback:Pointer[None])

primitive OpenGL
	fun glColorBufferBit():I32 => 0x00004000
	

actor@ MainThreadActor
	"""
	Allocated by the glut_main.c. It gets allocated, then unscheduled (so pony itself doesn't run)
	it, and then it "becomes" the actor.
	"""
	
	fun @displayFunc() =>
		@glClearColor(1.0, 0.0, 0.0, 1.0)
		@glClear(OpenGL.glColorBufferBit())
		@glutSwapBuffers()
	
	new create() =>
		@fprintf[I32](@pony_os_stdout[Pointer[U8]](), "MainThreadActor created!\n".cstring())
		
		@glutDisplayFunc(addressof displayFunc)
		

// Note: no main actor is created when you compile your pony code as a library. This is not true on my fork of
// pony, which allows you to keep a Main actor and start the library simply by calling pony_main() from your c code
//actor Main
//	new create(env:Env) =>
//		env.out.print("main actor")
