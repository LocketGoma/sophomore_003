#include<iostream>
using namespace std;

template <class T>
class Bag
{
public:
	Bag(int bagCapacity = 3);
	~Bag();

	int Size() const;
	bool IsEmpty() const;
	T& Element() const;
	void Push(const T&);
	void Pop();
	
private:
	T *array;
	int capacity;
	int top;
	
	void UpSize(T*&, const int, const int);
};


class Biscard : public Bag<char *>
{
public:
	Biscard(int sizeCapacity = 3);
	~Biscard();
	 
	char **Element();
	void Push(char*, char*);
	int Size() const;
	void Pop();
	bool IsEmpty() const;


private: // 
	char ***array;

	char *name; // array[i][0];
	char *phone;// array[i][1];

	int capacity;
	int top;
	
	void ShowInfo(char **); 
	void UpSize(char ***&, const int, const int);
};


int main() {
	Bag<int> bg(3); 


	// count 3 start
	cout << "size :: " << bg.Size() << endl;
	cout << "is empty? : " << bg.IsEmpty() << endl;
	try {
	cout << bg.Element() << endl;  } // element must be use 'try/catch'. <- why? don't know...
	catch (int i) {
	cout << "error" << endl;
	}
	
	// count 3 end

	bg.Push(100);
	bg.Push(200);
	bg.Push(300);

	// count 4 start
	cout << "size :: " << bg.Size() << endl;
	cout << "is empty? : " << bg.IsEmpty() << endl;
	try {
		cout << bg.Element() << endl;  
	}
	catch (int i) {
		cout << "error" << endl;
	}
	// count 4 end;
	cout << endl;
	// count 5 start;
	bg.Push(400);
	bg.Push(500);
	bg.Push(600);
	bg.Push(700);
	cout << "size :: " << bg.Size() << endl;
	cout << "is empty? : " << bg.IsEmpty() << endl;
	try {
		cout << bg.Element() << endl;  
	}
	catch (int i) {
		cout << "error" << endl;
	}
	// count 5 end
	cout << endl;

	// count 6 start
	bg.Pop();
	bg.Pop();

	cout << "size :: " << bg.Size() << endl;
	cout << "is empty? : " << bg.IsEmpty() << endl;
	try {
		cout << bg.Element() << endl; 
	}
	catch (int i) {
		cout << "error" << endl;
	}

	// count 6 end

	//Biscard part
	//it use "char *", not 'string', so occur many worring. but, still moving.

	cout << "---biscard---" << endl;
	Biscard bs(3);
	try {
		cout << bs.Element() << endl;  
	}
	catch (int i) {
		cout << "error" << endl;
	}
	cout << "size :: " << bs.Size() << endl;
	cout << "is empty? : " << bs.IsEmpty() << endl;

	bs.Push("abc", "123");
	bs.Push("bcd", "234");
	bs.Push("cde", "345");
	bs.Push("def", "456");

	try {
		cout << bs.Element() << endl;  
	}
	catch (int i) {
		cout << "error" << endl;
	}
	cout << "size :: " << bs.Size() << endl;
	cout << "is empty? : " << bs.IsEmpty() << endl;

	bs.Push("efg", "567");
	bs.Push("fgh", "678");
	bs.Push("ghi", "789");

	try {
		cout << bs.Element() << endl;  
	}
	catch (int i) {
		cout << "error" << endl;
	}
	cout << "size :: " << bs.Size() << endl;
	cout << "is empty? : " << bs.IsEmpty() << endl;


	bs.Pop();
	bs.Pop();

	try {
		cout << bs.Element() << endl; 
	}
	catch (char * s) {
		cout << s << endl;
	}
	cout << "size :: " << bs.Size() << endl;
	cout << "is empty? : " << bs.IsEmpty() << endl;

	return 0;
}



// bag Class

template <class T> 
Bag<T>::Bag(int bagCapacity) { 
	capacity = bagCapacity;
	array = new T[capacity];
	top = -1;
}
template <class T> 
Bag<T>::~Bag() {
	delete[] array;
	cout << "Good Bye" << endl;
}
template <class T> // size return
int Bag<T>::Size() const { 

	return top + 1;
}
template <class T> // IsEmpty
bool Bag<T>::IsEmpty() const { 
	if (Size() == 0) {
		return true;
	}
	else {
		return false;
	}
}
template <class T> //
void Bag<T>::UpSize(T*& a, const int oldSize, const int newSize) { 
	if (newSize < 0) throw "upsize error.";

	T* temp = new T[newSize]; // new array
	int num = (newSize - oldSize);
	copy(a, a + num, temp);
	delete[] a;
	a = temp;

}
template <class T> // push
void Bag<T>::Push(const T& tot) { 
	if (capacity == top + 1) {
		UpSize(array, capacity, capacity * 2);
		capacity *= 2;
	}
	array[++top] = tot;

}
template <class T> //eject
void Bag<T>::Pop() { 
	if (IsEmpty())
	{
		cout << "Bag is empty." << endl;
	}
	else {
		int deletePos = top / 2;
		cout << "<eject> array[" << deletePos << "] ::" << array[deletePos] << endl;
		copy(array + deletePos + 1, array + top + 1, array + deletePos);

		top--;
	}
}
template <class T> //element :: print middle obj
T& Bag<T>::Element() const { // 
	if (IsEmpty()){
		throw -1;}

	return array[(top / 2)];
}

// Biscard Class
Biscard::Biscard(int sizeCapacity ) {
	capacity = sizeCapacity;
	array = new char**[capacity];
	top = -1;
}
Biscard::~Biscard() { 
	for (int i = 0; i < top; ++i) {
		delete[] array[i];
	}
	delete[] array;

	cout << "Oops." << endl;
}
int Biscard::Size() const {
	return top + 1;
}
void Biscard::Push(char *name, char *number) { 
	if (capacity == top + 1) {
		UpSize(array, capacity, capacity * 2); 
		capacity *= 2;
	}
	++top;

	array[top] = new char*[2];

	array[top][0] = name;
	array[top][1] = number;

}
void Biscard::UpSize(char *** &a, const int oldSize, const int newSize) { 
	if (newSize < 0) throw "upsize error";

	char ***temp = new char**[newSize]; // new array


	for (int i = 0; i < newSize - oldSize; i++) {
		temp[i] = new char*[2];
		temp[i][0] = a[i][0];
		temp[i][1] = a[i][1];
	}

	delete[] a;
	a = temp;

}

void Biscard::ShowInfo(char **print) {

	cout << "name :: " << print[0] << "  number::" << print[1] << endl;

}
bool Biscard::IsEmpty() const {
	if (Size() == 0) {
		return true;
	}
	else {
		return false;
	}
}
char **Biscard::Element() { 
	if (IsEmpty()){
		throw -1;}

	int i = top / 2;

	ShowInfo(array[i]);
	return array[i]; 
}
void Biscard::Pop() {
	if (IsEmpty())
	{
		cout << "Bag is empty." << endl;
	}
	else {
		int deletePos = top / 2;
		cout << "<eject> array[" << deletePos << "] ::";
		ShowInfo(array[deletePos]);

		copy(array + deletePos + 1, array + top + 1, array + deletePos); 

		top--;
	}
}
