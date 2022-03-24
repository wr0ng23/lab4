#pragma once
#include <iostream>

template <typename T>
T input()
{
	T answer{};
	while (1)
	{
		std::cin.unsetf(std::ios::skipws);
		std::cout << "Ввод: ";
		std::cin >> answer;
		if (std::cin.good())
		{
			std::cin.ignore(100, '\n');
			return answer;
		}
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Повторите попытку ввода, произошла ошибка!" << std::endl;
	}
}