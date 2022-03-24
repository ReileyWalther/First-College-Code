debugFlag=-g

savings: Child.o savings.o 
	g++ -o savings savings.o Child.o $(debugFlag)

savings.o: savings.cpp Child.h
	g++ -c savings.cpp -o savings.o $(debugFlag)

Child.o: Child.cpp Child.h 
	g++ -c Child.cpp $(debugFlag)

clean: 
	\rm -f *.o savings

