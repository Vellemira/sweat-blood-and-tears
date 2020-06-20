МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>

### Отчёт по лабораторной работе № 5<br/> по дисциплине "Программирование"
<br/>

студентки 1 курса группы ИВТ-б-о-192(1)  
Николаевой Владимиры Григорьевны   
направления подготовки 09.03.01 "Информатика и вычислительная техника"    
<br/>

<table>
<tr><td>Научный руководитель<br/> старший преподаватель кафедры<br/> компьютерной инженерии и моделирования</td>
<td>(оценка)</td>
<td>Чабанов В.В.</td>
</tr>
</table>
<br/><br/>

Симферополь, 2020

<br><br><br>

### Цель: <br>
------

1. Научиться работать с текстовыми файлами;
2. Закрепить навыки работы со структурами.


### Ход работы: <br>
------

1. Скачиваем необходимые файлы из [репозитория](https://github.com/rebeccabilbro/titanic), а именно: train.csv , data_dictionary.txt 
2. Основываясь на файле data_dictionary.txt реализовываем структуру Passenger.
   </br><br>

#### Main.cpp:

```C++

#include <iostream>
#include<vector>
#include<fstream>
#include<string>

using namespace std;

enum class Sex 
{ 
	Female,
	Male 
};
enum class Pclass 
{
	FIRST = 1, 
	SECOND, 
	//THIRD 
};
enum Embarked
{ 
	C, 
	Q, 
	S 
};

struct Passenger 
{
	int number;
	bool survival;
	Pclass pclass;
	string name;
	Sex sex;
	double age;
	int sibsp, parch;
	string ticket;
	double fare;
	string cabin;
	Embarked embarked;
};

vector<int> children;
vector<Passenger> passengers;

int ending = -1;
int endingSize = 1;

string readToStr(string str, string endingStr) 
{
	int begin = ending + endingSize;

	ending = str.find(endingStr, begin);
	endingSize = endingStr.size();

	return str.substr(begin, ending - begin);
}

string reading(ifstream& fin, char ending = '\r')
{
	string s = "";
	char storage;

	while (fin.read(&storage, 1)) 
	{
		if (storage != ending) 
			s += storage;
		else
			break;
	}

	return s;
}

string state(Embarked max) 
{
	if (max == 0)  
		return "C";
	else if (max == 1) 
		return "Q";
	else 
		return "S";
}

int main()
{
	setlocale(LC_ALL, "RUS");
	ifstream fin("train1.csv");
	if (!fin)
	{
		cout << "Error!";
		exit(1);
	}
	ofstream fout("File1.txt");
	string rString;
	reading(fin, '\r');

	while (true) 
	{

		ending = -1;

		rString = reading(fin, '\r');
		if (rString == "") 
			break;

		Passenger p;
		p.number = stoi(readToStr(rString, ","));
		p.survival = stoi(readToStr(rString, ","));
		p.pclass = (Pclass)stoi(readToStr(rString, ",\""));
		p.name = readToStr(rString, "\",");
		p.sex = readToStr(rString, ",") == "male" ? Sex::Male : Sex::Female;

		string years = readToStr(rString, ",");

		if (years == "") 
			p.age = -1;
		else 
			p.age = stod(years);

		p.sibsp = stoi(readToStr(rString, ","));
		p.parch = stoi(readToStr(rString, ","));
		p.ticket = readToStr(rString, ",");
		p.fare = stod(readToStr(rString, ","));
		p.cabin = readToStr(rString, ",");

		string em = readToStr(rString, ",");
		if (em == "C") 
			p.embarked = Embarked::C;
		else if (em == "Q") 
			p.embarked = Embarked::Q;
		else 
			p.embarked = Embarked::S;

		passengers.push_back(p);
	}

	int survivalAll = 0, first = 0, second = 0, third = 0, female = 0, male = 0;
	double averageAge = 0;
	int femaleAll = 0, maleAll = 0;
	double averageFemaleAge = 0, averageMaleAge = 0;
	int aState[3]{};
	int age_all = 0;
	Embarked stateMax = C;

	for (int i = 0; i < passengers.size(); i++) 
	{
		if (passengers[i].survival) 
		{
			survivalAll++;
			if (passengers[i].pclass == Pclass::FIRST)
				first++;
			else if (passengers[i].pclass == Pclass::SECOND)
				second++;
			else 
				third++;

			if (passengers[i].sex == Sex::Female) 
				female++;
			else 
				male++;
		};

		if (passengers[i].age != -1) 
		{
			averageAge += passengers[i].age;
			age_all++;

			if (passengers[i].sex == Sex::Female) 
			{
				femaleAll++;
				averageFemaleAge += passengers[i].age;
			}

			else 
			{
				maleAll++;
				averageMaleAge += passengers[i].age;
			}
		}

		aState[passengers[i].embarked]++;

		if (passengers[i].age < 18 && passengers[i].age != -1) 
			children.push_back(passengers[i].number);
	}
	averageAge /= age_all;
	averageFemaleAge /= femaleAll;
	averageMaleAge /= maleAll;

	if (aState[stateMax] < aState[Q]) 
		stateMax = Q;
	if (aState[stateMax] < aState[S]) 
		stateMax = S;

	fout << "Общее число выживших:" << survivalAll << '\n'
		<< "Число выживших из 1 класса:" << first << '\n'
		<< "Число выживших из 2 класса:" << second << '\n'
		<< "Число выживших из 3 класса:" << third << '\n'
		<< "Количество выживших женщин:" << female << '\n'
		<< "Количество выживших мужчин:" << male << '\n'
		<< "Средний возраст пассажира:" << averageAge << '\n'
		<< "Средний возраст женщин:" << averageFemaleAge << '\n'
		<< "Средний возраст мужчин:" << averageMaleAge << '\n'
		<< "Штат, в котором село больше всего пассажиров:" << state(stateMax) << '\n'
		<< "Список идентификаторов несовершеннолетних (младше 18) пассажиров:" << '\n';

	for (int i = 0; i < children.size(); i++) 
	{
		if (i == children.size() - 1) 
		{
			fout << children[i];
			break;
		}

		fout << children[i] << ",";
	}

	fout.close();
	fin.close();
}
```
Таблица с характеристиками:<br>
|                                           **Характеристика** | **Результат**                                                |
| -----------------------------------------------------------: | ------------------------------------------------------------ |
|                                         Общее число выживших | 342                                                          |
|                                   Число выживших из 1 класса | 136                                                          |
|                                   Число выживших из 2 класса | 87                                                           |
|                                   Число выживших из 3 класса | 119                                                          |
|                                   Количество выживших женщин | 233                                                          |
|                                   Количество выживших мужчин | 109                                                          |
|                                    Средний возраст пассажира | 29.6793                                                      |
|                                      Средний  возраст женщин | 27.9042                                                      |
|                                      Средний  возраст мужчин | 30.702                                                       |
|                 Штат, в котором село больше всего пассажиров | S                                                            |
| Список идентификаторов несовершеннолетних (младше 18) пассажиров | 8,10,11,15,17,23,25,40,44,51,59,60,64,69,72,79,85,87,112,115,120,126,139,148,157,164,165,166,172,173,183,184,185,194,206,209,221,234,238,<br>262,267,279,283,298,306,308,330,334,341,349,353,375,382,387,390,408,420,434,436,446,447,449,470,480,481,490,501,505,531,533,536,542,543,<br>550,551,575,619,635,643,645,684,687,690,692,721,722,732,747,751,752,756,765,778,781,782,788,789,792,803,804,814,820,825,828,831,832,842,<br>845,851,853,854,870,876 |
<br>

В итоге получаем файл с результатом: [result.txt](https://github.com/Vellemira/sweat-blood-and-tears/blob/master/Labs/Laba%205/result.txt)

### Вывод:

------

Выполнив лабораторную работу, я закрепила навыки работы со структурами, csv-файлами и научилась работать с текстовыми файлами.