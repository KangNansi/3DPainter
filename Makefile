
CC=g++


GTK_FLAGS=`pkg-config gtkmm-3.0 --cflags`
GTK_LIBS=`pkg-config gtkmm-3.0 --libs`
OPENGL_LIB=-lGL

WIDGETS_OBJ=$(patsubst ./src%, ./obj%, $(patsubst %.cpp, %.o, $(wildcard ./src/widgets/*.cpp)))

VIEWS_OBJ=$(patsubst ./src%, ./obj%, $(patsubst %.cpp, %.o, $(wildcard ./src/views/*.cpp)))

TEST=./src/widgets/*.cpp

3DPainter: ${WIDGETS_OBJ} ${VIEWS_OBJ} obj/main.o
	g++ -o bin/3DPainter $^ $(GTK_LIBS) $(OPENGL_LIB)

obj/main.o: src/main.cpp src/main.hpp
	g++ -c -o $@ $< $(GTK_FLAGS)

# WIDGETS

obj/widgets/%.o : src/widgets/%.cpp src/widgets/%.hpp obj/widgets
	g++ -c -o $@ $< $(GTK_FLAGS)

obj/widgets:
	mkdir obj/widgets

# VIEWS

obj/views/%.o : src/views/%.cpp src/views/%.hpp obj/views
	g++ -c -o $@ $< $(GTK_FLAGS)

obj/views:
	mkdir obj/views