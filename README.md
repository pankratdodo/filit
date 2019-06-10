# Filit Public

**Логика**
1. is_valid - Читаем и валидируем, при успехе возвращаем считанную строку (map)
[RETURN: все ок ? **map** : -1]
2. map2figures - считываем валидный ввод (в форме строки **с \n**) и засовываем в список (**s_tetris *figures**) 
[RETURN: все ок ? **figures** : -1]
3. solve_it - считываем *figures (опц. Q фигур) и выводим ответ на филит [RETURN: все ок ? 1 : -1]
4. clean_up - если где-то что-то выделяли - удаляем все

**Структура папки**
- Пары %.c:%.h
- **fillit.c** - это файл с main'ом
- libft - lib files
- Makefile (TBA)

**Порядок**
- к каждому С файлу нужен h файл, кроме него в С файлы ничего не инклюдим

**Планы**
- ! Лучше потом поменять мою либу на твою - у меня где-то есть одна ехидная сега
- В Makefile необходимо проверить и убрать "-g" дебаг флажки
- ...
