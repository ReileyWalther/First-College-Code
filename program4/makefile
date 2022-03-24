DEBUG=-g

LLtest: LLtest.o Student.o 
	g++ -o LLtest LLtest.o Student.o $(DEBUG)

LLtest.o: LLtest.cpp Student.h LinkedList.h LListIter.h
	g++ -c LLtest.cpp $(DEBUG)

Student.o: Student.cpp Student.h
	g++ -c Student.cpp $(DEBUG)

clean:
	rm -f LLtest LLtest.o Student.o 
