class SuperArray
{
	private:

        int m_size;
        int m_capacity;
        int  *m_data;

        public:
               
	//Consrtuctor definition
	SuperArray();

	//Function that return array size
	int getSize();

	//Function that return capacity
        int getCapacity();
	
	//Function that check if array size is equal in capacity,capacity multiply two times 
	void pushBack(int value);

	//Indexing operator
	int& operator[](int index);

	//Function that add value appropriate of index in array
       	void insert(int index,int value);
	
	//Function that remove index in array
	void remove(int index);

	//Destructor definition
        ~SuperArray();
        
	        
};

