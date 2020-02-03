# pony-glut-example

A (hopefully simple) example of a merging pony with glut.  Here are the basic steps:

1. download and compile ponyc (you need this for the pony runtime library)
2. in your c code, on your "opengl thread", instiate an FFI actor
3. periodically poll the actor from that thread (this will run called behaviours)


