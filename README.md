# pony-glut-example

**WARNING** This code only compiles with [my fork of Pony](https://github.com/KittyMac/ponyc/tree/roc_master).

### Purpose

To test an addition to my fork of pony which provides the capability of specifying that an actor should only be executed on the main thread of the program.

This feature is necessary when working with external APIs which require that their callers only access it from a specific thread (such as OpenGL).

Previously the only mechanism to do this was to create a C shell and compile your pony code as a library, and have the C code instantiate an FFI actor.

Now all you need to do is include the following hint in your actor class, and instances of that class will only execute on the main thread.

``` 
actor OpenGL
	fun _use_main_thread():Bool => true
	
```



## License

pony.http is free software distributed under the terms of the MIT license, reproduced below. pony.http may be used for any purpose, including commercial purposes, at absolutely no cost. No paperwork, no royalties, no GNU-like "copyleft" restrictions. Just download and enjoy.

Copyright (c) 2019 Rocco Bowling

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.