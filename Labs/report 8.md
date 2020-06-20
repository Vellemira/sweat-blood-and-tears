МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>

### Отчёт по лабораторной работе № 8<br/> по дисциплине "Программирование"
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
## Настройка Qt Creator для разработки приложений под android
### Цель:
------

1. Настроить IDE Qt Creator для разработки приложений под android ОС;
2. Изучить базовые понятия связанные с мобильной разработкой;
3. Научиться создавать мобильные приложения при помощи фреймворка Qt 5.14.

### Ход работы
------

**Установка JDK 8** <br>
JDK использовался мной ранее. Мне пришлось только проверить текущую версию и обновиться.

![img](https://psv4.userapi.com/c856320/u166751189/docs/d14/d6190b35e1c8/h7J4EDdeO_s.jpg?extra=VfQaIm83VjdyqKzA7QNmDe9p6ZAk_kgGnefRFlk-1l0bTvSaBQWOfAdkVLdWAUQdY0PGBEbz1yBrRO9gSqZsMb7lZDGXsrbb2YaESJ3aW1yrwXa6eGtOcy81ooAFm5regY5koTGWQBomx02ru7VMnDfu)<br>*Рисунок 1. Проверка версии JDK*<br>

**Установка Android Studio**<br>
Скачиваем и устанавливаем с [этого](https://developer.android.com/studio) сайта Android Studio. <br>
После установки Android Studio устанавливаем SDK нужной версии.<br>
![](https://psv4.userapi.com/c856320/u166751189/docs/d9/3c63b4121e31/gkdscv.jpg?extra=4DVvs1VCk7EyTuMUeeqVrzwLInS4xYkO9iAvktiGNo6hhULsrEP0YV4WklVm5xGtsU1DVFusrwDQFmoCInj5l57E7E-mXdmdOdwdEsJio24bLqArQ9Sz7nMeB0GN2JiQ0jCjcMWaeHIe9aabO-V6GAis)

*Рисунок 2. SDK*<br>
Так как Android Studio была установлена ранее и использовалась не в связки с QT, я вручную установила дополнительные компоненты, а именно: NDK, с [официиального](https://developer.android.com/ndk/downloads/) сайта.<br>
**Настройка QT**<br>
Затем был настроен QT, путём подключения JDK, SDK, NDK.<br>

![](https://psv4.userapi.com/c856320/u166751189/docs/d9/a70a8f8a7f87/dfhhl.jpg?extra=mJJtDtlHsv9L5YOxLrutOO_pYcLltK6qQQkJs_s1cC3xD0zuVPnj1FaS0LyhV7hnsnM1JQJjqEziKm6bK8CzAECvsdKlyJP1pZe_X8ao1QGGXtqsqg2dflSH-CkexGv6F1PNECJBTCvngw7ChIl9F2rO)
<br> *Рисунок 3. Правильная настройка QT* <br>

**Запуск Android проекта**<br>
Запускаем любой понравившийся проект на Android. <br>

Мой выбор пал на Qt SCXML Calculator.<br>

Изрядно попотев, в конечном итоге мне удалось запустить это приложение на своём новеньком смартфоне Redmi Note 9s.

![](https://psv4.userapi.com/c856324/u166751189/docs/d4/02c61928601b/GDe4oLx15wY.jpg?extra=Jwb62s4pbZQ84AshzMLCiaItAcNHXUh2AWRAjSgtjRHziIgeoV0O_q8AXnTAryIYT0_x7okGDBxaZxGypuu5bATexNVUDEeIAvZpjJO3y5bt3QeGBpugg7O7CO__rvOi1Z2b48magwKW2BjS6f2vG_Ms)

*Рисунок 4. Запуск приложения на телефоне*



### Вывод:<br>
------

При выполнении лабораторной работы мной была произведена адаптация QT Creator для разработки приложений под Android OC, изучены базовые понятия мобильной разработки, а также получены навыки создания и отладки Android приложений на языке C++.
