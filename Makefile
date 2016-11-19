main: main.o TextureImage.o
	${CC} -o main main.o TextureImage.o -lGL -lGLU -lGLEW -lglut -lstdc++
main.o: main.cpp
	${CC} -o main.o main.cpp -c
TextureImage.o: TextureImage.cpp
	${CC} -o TextureImage.o TextureImage.cpp -c
