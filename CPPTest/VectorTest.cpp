#include <vector>
#include <iostream>

double mean(double *array, size_t n)
{
	double m = 0;
	for (size_t i = 0; i < n; ++i)
	{
		m += array[i];
	}
	return m / n;
}

int main()
{
	typedef std::vector<int> int_vec_t;
	size_t size = 10; //size_t is return type of sizeof
	int_vec_t array(size); //make room for 10 int vector initialized to default value 0
	for (int i = 0; i < size; ++i) {
		array[i] = i; //[] operator of vector like array does not check if index exists, can throw index not found exception
	} 
	try {
		array.at(1000) = 0;
	}
	catch (std::out_of_range o) {
		std::cout << o.what() << std::endl;
	}
	std::vector<char> carray; //create empty vector
	carray.reserve(10); //allocate memory of 10 items without initializing elements 
	char c = 0;
	carray.push_back(c);
	std::cout << carray.capacity() << std::endl; //calapcity is 10
	std::cout << carray.size() << std::endl; //size is 1
	carray.resize(20); //resize the vector to have 20 elements resizing to smaller number whill chop off elements after new size
	while (c != 'x') {
		std::cin >> c;
		carray.push_back(c); //Automatically allocate memory chunk default size as needed as size increases
	}
	double p[] = { 1, 2, 3, 4, 5 };
	std::vector<double> darray;
	darray.push_back(1);
	darray.push_back(2);
	darray.push_back(3);
	darray.push_back(4);
	darray.push_back(5);
	std::cout << mean(&darray[0], 5) << std::endl; //pass reference to first element in vector explicitly
	std::cout << mean(p, 5) << std::endl; //for array array name means address to first element
	std::vector<double> a(p, p + 5); //initialize vector a with elements of array p by taking first and one past last element address of p
	std::vector<double>::const_iterator i;
	for (i = darray.begin(); i != a.end(); ++i) {
		std::cout << *i << std::endl;
	}
	darray.assign(a.begin(), a.end()); //initialize darray with elements of a vector
	std::vector<double>::reverse_iterator r = darray.rbegin();
	std::vector<double>::iterator i = r.base(); //point to last element in sequence
	double d = darray.front(); //same as darray[0], darray.at(0), *(darray.begin())
	d = darray.back(); //Same as darray[darray.size() - 1], darray.at(darray.size() - 1), *(darray.end() - 1)
	darray.pop_back(); //removes the last element but does not reduce capacity
	std::vector<double>::iterator it = darray.begin() + 1;
	it = darray.insert(it, 33);
	darray.erase(it, it + 2); //remove 2 elements starting with it
	darray.erase(it); //remove element at it
	darray.clear(); //remove all elements in darray, but keeps capacity same
	std::vector<int> v;
	v.clear();
	v.swap(std::vector<int>(v)); //v swap contents of v to its new elements and memory allocation
	return 0; //No need to delete vector like array because vector template takes care of deleting
}