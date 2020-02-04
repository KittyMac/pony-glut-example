use "framework:GLUT"
use "framework:OpenGL"

use @glClearColor[None](red:F32,green:F32,blue:F32,alpha:F32)
use @glClear[None](mask:I32)

use @glutInitWindowSize[None](w:I32, h:I32)
use @glutInit[None](argc:Pointer[I32], argv:Pointer[None])
use @glutInitDisplayString[None](displayString:Pointer[U8] tag)
use @glutCreateWindow[None](windowName:Pointer[U8] tag)

use @glutSwapBuffers[None]()
use @glutMainLoop[None]()

use @glutDisplayFunc[None](callback:Pointer[None])

use @pthread_main_np[I32]()

primitive OpenGLConstants
	fun glColorBufferBit():I32 => 0x00004000
	

actor OpenGL
	"""
	To interact with OpenGL we must only do it from the main thread of the program. To ensure this,
	we flag this actor such that it uses the main thread only.
	"""
	fun _use_main_thread():Bool => true
	
	fun @displayFunc() =>
		@glClearColor(1.0, 0.0, 0.0, 1.0)
		@glClear(OpenGLConstants.glColorBufferBit())
		@glutSwapBuffers()
	
	new create(env:Env) =>
		var argc:I32 = 0
		var argv:Pointer[None] = Pointer[None]
		
		@fprintf[I32](@pony_os_stdout[Pointer[U8]](), "OpenGL.create() is on main thread: %d\n".cstring(), @pthread_main_np())
				
	    @glutInitWindowSize(512, 512)
	    @glutInit(addressof argc, argv)
	    @glutInitDisplayString("rgb double depth".cstring())
	    @glutCreateWindow("Pony GLUT".cstring())
				
		@glutDisplayFunc(addressof displayFunc)		
	    @glutMainLoop()
		

actor Main
	new create(env:Env) =>
		OpenGL(env)
		
		@fprintf[I32](@pony_os_stdout[Pointer[U8]](), "Main.create() is on main thread: %d\n".cstring(), @pthread_main_np())
