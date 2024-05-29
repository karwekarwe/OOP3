# README

## Paleisties proceso instrukcija:

1. Visų pirma, iš https://github.com/karwekarwe/OOP2 reikia klonuoti repozitoriją savo darbo aplinkoje naudojant 'git clone'.
2. Atsidarius naują terminalą, nueikite į klonuotos repozitorijos aplnką.
3. Kompiliuokite programą naudojant "Makefile" failą, kuris jau bus klonuotoje repozitorijose - terminale įrašykite "make".
4. Pasirinkite su kokia programos versija norite dirbti.

## Programos veikimas:

1.  Paleidus programą, vartotojui pateikiami pasirinkimai:
+ Duomenų įvestis ranka ar nuskaitymas iš failo. Toliau seka šie pasirinkimai:
     Ranka: 
     - Pilna įvestis ranka / pažymių generavimas / pažymių ir vardų generavimas / baigti darbą.
     - Skaičiavimo metodas: vidurkis / mediana
+ Iš failo:
     - Generuoti naują ar naudoti esamą failą
     - Kokio dydžio failą generuoti / naudoti? (1. 1000 2. 10000 3. 100000 4. 1000000 5. 10000000.)
     - Skaičiavimo metodas: vidurkis / mediana
     - Rikiavimo metodas: vardas / pavardė / galutinis
     - Išvestis į failą ar ekraną.

# Programos versijos:
## v0.1
+ Studento galutinio balo skaičiavimas pagal vidurkį arba medianą
+ std::vector / C masyvai
+ struct Stud
## v0.2
+ Duomenys nuskaitomi iš failo
## v0.3
+ header (*.h) failai
+ Išimčių valdymas
## v0.4
+ Studentų sarašų failų generavimas
+ Studentų rūšiavimas į dvi grupes pagal galutinį balą
+ Programos veikimo greičio (spartos) analizė
## v1.0
+ Trys programos versijos: std::vector,  std::list,  std::deque
+ Optimizuotas studentų rūšiavimas (dalijimas) į dvi kategorijas
## v1.1
+ Class Stud versija
+ Struct ir Class versijų palyginimas
## v1.2
+ Pritaikyta Rule of five
## v1.5
+ Sukurta bazinė klasė Zmogus, iš kurios išvesta klasė Stud
## v2.0
+ Realizuoti ir demonstruojami unit test testai (Catch - [https://github.com/catchorg/Catch2/releases/tag/v3.6.0?fbclid=IwZXh0bgNhZW0CMTEAAR22tR50_uOfmSpIaDAg-vh1J6x_Vx8HP37CkzBrw8thoaoX5rqA3GqSxuI_aem_AQ2dqup3Bzkw-VMJZk7ygzB1di_IcHDSQ3fv-AiWsivb2Z2UqpWUYVYC1sEDRIGEkJk_zpuSw3frjTqTHAp6pkB1](https://github.com/catchorg/Catch2/releases/tag/v3.6.0))
+ Klasę aprašanti dokumentacija HTML/TEX formatais - https://www.doxygen.nl/manual/index.html
## v3.0
+ sukurta ir pritaikyta (atskira nuo std::vector) Vector klasė
+ Paruošti Vector cach testai
+ Sugeneruota dokumentacija
+ pateiktas Setup.exe failas programos diegimui


# v3.0

## std::vector vs Vector

Tuščių vektorių pildymas (milisekundėmis):


|             | 1000 | 10000 | 100000 | 1000000 | 10000000 |
|-------------|------|-------|--------|---------|----------|
| std::vector | 0.27 | 3     | 28     | 289     | 2848     |
| Vector      | 0.08 | 1     | 9      | 118     | 1106     |

Atminties perskirstymai užpildant 100 000 000 elementų:

std::vector:
```
std::vector atmintis buvo perskirstyta 27 kartų
```

Vector:
```
Vector atmintis buvo perskirstyta 27 kartų
```

Duomenų apdorojimas (milisekundėmis):

| Vector                                   | 100000 | 1000000 | 10000000 |
|------------------------------------------|--------|---------|----------|
| Skaitymas iš failo:                      | 169    | 1965    | 23842    |
| Skirstymas  į dvi grupes:                | 34     | 319     | 13412    |
| Rūšiavimas didėjimo tvarka konteineryje: | 107    | 1410    | 22931    |
| Viso:                                    | 310    | 3694    | 60185    |

| std::vector                              | 100000 | 1000000 | 10000000 |
|------------------------------------------|--------|---------|----------|
| Skaitymas iš failo:                      | 189    | 1737    | 17837    |
| Skirstymas  į dvi grupes:                | 30     | 272     | 4932     |
| Rūšiavimas didėjimo tvarka konteineryje: | 182    | 2393    | 36037    |
| Viso:                                    | 401    | 4402    | 58806    |


