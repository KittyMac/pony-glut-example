use "framework:GLUT"
use "framework:OpenGL"
use "ttimer"

use @glClearColor[None](red:F32,green:F32,blue:F32,alpha:F32)
use @glClear[None](mask:I32)

use @glutInitWindowSize[None](w:I32, h:I32)
use @glutInit[None](argc:Pointer[I32], argv:Pointer[None])
use @glutInitDisplayString[None](displayString:Pointer[U8] tag)
use @glutCreateWindow[None](windowName:Pointer[U8] tag)

use @glutSwapBuffers[None]()
use @glutMainLoop[None]()

use @glutIdleFunc[None](callback:Pointer[None])
use @glutDisplayFunc[None](callback:Pointer[None])

use @pthread_main_np[I32]()

primitive OpenGLConstants
	fun glColorBufferBit():I32 => 0x00004000
	

actor OpenGL
	"""
	To interact with OpenGL we must only do it from the main thread of the program. To ensure this,
	we flag this actor such that it uses the main thread only.
	"""	
	var c:F32 = 0
	
	fun _use_main_thread():Bool => true
		
	be update(v:F32) =>
		c = (v.sin() + 1.0) / 2.0
		@glClearColor(c, 0.0, 0.0, 1.0)
		@glClear(OpenGLConstants.glColorBufferBit())
		@glutSwapBuffers()
			
	fun @displayFunc() =>
		// we aren't required to render in the display func, but we are required to have one ::shrug::
		None
	
	fun @idleFunc() =>
		// since the glut "main loop" never ends, we need to provide our actor some time in order to
		// process messages it receives from the runtime. ponyint_poll_self() will do that for us.
		@ponyint_poll_self[None]()
	
	new create(env:Env) =>
		var argc:I32 = 0
		var argv:Pointer[None] = Pointer[None]
		
		@fprintf[I32](@pony_os_stdout[Pointer[U8]](), "OpenGL.create() is on main thread: %d\n".cstring(), @pthread_main_np())
				
	    @glutInitWindowSize(512, 512)
	    @glutInit(addressof argc, argv)
	    @glutInitDisplayString("rgb double depth".cstring())
	    @glutCreateWindow("Pony GLUT".cstring())
		
		@glutIdleFunc(addressof idleFunc)
		@glutDisplayFunc(addressof displayFunc)
		@glutMainLoop()



actor Main is TTimerNotify
	let vis:OpenGL
	
	var anim:F32 = 0.0
	let animateTimer:TTimer
	
	be timerNotify(timer:TTimer tag) =>
		anim = anim + 0.02
		vis.update(anim)
	
	new create(env:Env) =>
		vis = OpenGL(env)
		
		animateTimer = TTimer(1000 / 60, this, false)
				
		@fprintf[I32](@pony_os_stdout[Pointer[U8]](), "Main.create() is on main thread: %d\n".cstring(), @pthread_main_np())
