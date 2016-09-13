#makefile

productTest: ProductDriver.o ProductInventory.o Product.o
	g++ ProductDriver.o ProductInventory.o Product.o -o productTest

ProductDriver.o: ProductDriver.cpp ProductInventory.h Product.h
	g++ -c ProductDriver.cpp

ProductInventory.o: ProductInventory.cpp ProductInventory.h Product.h
	g++ -c ProductInventory.cpp

Product.o: Product.cpp Product.h
	g++ -c Product.cpp

clean:
	rm *.o
	rm productTest
