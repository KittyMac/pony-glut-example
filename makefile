release:
	stable env /Volumes/Development/Development/pony/ponyc/build/release/ponyc -o ./build/
	./build/pony_glut_example

debug:
	stable env /Volumes/Development/Development/pony/ponyc/build/debug/ponyc -d -o ./build/
	lldb ./build/pony_glut_example