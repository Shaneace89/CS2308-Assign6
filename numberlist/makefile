#makefile

listTest: ListDriver.o NumberList.o
	g++ ListDriver.o NumberList.o -o listTest

ListDriver.o: ListDriver.cpp NumberList.h
	g++ -c ListDriver.cpp

NumberList.o: NumberList.cpp NumberList.h
	g++ -c NumberList.cpp

clean:
	rm *.o
	rm listTest