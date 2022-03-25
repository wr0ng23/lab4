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
		cout << "Введите, что требуется сделать\n"
			<< "1) Отсортировать массив\n"
			<< "2) Создать список\n\n";
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
			cout << "Введена неверная цифра\n\n";
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
		cout << "Введите с каким типом данных вы хотите работать\n"
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
			cout << "Введена неверная цифра\n\n";
			system("pause");
		}
	}
}

template<typename T>
void creating_mass_and_sort()
{
	cout << "Введите размер массива\n";
	size_t size_mass = input<size_t>();
	T* mass = new T[size_mass]{};
	cout << "Введите элементы массива через перенос строки\n";
	for (size_t i = 0; i < size_mass; ++i)
	{
		mass[i] = input<T>(); 
	}

	while (1)
	{
		bool flag = true;
		system("cls");
		cout << "Как вы хотите отсортировать массив?\n"
			<< "1) По возрастанию\n"
			<< "2) По убыванию\n"
			<< "3) Вернутся назад\n";

		int c = input<int>();
		system("cls");
		switch (c)
		{
		case 1:
			SelectionSort(mass, size_mass);
			cout << "Массив отсортирован по возрастанию:\n";
			break;
		case 2:
			SelectionSort(mass, size_mass, 'l');
			cout << "Массив отсортирован по убыванию:\n";
			break;
		case 3:
			system("cls");
			delete[] mass;
			return;
		default:
			system("cls");
			cout << "Введена неверная цифра, повторите попытку\n";
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
	cout << "Введите количество строк\n";
	const size_t n_strings = input<size_t>();
	const char** mass = new const char* [n_strings];
	const char* subline = nullptr;
	std::string str;
	system("cls");
	for (size_t i = 0; i < n_strings; i++)
	{
		cout << "Введите строку " << i + 1 << endl;
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
		cout << "Как вы хотите отсортировать массив?\n"
			<< "1) По возрастанию\n"
			<< "2) По убыванию\n"
			<< "3) Вернутся назад\n";

		int c = input<int>();
		system("cls");
		switch (c)
		{
		case 1:
			SelectionSort(const_cast<char**>(mass), n_strings, 'u');
			cout << "Массив отсортирован по возрастанию:\n";
			break;
		case 2:
			SelectionSort(const_cast<char**>(mass), n_strings, 'l');
			cout << "Массив отсортирован по убыванию:\n";
			break;
		case 3:
			system("cls");
			delete[] mass;
			return;
		default:
			system("cls");
			cout << "Введена неверная цифра, повторите попытку\n";
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
		cout << "Введите с каким типом данных вы хотите работать\n"
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
			cout << "Введена неверная цифра\n\n";
			system("pause");
		}
		cout << "Хотите отсортировать еще один массив?(для выхода - н)\n";
		char ans = input<char>();
		if (ans == 'н')
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
		cout << "-----Меню-----\n"
			<< "1) Добавить новый элемент в конец списка\n"
			<< "2) Показать весь список\n"
			<< "3) Получить элемент заданой позиции\n"
			<< "4) Объединить два списка\n"
			<< "5) Выход\n\n";
		int answer = input<int>();
		try
		{
			system("cls");
			switch (answer)
			{
			case 1:
			{
				cin >> list1;
				cout << "Элемент успешно добавлен в конец списка.\n\n";
				system("pause");
				break;
			}
			case 2:
			{
				if (list1.get_size_of_List() == 0)
					throw std::string("Список пока что пуст\n");
				cout << "Элементы текущего списка:\n" << list1;
				system("pause");
				break;
			}
			case 3:
			{
				if (list1.get_size_of_List() == 0)
					throw std::string("Список пока что пуст\n");
				cout << "Введите индекс элемента, к которому хотите получить доступ\n";
				size_t index = input<size_t>();
				list1[index];
				cout << "Элемент списка с индексом " << index << ", равен " << list1[index] << ".\n\n";
				if (typeid(list1) != typeid(List<char*>))
				{
					cout << "Желаете ли вы изменить элемент под индексом " << index << "?(д/н)\n";
					char ans = input<char>();
					if (ans == 'д')
					{
						cout << "Введите значение для замены\n";
						list1[index] = input<T>();
						cout << "Элемент массив под индексом " << index << " успешно изменен на значение - "
							<< list1[index] << ".\n" << endl;
					}
				}
				system("pause");
				break;
			}
			case 4:
			{
				if (list1.get_size_of_List() == 0)
					throw std::string("Добавьте сначала элементы в 1 список\n");
				list2 = new List<T>;
				cout << "Создан список №2.\n";
				cout << "Сейчас вам будет предложено добавить несколько элементов в этот список.\n\n";
				system("pause"); system("cls");
				char c;
				do
				{
					cin >> *list2;
					cout << "Желаете ли вы продолжить?(для выхода введите - н)\n";
					c = input<char>();
				} while (c != 'н');
				cout << "Списки объединены.\n\n";
				List<T>* result = new List<T>;
				*result = list1 + *list2;
				cout << "Элементы 1 списка:\n" << list1
					<< "Элементы 2 списка:\n" << *list2
					<< "Элементы после объединения списков:\n" << *result;
				delete list2; 
				delete result;
				system("pause");
				break;
			}
			case 5:
				cout << "Выход из программы..\n";
				exit(1);
			default:
				cout << "Введена неверная цифра!\n";
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