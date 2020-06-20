МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>

### Отчёт по лабораторной работе № 3 Дешифровка текста из изображения<br/>по дисциплине "Программирование"
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



1. Закрепить навыки разработки программ использующих операторы цикла;
2. Закрепить навыки разработки программ использующих массивы;
3. Освоить методы подключения сторонних библиотек.

### Ход работы: <br>
------



1. Для работы с изображением была скачена библиотека [libbmp](https://github.com/marc-q/libbmp) .
2. Добавляем в исходные файлы проекта файл libbmp.cpp из библиотеки.<br>![](https://sun9-53.userapi.com/cbHr8wg2945CRJoal53wRDgfgsuwZHD6qkCTFQ/D-N8JhTLU9I.jpg)<br>*Рисунок 1. добавление libbmp.cpp*<br>

3. Создаём папку *include* и переносим туда файл libbmp.h и через свойства проекта подключаем данный каталог.<br>![](https://sun1.43222.userapi.com/JqsqH_fKG0c3qjJaUg8vVwoV4yDNG1xQxADKAg/g6AMvSyd5c0.jpg)<br>*Рисунок 2. Каталог include*<br>

4. Номер изображения - ***3***, ключ - ``` 00r 00g 00b 01r 01g 01b 10r 10g```.<br>![](https://neroid.ru/wp-content/uploads/2020/02/pic3.bmp) </br>
*Рисунок 3. Исследуемое изображение*<br>

**Код программы:**

```C++
include <iostream>
#include "libbmp.h"

void decoder(int d);

int main()
{
	BmpImg img;
	img.read("pic3.bmp");

	int width = img.get_width(), height = img.get_height();

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++) 
		{
			const int RED = img.red_at(i, j), GREEN = img.green_at(i, j), BLUE = img.blue_at(i, j);
			decoder(1 & RED);
			decoder(1 & GREEN);
			decoder(1 & BLUE);
		}
	}
}

void decoder(int d)
{
	static int i = 0, a[8];

	a[i] = d;
	i++;

	if (i == 8)
	{
		char s = 0;

		for (int i = 7; i >= 0; i--) s = s | (a[7 - i] << i);
		if (s == '\0') exit(0);
		std::cout << s;
		i = 0;
	}
}

```
### Результат:

------

> Thomas Jefferson (April 13, 1743[a] � July 4, 1826) was an American statesman, diplomat, lawyer, architect, philosopher, and Founding Father who served as the third president of the United States from 1801 to 1809. Previously, he had served as the second vice president of the United States from 1797 to 1801. The principal author of the Declaration of Independence, Jefferson was a proponent of democracy, republicanism, and individual rights, motivating American colonists to break from the Kingdom of Great Britain and form a new nation; he produced formative documents and decisions at both the state and national level. During the American Revolution, he represented Virginia in the Continental Congress that adopted the Declaration, drafted the law for religious freedom as a Virginia legislator, and served as the second Governor of Virginia from 1779 to 1781, during the American Revolutionary War. He became the United States Minister to France in May 1785, and subsequently the nation's first secretary of state under President George Washington from 1790 to 1793. Jefferson and James Madison organized the Democratic-Republican Party to oppose the Federalist Party during the formation of the First Party System. With Madison, he anonymously wrote the controversial Kentucky and Virginia Resolutions in 1798 and 1799, which sought to strengthen states' rights by nullifying the federal Alien and Sedition Acts. As president, Jefferson pursued the nation's shipping and trade interests against Barbary pirates and aggressive British trade policies. He also organized the Louisiana Purchase, almost doubling the country's territory. As a result of peace negotiations with France, his administration reduced military forces. He was reelected in 1804. Jefferson's second term was beset with difficulties at home, including the trial of former vice president Aaron Burr. American foreign trade was diminished when Jefferson implemented the Embargo Act of 1807, responding to British threats to U.S. shipping. In 1803, Jefferson began a controversial process of Indian tribe removal to the newly organized Louisiana Territory, and he signed the Act Prohibiting Importation of Slaves in 1807. After retiring from public office, Jefferson founded the University of Virginia. Jefferson, while primarily a planter, lawyer and politician, mastered many disciplines, which ranged from surveying and mathematics to horticulture and mechanics. He was an architect in the classical tradition. Jefferson's keen interest in religion and philosophy led to his presidency of the American Philosophical Society; he shunned organized religion but was influenced by both Christianity and deism. A philologist, Jefferson knew several languages. He was a prolific letter writer and corresponded with many prominent people. His only full-length book is Notes on the State of Virginia (1785), considered perhaps the most important American book published before 1800.[1] Although regarded as a leading spokesman for democracy and republicanism in the era of the Enlightenment, some modern scholarship has been critical of Jefferson's private life, finding a contradiction between his ownership of the large numbers of slaves that worked his plantations and his famous declaration that "all men are created equal". Although the matter remains a subject of debate, most historians believe that Jefferson had a sexual relationship with his slave Sally Hemings, a mixed-race woman who was a half-sister to his late wife, and that he fathered at least one of her children. Presidential scholars and historians generally praise Jefferson's public achievements, including his advocacy of religious freedom and tolerance in Virginia. Jefferson continues to rank highly among U.S. presidents.<br>
>

### Вывод: 

------

По завершении лабораторной работы, мной были закреплены навыки разработки программ с использованием циклов и массивов, а также освоены методы подключения библиотек.