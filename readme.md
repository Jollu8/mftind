 mtfind

Написать программу mtfind, производящую поиск подстроки в текстовом файле
по маске с использованием многопоточности.




ПРИМЕР

Файл input.txt:
```
1  I've paid my dues

2  Time after time.

3  I've done my sentence

4  But committed no crime.

5  And bad mistakes ?

6  I've made a few.

7  I've had my share of sand kicked in my face

8  But I've come through.
```


Запуск программы:

```
mtfind input.txt "?ad"
```
Ожидаемый результат:
```
3

5 5 bad

6 6 mad

7 6 had
```


Решение представить в виде архива с исходным кодом и
проектом CMake
или Visual Studio (либо в виде ссылки на онлайн Git-репозиторий).

Код должен компилироваться в GCC или MSVC.




Критерии оценки решения:
1) Правильность выдаваемых результатов

2) Качество и читабельность кода, легкость дальнейшего развития и поддержки

3) Скорость работы и потребление памяти

# Build
```
mkdir build-release
cd build-release
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
```

# Run
```
./mtfind <input file> <mask>
```
