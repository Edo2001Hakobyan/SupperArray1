#include <iostream>
#include "SuperArray.hpp"

int main()
{
	SuperArray arr;

        std::cout<<"Initial array capacity: "<<arr.getCapacity()<<std::endl;

	for (int i = 0; i < 20; ++i)
	{
		arr.pushBack(i);
	}

	std::cout<<"Final array size: "<<arr.getSize()<<std::endl;
	std::cout<<"Final array capacity: "<<arr.getCapacity()<<std::endl;
        
        std::cout<<"Initial array:"<<std::endl;	
        for (int i = 0;i < arr.getSize();++i)
	{
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;
        
        SuperArray copyArr = arr;	
	for(int i=0; i < copyArr.getSize();i++ )
	{
		std::cout<<copyArr[i]<<" ";
	}
	std::cout<<std::endl;

	arr.insert(1,16);
	arr.remove(2);

	std::cout<<"Array that in use insert(1,16) and remove(2 index) functions:"<<std::endl;
        for (int i = 0;i < arr.getSize();++i)
	{
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;

	

	return 0;
}
