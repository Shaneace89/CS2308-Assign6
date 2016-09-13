#Makefile

inventory: ProductDriver.o Product.o ProductInventory.o
	g++ ProductDriver.o Product.o ProductInventory.o -o inventory

ProductDriver.o: ProductDriver.cpp ProductInventory.h
	g++ -c ProductDriver.cpp

Product.o: Product.cpp Product.h
	g++ -c Product.cpp

ProductInventory.o: ProductInventory.cpp ProductInventory.h
	g++ -c ProductInventory.cpp

clean:
	rm *.o

cleanclean:
	rm *.o inventory

run:
	./inventory
