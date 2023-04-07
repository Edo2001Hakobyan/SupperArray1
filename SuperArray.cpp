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

	int SuperArray::getCapacity()
	{
		return m_capacity;
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
	       	if(m_size == m_capacity)
		{
		    void pushBack();
		}	
	        
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

      //Overloaded assignment operator
      SuperArray& SuperArray::operator=(const SuperArray& other)
      {       
	      //Check for self-assignment 
	      if(this != &other)
	      {
                   m_size = other.m_size;
		   m_capacity = other.m_capacity;
		   m_data = other.m_data;
	      }
	      return *this;
     
      }

      //Copy constructor
      SuperArray::SuperArray(const SuperArray& other) : m_capacity(other.m_capacity),m_size(other.m_size)
      {
	      std::cout<<"Copy constructor:"<<std::endl;
	      m_data = new int[m_capacity]; 
	      for(int i = 0;i < m_size;i++)
	      {
		  m_data[i] = other.m_data[i];
	      } 	   
      }
      
      //Destructor
      SuperArray::~SuperArray()
      {
	    delete [] m_data;
      }  


         

