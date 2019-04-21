# Objektinis Programavimas


## Trečia OOP užduotis

## Releases


# Link
[Reikalavimai](https://github.com/objprog/paskaitos2019/wiki/3-oji-u%C5%BEduotis#reik-versijai-1.1)

## failo formatas
Mano programoje nenaudojama pirma eilute su "nd1 nd2 nd3"
Vardas Pavarde nd nd nd nd ... Egzaminas
```
Andrius Jokubauskas 2 4 5 6 9 9 9 5
```
Makefile commands:
## make

## clean
istrina main ir .o failus

# Versijos 1.1 analize
# 10 studentu 20 pazymiu
* Vector 0.0312 s
* List 0.0220012 s
* Deque 0.0080004 s

# 100 studentu 20 pazymiu
* Vector 0.0156 s
* List 0.0312001 s
* Deque 0.0156001 s

# 1000 studentu 20 pazymiu
* Vector 0.0780001 s
* List 0.0780002 s
* Deque 0.0780001 s

# 10000 studentu 20 pazymiu
* Vector 0.655201 s
* List 0.686401 s
* Deque 0.639601 s

# 100000 studentu 20 pazymiu
* Vector 5.75641 s
* List 4.33561 s
* Deque 4.52401 s

# 1m studentu 20 pazymiu
* Vector 21.7257 s
* List 21.8868 s
* Deque 20.3454 s
## Makefile guide
```
CC=g++
main:
	$(CC) -o main main.cpp funkcijos.cpp Studentas.cpp
GenerateFile:
	$(CC) -o GenerateFile SarasoGen.cpp
clean:
	rm *.o *.exe *.txt

```
* main - sukuria exe file programai paleisti
* GenerateFile sukuria exe file .txt file generavimui
* clean isvalo .exe ir .o failus

## Ver. 1.1 analize

# strategija 2 optimizuoto vector varianto rezultatai naudojant struct
* 100 studentu 10 pazymiu 0.0475008 s
* 1000 studentu 10 pazymiu 0.0900013 s
* 10000 studentu 10 pazymiu 0.547508 s
* 100000 studentu 10 pazymiu 3.93757 s

# strategija 2 optimizuoto vector varianto rezultatai naudojant class be optimizacijos
* 100 studentu 10 pazymiu 0.0030002 s
* 1000 studentu 10 pazymiu 0.0600034 s
* 10000 studentu 10 pazymiu 0.17201 s
* 100000 studentu 10 pazymiu 1.86511 s

# strategija 2 optimizuoto vector varianto rezultatai naudojant class -O2
* 100 studentu 10 pazymiu 0.0090005 s
* 1000 studentu 10 pazymiu 0.0140008 s
* 10000 studentu 10 pazymiu 0.555032 s
* 100000 studentu 10 pazymiu 1.14307 s

# -O3 nepadare jokio efekto.