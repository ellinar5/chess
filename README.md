# Игра в шахматы
[Изначальное условие проекта](https://disk.yandex.ru/d/u8xOZI_sQhHN9Q)

## ЦЕЛЬ ПРОЕКТА
- Загрузка фигур из файла input.txt
- Отображение шахматной доски с фигурами
- Распределите  фигур на черные и белый
- Вывод какая из  фигур бьет другую 

## Реализация проекта
- Файлы: main.c, *.h, *.c, input.txt
- Загрузка фигур с валидацией
- Автоматическое присваивание цветов (черные/белые)
- Проверка шахматных атак по правилам
- Поддержка фигуры Shadow (теник)

## Архитектура кода
- CreatingAChessBoard.* — загрузка и отрисовка доски
- SplittingShapesIntoColors.* — деление фигур по цвету
- CheckAttacks.* — логика атак
- main.c — консольный интерфейс
- input.txt — исходные фигуры

## Особенности реализации фигуры Тенник
- Движется по вертикали, горизонтали, диагонали (как ферзь)
- Не прыгает через другие фигуры
- В текущей реализации: не оставляет тень
- Возможность доработки механики тени

## Возможные консольные команды в main.c
- start — отобразить доску и атаки (Проверка атак и визуализация в консоли)
- help — полная справка о самой программы
- exit — выход






