#include <iostream>
#include <algorithm>
#include "SuperArray.hpp"

        
	
	SuperArray::SuperArray()
	{
		m_size = 0;
		m_capacity = 10;
		m_data = new int[m_capacity];
	}

       	int SuperArray::getSize()
	{
		return m_size;
	}

	
	SuperArray::~SuperArray()
        {
	      delete [] m_data;
        }  

	void SuperArray::pushBack(int value)
	{
		if(m_size == m_capacity)
		{       
			//If the array is full,double the capacity
			m_capacity *= 2;
			int *new_data = new int[m_capacity];
			std::copy(m_data,m_data + m_size,new_data);
			delete [] m_data;
			m_data = new_data;
		}
		m_data[m_size++] = value;
	}
      
        void SuperArray::insert(int index,int value)
        {
	        
                if(index < 0 || index >= m_size)
      	        {
      		    std::cout<<"Index out of range"<<std::endl;
      		    exit (1);
      	        }

                //Shift all elements to the right of the insertion point
		//To make room for the new element		
      		for (int i = m_size; i > index; i--)
		{
			m_data[i] = m_data[i-1];
		}
                
		//Insert the new element
		m_data[index] = value;
		m_size++;
		
		

        }

        void SuperArray::remove(int index)
        {       
		if(index < 0 || index >= m_size)
      	        {
      		    std::cout<<"Index out of range"<<std::endl;
      		    exit (1);
      	        }               
      		
                //Shift all elements to the left of the delition point
		//To fill in the gap left by the removed element
		for(int i = index; i < m_size-1; i++)
		{
			m_data[i] = m_data[i + 1];
		}
                
		//Decrement the size of array
		m_size--;
	}


      //Indexing operator
      int& SuperArray::operator[](int index)
      {
      	if(index < 0 || index >= m_size)
      	{
      		std::cout<<"Index out of range"<<std::endl;
      		exit (1);
      	}
      	return m_data[index];
      }
      
         

