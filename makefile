all:
	g++ -o main processador.cpp
	./main
clean:
	rm -f main