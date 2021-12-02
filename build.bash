if g++ -c main.cpp
then
	g++ main.o -o main -lsfml-graphics -lsfml-window -lsfml-system
	./main
fi