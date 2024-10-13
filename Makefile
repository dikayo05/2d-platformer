all: clean compile link

compile:
	g++ -c src/main.cpp -o build/main.o -Iinclude

link:
	g++ build/main.o -o build/main.exe -Llib -lsfml-graphics -lsfml-window -lsfml-system

clean:
# harus menggunakan backslash untuk windows
	del build\*.o build\*.exe