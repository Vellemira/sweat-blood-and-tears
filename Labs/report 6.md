МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>
### Отчёт по лабораторной работе № 6<br/> по дисциплине "Программирование"
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
# Погодный информер<br>
## Цель:<br>
1. Закрепить навыки разработки многофайловыx приложений;

2. Изучить способы работы с API web-сервиса;
3. Изучить процесс сериализации/десериализации данных.

## Ход работы:<br>
1. Скачиваем [библиотеку](https://github.com/yhirose/cpp-httplib) для работы с сетью.
2. После регистрации на сервисе получаем API Ключ - ```f5702589f53fd693876c088f8f8e12e3```
3. 
```c++
#include <iostream>
#include <fstream>
#include <string>

#include "httplib/httplib.h"
#include "include/HC.cfg.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;
using namespace std;

void replace(string& str, const string& from, const string& to);

void gResponse(const httplib::Request& req, httplib::Response& res);

int main()
{
	cout << "server is running" << endl;

	httplib::Server server;
	server.Get("/", gResponse);
	server.listen("localhost", 3000);
}

void replace(string& str, const string& from, const string& to)
{
	size_t beginning = str.find(from);

	if (beginning == string::npos) 
		return;
	str.replace(beginning, from.length(), to);
}

void gResponse(const httplib::Request& req, httplib::Response& res)
{
	string s;

	httplib::Client cli("api.openweathermap.org", 80);
	auto result = cli.Get("/data/2.5/forecast?id=693805&APPID=f5702589f53fd693876c088f8f8e12e3&units=metric");

	json j = json::parse(result->body);
	cout << j.at("city").at("name") << endl;

	int start = j.at("list")[0].at("dt");

	ifstream ifs("Weather.html");
	getline(ifs, s, '\0');
	ifs.close();
	replace(s, "{city.name}", j.at("city").at("name"));

	for (auto& el : j.at("list").items()) {

		if (el.value().at("dt") >= start) 
		{
			replace(s, "{list.dt}", el.value().at("dt_txt"));
			replace(s, "{list.weather.icon}", el.value().at("weather")[0].at("icon"));
			replace(s, "{list.main.temp}", to_string(el.value().at("main").at("temp")));
			start += 86400;
		}
	}

	res.set_content(s, "text/html");
}
```
4. В итоге получаем вывод информации о погоде:![img](https://sun9-39.userapi.com/M6U-USwznrZTq6_xGMx9srIjQ7bO51szMY5yrg/oJF4oBv-Oyw.jpg)<br>*Рисунок 1. Результат*<br>

## Вывод:
Выполнив лабораторную работу, я закрепила навыки разработки многофайловых приложений, изучила процесс сериализации/десериализации данных, а также научилась работать с API.