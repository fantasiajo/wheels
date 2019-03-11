#include "shared_ptr.h"
#include <iostream>

int main() {
	/*
	LZ::shared_ptr<int> spi(new int(10));
	std::cout << spi.getCnt() << std::endl;
	{
		LZ::shared_ptr<int> spi2(spi);
		std::cout << spi.getCnt() << std::endl;
		std::cout << spi2.getCnt() << std::endl;
	}
	std::cout << spi.getCnt() << std::endl;
	*/
	LZ::shared_ptr<int> spi(new int(10));
	LZ::shared_ptr<int> spi2(new int(20));
	std::cout << spi.getCnt() << std::endl;
	std::cout << spi2.getCnt() << std::endl;
	{
		LZ::shared_ptr<int> spi3 = spi2;
		spi2 = spi;
		std::cout << spi.getCnt() << std::endl;
		std::cout << spi2.getCnt() << std::endl;
		std::cout << spi3.getCnt() << std::endl;
	}
	std::cout << spi.getCnt() << std::endl;
	std::cout << spi2.getCnt() << std::endl;
	return 0;
}
