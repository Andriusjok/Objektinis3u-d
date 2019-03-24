# Objektinis Programavimas


## Antra užduotis
### [v1.0 antra strategija](https://github.com/Andriusjok/ObjekProg/releases/tag/V1.02Strat) - (2019-03-24) 
### [v1.0 pirma strategija](https://github.com/Andriusjok/ObjekProg/releases/tag/V1_pirma_strat) - (2019-03-24)  
### [v0.5](https://github.com/Andriusjok/ObjekProg/releases/tag/Version0.5) - (2019-03-10) 
### [v0.4](https://github.com/Andriusjok/ObjekProg/releases/tag/Ver0.4) - (2019-03-03) 
### [v0.3](https://github.com/Andriusjok/ObjekProg/releases/tag/v0.3) - (2019-02-24)
### [v0.2](https://github.com/Andriusjok/ObjekProg/releases/tag/V0.2E) - (2019-02-17)
### [v0.1](https://github.com/Andriusjok/ObjekProg/releases/tag/0.1FixedBugs) - (2019-02-17)

## Versiju Fix'es
[v0.4](https://github.com/Andriusjok/ObjekProg/releases/tag/ver0.4F) - (2019-03-10)
# Link
[Reikalavimai](https://github.com/objprog/paskaitos2019/wiki/2-oji-u%C5%BEduotis)

[0.5 Dokumentacija](#user-content-versijos-05-analize)


## V0.2 failo formatas
Mano programoje nenaudojama pirma eilute su "nd1 nd2 nd3"
Vardas Pavarde nd nd nd nd ... Egzaminas
```
Andrius Jokubauskas 2 4 5 6 9 9 9 5
```
Makefile commands:
## make
Sukuria .o failus ir juos sulinkina i "main" faila.
## clean
istrina main ir .o failus
## V0.4 Rezultatai
------------------------------------------------------------
* 10 studentu 10 pazymiu
![Rezultatai](https://i.imgur.com/eR9Ch3D.png)
* 100 studentu 10 pazymiu
![Rezultatai](https://i.imgur.com/3PjcBh6.png)
* 1000 studentu 10 pazymiu
![Rezultatai](https://i.imgur.com/nmrE4hJ.png)
* 10000 studentu 10 pazymiu
![Rezultatai](https://i.imgur.com/kqrcstP.png)
* 100000 studentu 10 pazymiu
![Rezultatai](https://i.imgur.com/W0WxAto.png)
------------
# Versijos 0.5 analize
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
## 0.5 Makefile guide
```
CC=g++
Vector:
	$(CC) -o Vector VectorApdorojimas.cpp funkcijos.cpp
Deque: 
	$(CC) -o Deque DeQueApdorjimas.cpp Dequefunkcijos.cpp
List:
	$(CC) -o List ListApdorojimas.cpp Listfunkcijos.cpp
GenerateFile:
	$(CC) -o GenerateFile SarasoGen.cpp
clean:
	rm *.o *.exe *.txt
```
* Vector - sukuria exe file realizacijai su vektorium
* Deque - sukuria exe file realizacijai su deque
* List - sukuria exe file realizacijai su list
* GenerateFile sukuria exe file .txt file generavimui
* clean isvalo .exe ir .o failus
# 1.0 versijos analize
# strategija 1 100000 studentu 10 pazymiu
* List 3.90302 s
* vector 4.04883 s
* deque 4.00563 s
# strategija 1 100 studentu 10 pazymiu
* list 0.0488002 s
* vector 0.0322001 s
* deque 0.0312001 s
# strategija 1 1000 studentu 10 pazymiu
* list 0.0468001 s
* vector 0.0624001 s
* deque 0.0976004 s
# strategija 1 10000 studentu 10 pazymiu
* list 0.432201 s
* vector 0.448207 s
* deque 0.376004 s
# strategija 2 100000 studentu 10 pazymiu
* list 3.75001 s
* vector nesulaukiau, bet virs 5min.
* deque nesulaukiau, bet virs 3min.
# strategija 2 10000  studentu 10 pazymiu
* list 0.589413 s
* vector 11.973 s
* deque 5.93621 s
# strategija 2 1000   studentu 10 pazymiu
* list 0.0624002 s
* vector 0.1716 s
* deque 0.1248 s
# strategija 2 100    studentu 10 pazymiu
* list 0.0156 s
* vector 0.0312001 s
* deque 0.0156 s