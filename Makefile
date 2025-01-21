main:
	gcc shapes/rectangle.c shapes/circle.c main.c -lm  -o main `pkg-config --cflags --libs sdl3`
	./main
clean:
	rm main

