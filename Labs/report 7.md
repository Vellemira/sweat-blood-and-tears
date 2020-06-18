МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>

### Отчёт по лабораторной работе № 7<br/> по дисциплине "Программирование"
<br/>

студентки 1 курса группы ИВТ-б-о-192(1)  
Николаевой Владимира Григорьевна  
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


### Цель: изучить основные возможности создания и отладки программ в IDE Qt Creator.

1. Как создать консольное приложение С++ в IDE Qt Creator без использования компонентов Qt?</br>
    Необходимо открыть QT Creator, затем:<br>
    `Проекты -> Создать -> Приложение -> Консольное приложение QT`, либо ` Проект без QT -> Приложение на языке C++`
    Рис 1.1, Рис 1.2, Рис 1.3<br><br>
    ![](https://sun3.43222.userapi.com/OI_kdab3Cid6d6SuDjc5B1D3WzAXj8hzd7kUYQ/lw_ps9vPcv8.jpg)<br>
   Рисунок 1. Создание проекта QT.<br><br>
    ![](https://sun1.43222.userapi.com/XWjWswSotCxmAf852MBVeZ3nS-Eb2O_ABzp9Cw/AXgGxi_azVM.jpg)
    <br> Рисунок 1.2 Создание консольного приложения QT.<br><br>
   
2. Как изменить цветовую схему (оформление) среды?
    Необходимо нажать на меню `Инструменты -> Параметры -> Среда`, после чего выбирать темы.<br>
    ![](https://sun1.43222.userapi.com/LBVgzP6bdDym-dP7kJeRRPXe2vtQYB-OdM-8aA/HRLkbC9XFPc.jpg)
    <br>Рисунок 2. Смена оформления, этап 1.<br>
    ![](https://sun2.43222.userapi.com/KL8SRZN9SZERGqDxq8_KY5iASrPZDXatUQg5Xg/ZDaN8VqVkd4.jpg)
<br>Рисунок 2.1 Смена оформления, этап 2<br>
    
3. Как закомментировать/раскомментировать блок кода средствами Qt Creator?<br>
    С помощью сочетания клавиш `CTRL + /`
    
4. Как открыть в проводнике Windows папку с проектом средствами Qt Creator?<br>
  Необходимо нажать на любой файл в проекте правой кнопкой мыши -> показать в проводнике.<br>
  ![img](https://sun2.43222.userapi.com/UJOf5OC678QX_KKgPUtZ8l_Gmip2ThzkkjsECA/sKUQXz6GgVA.jpg)
  <br><br>

5. Какое расширение файла-проекта используется Qt Creator?
`.pro`<br>
![](https://sun9-38.userapi.com/c857128/v857128488/e8b2e/YqCqBWkRcPY.jpg)<br>Рисунок 3. Расширение проекта

6. Как запустить код без отладки?<br>
`CTRL + R`, либо значок зелёной стрелочки.<br>
![](https://sun1.43222.userapi.com/4quegVLFgwb0lbTlhJeFvk922582JEN8MXMM4w/i_dl67K470I.jpg)
<br>Рисунок 4. Запуск кода без отладки<br>
7. Как запустить код в режиме отладки?<br>
  Зелёная `стрелочка с жуком`, либо F5<br>
  ![](https://sun9-2.userapi.com/al_dCFHEPUvnuJJnopLgC9p0t_HBYsD-MerUAQ/T3X8L0VQebc.jpg)
  <br>Рисунок 5. Запуск кода с отладкой.<br>

8. Как установить/убрать точку останова (breakpoint)?
  `F9`

9. Создайте программу со следующим кодом:
  </textarea></div>
     <div class="crayon-main" style="position: relative; z-index: 1; overflow: hidden;">
       <table class="crayon-table" style="">
         <tbody><tr class="crayon-row">
       <td class="crayon-nums " data-settings="show">
         <div class="crayon-nums-content" style="font-size: 12px !important; line-height: 15px !important;"><div class="crayon-num" data-line="crayon-5e4d633787600825781143-1">1</div><div class="crayon-num crayon-striped-num" data-line="crayon-5e4d633787600825781143-2">2</div><div class="crayon-num" data-line="crayon-5e4d633787600825781143-3">3</div><div class="crayon-num crayon-striped-num" data-line="crayon-5e4d633787600825781143-4">4</div><div class="crayon-num" data-line="crayon-5e4d633787600825781143-5">5</div><div class="crayon-num crayon-striped-num" data-line="crayon-5e4d633787600825781143-6">6</div><div class="crayon-num" data-line="crayon-5e4d633787600825781143-7">7</div><div class="crayon-num crayon-striped-num" data-line="crayon-5e4d633787600825781143-8">8</div><div class="crayon-num" data-line="crayon-5e4d633787600825781143-9">9</div></div>
       </td>
           <td class="crayon-code"><div class="crayon-pre" style="font-size: 12px !important; line-height: 15px !important; -moz-tab-size:4; -o-tab-size:4; -webkit-tab-size:4; tab-size:4;"><div class="crayon-line" id="crayon-5e4d633787600825781143-1"><span class="crayon-p">#include &lt;iostream&gt;</span></div><div class="crayon-line crayon-striped-line" id="crayon-5e4d633787600825781143-2"><span class="crayon-t">int</span><span class="crayon-h"> </span><span class="crayon-e">main</span><span class="crayon-sy">(</span><span class="crayon-sy">)</span><span class="crayon-h"> </span><span class="crayon-sy">{</span></div><div class="crayon-line" id="crayon-5e4d633787600825781143-3"><span class="crayon-h">&nbsp;&nbsp;&nbsp;&nbsp;</span><span class="crayon-t">int</span><span class="crayon-h"> </span><span class="crayon-v">i</span><span class="crayon-sy">;</span></div><div class="crayon-line crayon-striped-line" id="crayon-5e4d633787600825781143-4"><span class="crayon-h">&nbsp;&nbsp;&nbsp;&nbsp;</span><span class="crayon-t">double</span><span class="crayon-h"> </span><span class="crayon-v">d</span><span class="crayon-sy">;</span></div><div class="crayon-line" id="crayon-5e4d633787600825781143-5"><span class="crayon-h">&nbsp;&nbsp;&nbsp;&nbsp;</span><span class="crayon-v">i</span><span class="crayon-h"> </span><span class="crayon-o">=</span><span class="crayon-h"> </span><span class="crayon-cn">5</span><span class="crayon-sy">;</span></div><div class="crayon-line crayon-striped-line" id="crayon-5e4d633787600825781143-6"><span class="crayon-h">&nbsp;&nbsp;&nbsp;&nbsp;</span><span class="crayon-v">d</span><span class="crayon-h"> </span><span class="crayon-o">=</span><span class="crayon-h"> </span><span class="crayon-cn">5</span><span class="crayon-sy">;</span></div><div class="crayon-line" id="crayon-5e4d633787600825781143-7"><span class="crayon-h">&nbsp;&nbsp;&nbsp;&nbsp;</span><span class="crayon-v">std</span><span class="crayon-o">::</span><span class="crayon-r">cout</span><span class="crayon-h"> </span><span class="crayon-o">&lt;&lt;</span><span class="crayon-h"> </span><span class="crayon-v">i</span><span class="crayon-h"> </span><span class="crayon-o">&lt;&lt;</span><span class="crayon-h"> </span><span class="crayon-v">d</span><span class="crayon-sy">;</span></div><div class="crayon-line crayon-striped-line" id="crayon-5e4d633787600825781143-8"><span class="crayon-h">&nbsp;&nbsp;&nbsp;&nbsp;</span><span class="crayon-st">return</span><span class="crayon-h"> </span><span class="crayon-cn">0</span><span class="crayon-sy">;</span></div><div class="crayon-line" id="crayon-5e4d633787600825781143-9"><span class="crayon-sy">}</span></div></div></td>
         </tr>
       </tbody></table>
     </div>
   </div>

* Переключитесь в конфигурацию сборки «Отладка»;
* Установите breakpoint на 5, 6 и 7 строках;
* Запустите приложение щелкнув по кнопке с изображением жука .
* Используйте эту же кнопку для перехода к следующей точке останова;
* Какое значение содержит переменная i в 5й строке?
  Значение 0.
* Какое значение содержит переменная d в 6й строке?<br>
 ![](https://sun1.43222.userapi.com/W_gIbo297ig3uZMJsiqCoAS-2P4p0vunU-fjDg/8GGnrYVKEto.jpg)<br>Рисунок 6. Значение переменной
* Какие значение содержатся в переменных i и  d в 7й строке?
5 и 5
* Совпадают ли эти значения с теми, что вы получали в MSVS для соответствующих типов? Нет, не совпадают.

15. Открываем файл main.cpp -> ЛКМ на `calc.show();` -> Жмём F1.
![](![img](https://sun3.43222.userapi.com/RqGfx_SQhgMLizUG94DlsENjW0p6yvg3ZLgoIQ/3ckPcZd9Chw.jpg)<br> Рисунок 7. Справка по функции `show();`
16. Формы -> Выбираем файл с расширением .ui, в нём будет возможность редактировать внешний вид нашего приложения.<br>
![](https://sun9-14.userapi.com/5AVeZmE85o5MTX5zQhB--Dk3ufzFc19L8Dgf4g/FcBX7MnlLFo.jpg)<br>Рисунок 8. Видоизменённое приложение<br>
Вывод: получены навыки создания проекта в среде QT. Также получены навыки использования некоторых горячих клавиш.
