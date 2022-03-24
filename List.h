#pragma once
#include <iostream>
#include <typeinfo>

template <typename var>
class List;

template <typename var>
std::ostream& operator<< (std::ostream&, const List<var>&);

template <typename var>
std::istream& operator>> (std::istream&, List<var>&);

template <typename T>
struct element
{
	T value;
	element* next;
	size_t index;
};

template <typename var>
class List
{
private:
	element<var>* first;
	element<var>* last;
	size_t size;
public:
	List();
	~List();
	List(const List<var>& l2);
	List<var>& operator= (const List<var>&);
	bool isEmpty() const;
	void initial_new_memory(size_t);
	List<var> operator+(List<var>&);
	var& operator[](size_t n) const;
	size_t get_size_of_List();
	friend std::istream& operator>> <>(std::istream&, List<var>&);
	friend std::ostream& operator<< <>(std::ostream&, const List<var>&);
};

template <>
void List<char*>::initial_new_memory(size_t size_memory)
{
	element<char*>* newElement = new element<char*>;
	newElement->value = new char[size_memory] {};
	newElement->index = size++;
	newElement->next = nullptr;
	if (isEmpty())
		first = newElement;
	else
		last->next = newElement;
	last = newElement;
}

template <typename var>
List<var>::List()
{
	first = nullptr;
	last = nullptr;
	size = 0;
}

template <typename var>
List<var>::~List()
{
	element<var>* temp = nullptr;
	while (first)
	{
		temp = first->next;
		delete first;
		first = temp;
	}
}

template <>
List<char*>::~List()
{
	element<char*>* temp = nullptr;
	while (first)
	{
		temp = first->next;
		delete first->value;
		delete first;
		first = temp;
	}
}

template <typename var>
List<var>::List(const List<var>& l2) : List<var>()
{
	this->initial_new_memory(l2.size);
	for (size_t i = 0; i < l2.size; i++)
	{
		(*this)[i] = l2[i];
	}
}

template <>
List<char*>::List(const List<char*>& l2) : List<char*>()
{
	element<char*>* current = l2.first;
	for (size_t i = 0; i < l2.size; i++)
	{
		this->initial_new_memory(strlen(l2[i]) + 1);
		strcpy((*this)[i], l2[i]);
	}
}

template <typename var>
size_t List<var>::get_size_of_List()
{
	return size;
}

template <typename var>
var& List<var>::operator[](size_t n) const
{
	if (n < 0 || n >= size)
	{
		throw std::string("Ошибочный индекс!");
	}

	element<var>* current = first;
	while (n != current->index)
	{
		current = current->next;
	}
	return current->value;
}

template <typename var>
List<var> List<var>::operator+(List<var>& l2)
{
	size_t size_of_lists = this->size + l2.size;
	var* mass1 = new var[size_of_lists]{};
	size_t i;
	for (i = 0; i < this->size; i++)
	{
		mass1[i] = (*this)[i];
	}

	for (i; i < size_of_lists; i++)
	{
		mass1[i] = l2[i - this->size];
	}

	List<var> result;
	result.initial_new_memory(size_of_lists);
	for (size_t i = 0; i < size_of_lists; i++)
	{
		result[i] = mass1[i];
	}

	delete[] mass1;
	return result;
}

template <>
List<char*> List<char*>::operator+(List<char*>& l2)
{
	size_t size_of_lists = this->size + l2.size;
	char** mass1 = new char*[size_of_lists]{};
	size_t i;
	for (i = 0; i < this->size; i++)
	{
		mass1[i] = new char[strlen((*this)[i]) + 1];
		strcpy(mass1[i], (*this)[i]);
	}

	for (i; i < size_of_lists; i++)
	{
		mass1[i] = new char[strlen(l2[i - this->size]) + 1];
		strcpy(mass1[i], l2[i - this->size]);
	}

	List<char*> result;
	for (size_t i = 0; i < size_of_lists; i++)
	{
		result.initial_new_memory(strlen(mass1[i]) + 1);
		strcpy(result[i], mass1[i]);
	}
	for (size_t i = 0; i < size_of_lists; ++i)
		delete[] mass1[i];
	delete[] mass1;

	return result;
}

template <typename var>
void List<var>::initial_new_memory(size_t size_memory)
{
	while (size_memory-- != 0)
	{
		element<var>* newElement = new element<var>;
		newElement->value = 0;
		newElement->index = size++;
		newElement->next = nullptr;
		if (isEmpty())
			first = newElement;
		else
			last->next = newElement;
		last = newElement;
	}
}

template <typename var>
bool List<var>::isEmpty() const
{
	return (first == nullptr) ? true : false;
}

template <typename var>
List<var>& List<var>::operator= (const List<var>& l2)
{
	if (this == &l2)
		return *this;

	this->initial_new_memory(l2.size);
	for (size_t i = 0; i < l2.size; i++)
	{
		((*this)[i]) = (l2[i]);
	}
	return *this;
}

template <>
List<char*>& List<char*>::operator= (const List<char*>& l2)
{
	if (this == &l2)
		return *this;
	for (size_t i = 0; i < l2.size; i++)
	{
		this->initial_new_memory(strlen(l2[i]) + 1);
		strcpy((*this)[i], l2[i]);
	}
	return *this;
}

template <typename var>
std::istream& operator>> (std::istream& in, List<var>& l1)
{
	std::cout << "Введите элемент для добавления в конец списка\n";
	var input_number = input<var>();
	element<var>* newElement = new element<var>;
	newElement->value = input_number;
	newElement->index = l1.size++;
	newElement->next = nullptr;
	if (l1.isEmpty())
		l1.first = newElement;
	else
		l1.last->next = newElement;
	l1.last = newElement;
	return in;
}

template <>
std::istream& operator>> (std::istream& in, List<char*>& l1)
{
	std::string str;
	std::cout << "Введите строку для добавления в конец списка\n";
	str = input<std::string>();
	const char* subline = new const char[str.length() + 1];
	subline = str.c_str();

	element<char*>* newElement = new element<char*>;
	newElement->value = new char[str.length() + 1];
	strcpy(newElement->value, subline);
	newElement->index = l1.size++;
	newElement->next = nullptr;

	if (l1.isEmpty())
		l1.first = newElement;
	else
		l1.last->next = newElement;
	l1.last = newElement;

	return in;
}

template <typename var>
std::ostream& operator<< (std::ostream& out, const List<var>& l1)
{
	if (l1.size == 0)
	{
		throw(std::string("В очереди нет элементов!\n"));
	}
	element<var>* current = l1.first;
	while (current)
	{
		out << current->value << std::endl;
		current = current->next;
	}
	std::cout << std::endl;
	return out;
}