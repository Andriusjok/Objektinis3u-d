# Objektinis Programavimas


## Antra užduotis

### [v0.5](https://github.com/Andriusjok/ObjekProg/releases/tag/Ver0.5) - (2019-03-10) 
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
* Vector 34.7257 s
* List 21.8868 s
* Deque 20.3454 s
