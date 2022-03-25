#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <typeinfo>
#include "SelectionSort.h"
#include "safe_input.h"
#include "List.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	void menu_list();
	void menu_selection_sort();

	while (1)
	{
		system("cls");
		cout << "�������, ��� ��������� �������\n"
			<< "1) ������������� ������\n"
			<< "2) ������� ������\n\n";
		int answer = input<int>();
		if (answer == 1)
		{
			menu_selection_sort();
		}
		else if (answer == 2)
		{
			menu_list();
		}
		else
		{
			system("cls");
			cout << "������� �������� �����\n\n";
			system("pause");
		}
	}

	return 0;
}

template <typename T>
void menu_list2(List<T>&);

void menu_list()
{
	while (1)
	{
		system("cls");
		cout << "������� � ����� ����� ������ �� ������ ��������\n"
			<< "1) int\n2) char\n3) float\n4) double\n5) char*\n\n";
		int answer = input<int>();

		switch (answer)
		{
		case 1:
		{
			List<int>* list = new List<int>;
			menu_list2(*list);
			break;
		}
		case 2:
		{
			List<char>* list = new List<char>;
			menu_list2(*list);
			break;
		}
		case 3:
		{
			List<float>* list = new List<float>;
			menu_list2(*list);
			break;
		}
		case 4:
		{
			List<double>* list = new List<double>;
			menu_list2(*list);
			break;
		}
		case 5:
		{
			List<char*>* list = new List<char*>;
			menu_list2(*list);
			break;
		}
		default:
			system("cls");
			cout << "������� �������� �����\n\n";
			system("pause");
		}
	}
}

template<typename T>
void creating_mass_and_sort()
{
	cout << "������� ������ �������\n";
	size_t size_mass = input<size_t>();
	T* mass = new T[size_mass]{};
	cout << "������� �������� ������� ����� ������� ������\n";
	for (size_t i = 0; i < size_mass; ++i)
	{
		mass[i] = input<T>(); 
	}

	while (1)
	{
		bool flag = true;
		system("cls");
		cout << "��� �� ������ ������������� ������?\n"
			<< "1) �� �����������\n"
			<< "2) �� ��������\n"
			<< "3) �������� �����\n";

		int c = input<int>();
		system("cls");
		switch (c)
		{
		case 1:
			SelectionSort(mass, size_mass);
			cout << "������ ������������ �� �����������:\n";
			break;
		case 2:
			SelectionSort(mass, size_mass, 'l');
			cout << "������ ������������ �� ��������:\n";
			break;
		case 3:
			system("cls");
			delete[] mass;
			return;
		default:
			system("cls");
			cout << "������� �������� �����, ��������� �������\n";
			flag = false;
		}
		if (flag == true)
		{
			for (size_t i = 0; i < size_mass; ++i)
			{
				cout << mass[i] << " ";
			}
		}
		cout << endl;
		system("pause");
	}
}

template<>
void creating_mass_and_sort<char*>() 
{
	cout << "������� ���������� �����\n";
	const size_t n_strings = input<size_t>();
	const char** mass = new const char* [n_strings];
	const char* subline = nullptr;
	std::string str;
	system("cls");
	for (size_t i = 0; i < n_strings; i++)
	{
		cout << "������� ������ " << i + 1 << endl;
		str = input<std::string>();
		subline = new char[str.length() + 1];
		mass[i] = new char[str.length() + 1];
		subline = str.c_str();
		strcpy(const_cast<char*>(mass[i]), subline);
		cout << endl;
	}
	system("pause");
	while (1)
	{
		bool flag = true;
		system("cls");
		cout << "��� �� ������ ������������� ������?\n"
			<< "1) �� �����������\n"
			<< "2) �� ��������\n"
			<< "3) �������� �����\n";

		int c = input<int>();
		system("cls");
		switch (c)
		{
		case 1:
			SelectionSort(const_cast<char**>(mass), n_strings, 'u');
			cout << "������ ������������ �� �����������:\n";
			break;
		case 2:
			SelectionSort(const_cast<char**>(mass), n_strings, 'l');
			cout << "������ ������������ �� ��������:\n";
			break;
		case 3:
			system("cls");
			delete[] mass;
			return;
		default:
			system("cls");
			cout << "������� �������� �����, ��������� �������\n";
			flag = false;
		}
		if (flag == true)
		{
			for (size_t i = 0; i < n_strings; ++i)
			{
				cout << i + 1 << ") " << mass[i] << endl;
			}
		}
		cout << endl;
		system("pause");
	}
}

void menu_selection_sort()
{
	while (1)
	{
		system("cls");
		cout << "������� � ����� ����� ������ �� ������ ��������\n"
			<< "1) int\n2) char\n3) float\n4) double\n5) char*\n\n";
		int answer = input<int>();
		system("cls");
		switch (answer)
		{
		case 1:
		{
			creating_mass_and_sort<int>();
			break;
		}
		case 2:
		{
			creating_mass_and_sort<char>();
			break;
		}
		case 3:
		{
			creating_mass_and_sort<float>();
			break;
		}
		case 4:
		{
			creating_mass_and_sort<double>();
			break;
		}
		case 5:
		{
			creating_mass_and_sort<char*>();
			break;
		}
		default:
			system("cls");
			cout << "������� �������� �����\n\n";
			system("pause");
		}
		cout << "������ ������������� ��� ���� ������?(��� ������ - �)\n";
		char ans = input<char>();
		if (ans == '�')
			exit(1);
	}
}

template <typename T>
void menu_list2(List<T>& list1)
{
	List<T>* list2 = nullptr;
	while (1)
	{
		system("cls");
		cout << "-----����-----\n"
			<< "1) �������� ����� ������� � ����� ������\n"
			<< "2) �������� ���� ������\n"
			<< "3) �������� ������� ������� �������\n"
			<< "4) ���������� ��� ������\n"
			<< "5) �����\n\n";
		int answer = input<int>();
		try
		{
			system("cls");
			switch (answer)
			{
			case 1:
			{
				cin >> list1;
				cout << "������� ������� �������� � ����� ������.\n\n";
				system("pause");
				break;
			}
			case 2:
			{
				if (list1.get_size_of_List() == 0)
					throw std::string("������ ���� ��� ����\n");
				cout << "�������� �������� ������:\n" << list1;
				system("pause");
				break;
			}
			case 3:
			{
				if (list1.get_size_of_List() == 0)
					throw std::string("������ ���� ��� ����\n");
				cout << "������� ������ ��������, � �������� ������ �������� ������\n";
				size_t index = input<size_t>();
				list1[index];
				cout << "������� ������ � �������� " << index << ", ����� " << list1[index] << ".\n\n";
				if (typeid(list1) != typeid(List<char*>))
				{
					cout << "������� �� �� �������� ������� ��� �������� " << index << "?(�/�)\n";
					char ans = input<char>();
					if (ans == '�')
					{
						cout << "������� �������� ��� ������\n";
						list1[index] = input<T>();
						cout << "������� ������ ��� �������� " << index << " ������� ������� �� �������� - "
							<< list1[index] << ".\n" << endl;
					}
				}
				system("pause");
				break;
			}
			case 4:
			{
				if (list1.get_size_of_List() == 0)
					throw std::string("�������� ������� �������� � 1 ������\n");
				list2 = new List<T>;
				cout << "������ ������ �2.\n";
				cout << "������ ��� ����� ���������� �������� ��������� ��������� � ���� ������.\n\n";
				system("pause"); system("cls");
				char c;
				do
				{
					cin >> *list2;
					cout << "������� �� �� ����������?(��� ������ ������� - �)\n";
					c = input<char>();
				} while (c != '�');
				cout << "������ ����������.\n\n";
				List<T>* result = new List<T>;
				*result = list1 + *list2;
				cout << "�������� 1 ������:\n" << list1
					<< "�������� 2 ������:\n" << *list2
					<< "�������� ����� ����������� �������:\n" << *result;
				delete list2; 
				delete result;
				system("pause");
				break;
			}
			case 5:
				cout << "����� �� ���������..\n";
				exit(1);
			default:
				cout << "������� �������� �����!\n";
				system("pause");
			}
		}
		catch (std::string& ex)
		{
			cout << ex << endl;
			system("pause");
		}
	}
}