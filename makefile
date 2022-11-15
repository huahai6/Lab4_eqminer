test:Input.o Output.o Stdin_format.o Judge.o Equminer.o
	g++ -o test Input.o Output.o Stdin_format.o Judge.o Equminer.o -g
Input.o:Input.cpp Input.h
	g++ -c -o Input.o Input.cpp -g
Output.o:Output.cpp Output.h
	g++ -c -o Output.o Output.cpp -g
Stdin_format.o:Stdin_format.cpp Stdin_format.h
	g++ -c -o Stdin_format.o Stdin_format.cpp -g
Judge.o:Judge.cpp Judge.h Input.h Output.h Stdin_format.h
	g++ -c -o Judge.o Judge.cpp -g
Equminer.o:Equminer.cpp Equminer.h Judge.h Input.h Output.h Stdin_format.h
	g++ -c -o Equminer.o Equminer.cpp -g
