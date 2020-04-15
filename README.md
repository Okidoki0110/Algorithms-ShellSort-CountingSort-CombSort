# Introducere

Aceasta lucrare este dedicata studiului asupra timpilor si memoriei folosite de
diferiti algoritmi de sortare, cat si a imbunatatirii acestora prin propunerea unor
metode mai eficiente. Sortarea este des folosita in lucrul cu arrays,linkedlist,Heap
etc. Un exemplu de folosire al sortarii il reprezinta motoarele de cautare web,
care folosesc astfel de algoritmi (Google, Yahoo, MSN). Astfel, putem intalni in
practica abordari distincte, precum algoritmi de sortare prin comparare Shell-
Sort,Comb Sort sau care exploateaza diferite proprietati ale datelor de intrare,
CountingSort.
Performanta algoritmilor este data de timpul de rulare, cat si de memoria uti-
lizata. In mod normal se folosesc doua metode de analiza si anume cea analitica
si cea empirica.

#  Shell Sort
Descoperit de catre Donald Shell in anul 1959, Shell Sort este o imbunatatire a algoritmului Insertion Sort, prin scaderea numarului de comparatii facute si prin urmare a timpului. Notiunea de gap este asociata cu "salt". Se alege o valoare cat mai mare pentru gap, deobicei primul are valoarea n/2 , se face interschimabarea elementelor vectorului daca este cazul, apoi se injumatateste valoarea n/4 pana cand gapul este 1 si astfel se ajunge la ideea de implementare a algorimului Insertion Sort. Determinarea complexitatii poate fi extrem de complexa. Algoritmul sorteaza o secventa de numere intregi pentru a defini ordinea comparatiilor elementelor, in consecinta complexitatea este data de modul alegerii secventei.

Secventa originala este
<img src="https://render.githubusercontent.com/render/math?math=[\frac{n}{2}], [\frac{n}{4}], [\frac{n}{8}] ... 1">

dar s-a constatat ca aceasta nu este suficient de buna si prin urmare mai multi
cercetatori au propus diferite secvente :

1. Hibbard -> 1, 3, 7, ... (2^k - 1); numere prime
  -Worst-Case running time este O(n^(3/2))
  -Average-Case running time este teoretic, deoarece nimeni nu a reusit sa demonstreze O(n^(5/4))
 2. Papernov si Statsevich -> (2^k + 1) -> O(n^(4/3))
 3. Pratt -> {5^p * 11^q} si {7^p * 13^q}
 4. Tokuda -> H_o=1, H_(s+1)=2,25H_s + 1
 
 Pentru a intelege mai bine modul de functionare am ales un vector ce contine 14 elemente de tip int. Alegem valoarea gapului initial n/2 = 14/2 = 7 apoi 7/2 = 3
 
Atunci cand gapul ajunge la dimensiunea 1, complexitatea devine O(n)

![](/image/exemplu.png)

Unul dintre cazurile defavorabile este considerat atunci cand cele mai mici
elemente sunt in pozitii ciudate, iar cele mai mari in pozitii egale

2; 11; 4; 12; 6; 13; 8; 14....

Cazul cel mai defavorabil este reprezentat de un vector sortat descrescator, in
acest caz complexitatea este O(n^2). Cazul cel mai favorabil este atunci cand vec-
torul este deja sortat, parcurgem elementele o singura data, iar complexitatea
este O(n)
Timpul de rulare depinde de secventa aleasa O(N^x) , x = 3/2 ; x = 5/4...2

1. Best Case Time Complexity : Theta(n * log2 n)
2. Worst Case Time Complexity : Theta(n^2)
3. Average Case : depinde de secventa aleasa
4. memorie: Theta(1)
5. In place; nu foloseste un vector suplimentar
6. Not stable

Sorting network este un set de comparatori, astfel incat IPul este reprezentat
de o serie de numere, aceleasi numere rearanjate in ordine ascendenta reprez-
inta OUPul.Un comparator este o retea de sortare cu doua intrari si doua iesiri,
care poate fi tratat ca o Black Box. Diferenta de baza dintre o retea de sortare
si algoritmul care doar citeste, sorteaza si aseaza vectorul, este ca in timp ce
stuctura de control a calculatorului este in mod inerent serial, fortand compara-
tiile si schimburile sa se faca una cate una, reteaua este paralela. Acest lucru
imbunatateste considerabil complexitatea Linia verticala indica comparatorul,
iar sageata indica directia. Acest algoritm este unul dintre cel mai rapid din

![](/image/doi.png)
clasa celor de complexitate secventiala O(n2). Viteza este aproximativ de 5 ori
mai mare decat sortarea prin metoda bulelor si de peste doua ori mai mare de-
cat metoda de sortare prin insertie. Este mai lent in comparatie cu metoda de
sortare rapida sau cea Heap. Simplitatea acestuia il face sa fie folosit atunci cand
se doreste sortarea repetata a unor vectori de dimensiune moderata. Nu este o
metoda stabila deoarece performanta depinde de alegerea secventei.

![](/image/running_time.png)

![](/image/complexity.png)

# Counting Sort

Inventat de catre Harold H. Seward in anul 1950, acesta un algoritm simplu, sta-
bil si eficient, cu un timp de functionare liniar. Este utilizat in diferita aplicatii
de Data Processing Systems, datorita eficientei ridicate.
Presupune folosirea unui vector auxiliar, in cadrul caruia vor fi stocate frecventele
elementelor. Vectorul auxiliar contine valori nule, iar numarul acestora este mai
mare decat cea mai semnificativa valoare. Parcugem vectorul si stocam numarul
de aparitii aux[a[i]] + + pentru fiecare i. Initializam un alt vector, sortedAr-
ray. Traversam array-ul auxiliar in care sunt retinute frecventele elementelor si
copiem i in sortedArray pentru aux[i], unde 0 <= i <= max(vector[]).
O(k+n) running time. Vectorul si sortedArray sunt traversate in O(n). Vectorul
auxiliar este traversat in O(k), de aici va rezulta complexitatea nala.
Algoritmul este eficace atunci cand range-ul nu este mai mare decat numarul
elemntelor. Nu are o complexitate bazata pe comparatie. Acesta este avantajos
atunci cand stim range of elements si daca elementele sunt integers.

![](/image/complexity2.png)


1. Time Complexity : O(n + k), k = max - min + 1
2. Space Complexity: )(k), k is the range of input
3. Stable
4. Sortare interna


Problema cu acest algoritm consta in faptul ca pentru numerele sunt intregi
pe 32 de biti, iar asta ar insemna sa imi aloce 16 GB RAM. O solutie pentru
acesta problema este sa impart cei 32 de biti, apeland de 4 ori functia Counting.
As vrea sa mentionez ca am renuntat la definitia generica din cadrul headerului
propus deoarece in cadrul functie de comparare putem avea orice tip. Pentru
datele de tip 
float m-am gandit ca o posibila solutie ar fi sa imultesc fiecare
numar cu error = 108 pentru a le transforma in inturi. Pentru numere negative
solutia ar fi fost sa imultesc valoarea cu -1.

![](/image/10.png)

![](/image/optimizare.png)

![](/image/history.png)

![](/image/11.png)


# Comb Sort

Descoperit de catre Stephen Lacey si Richard Box in 1991, este o imbunatatire
a algoritmului Bubble Sort. Acesta utilizeaza salturi mai mari decat 1, deobicei
consideram primul gap o valoare mare, apoi scade cu 1,3 pana ajunge la 1. Pentru
ultima valoare se aplica Bubble Sort.

![](comb.png)
1. Avantaje
  - Este adecvat pentru seturi de date compuse e din numere, e din siruri
de caractere
  - Complexitatea timpului este foarte buna, poate  comparata cu cea de la
algoritmul Quick Sort
  - Nu are apeluri de functii recursive
  - In-place-sorting

2. Dezavantaje
  - Trebuie sa redimensionate salturile cu o diviziune de 1.3, ceea ce reprezinta
o fractiune.
  - Best Case : O(n)
  - Average Case: O(n * log n)
  - Worst Case : O(n^2)
  - Nu este stabil
  
  
# Evaluarea solutiilor

Algoritmii prezentati anterior au fost analizati din punct de vedere al timpului
de executie, cat si din punct de vedere al numarului de iteratii facute. Am folosit
diferite dimensiuni ale datelor de intrare, astfel ca testele ce ajuta la analiza
contin de la 4 pana la 100000 de elemente.
Testele au fost generate in cadrul programului "Random.c", din directorul IN
care genereaza random n cifre de tip int. Primele 7 teste contin elemente din
ce in ce mai multe. Testul 8 cotine elemente deja sortate, testul 9 este contine
inturi sortate descrescator. In directorul OTHER TEST sunt numere sortate e
ascendent, fie descentent pana la o anumita valoare, apoi se continua cu o con-
stanta.
Pentru verificarea testelor precizate anterior, se folosec : programul Test in cadrul
caruia se primeste inputul si compara fisierul de out de referinta si in urma
caruia afiseaza "Test PASSED" sau "Test FAILED". Fisierele ALGO.CPP core-
spunde implementarii algoritmului Shell Sort, ALGO2.CPP pentru Counting
Sort, ALGO3.CPP pentru Comb Sort. ALGO.H este header-ul ce contine definitiile algoritmilor prezentati. Makefile - ul contine o regula de build care va genera
un fisier obiect algo.o, cu implementarea functiilor din algo.h. Altfel, pasii pentru
testarea algoritmilor sunt :

1. make
2. ./tema (numarul testului) (numarul algoritmului)

Teste si algoritmii au fost creeate folosind Visual Studio Code 1.30.0. Am testat doar date de tip int. Testele contin incepand de la 1 la 9 numarul
de inputuri 10^3, 2 * 10^3, 10^4,2 * 10^4, 10^4, 10^5, 2 * 10^5, 10^6, 10^4 deja ordonat, 10^4
ordonat descrescator. Testul 0 contine 4 int-uri.

![](/image/final.png)
![](/image/final2.png)

# Concluzii
1. Din punct de vedere al numarului de iteratii
{ Testul 1 contine 103 inturi se observa ca algoritmul Counting are cele mai
multe iteratii, acest lucru se datoreaza faptului ca el foloseste acel vector
auxiliar, iteratiile sunt innumarate incepand cu alocarea, adunarea cat si
atunci cand creez vectorul sortat. Este un algoritm stabil, acest lucru pre-
supune ca atunci cand avem doua valori egale in vectorul care urmeaza a 
sortat ele sunt puse pe in ordinea in care se gasesc initial
{ Shell Sortul are un numar mai mic de iteratii decat Comb Sort, deoarece
alegerea gapului si complexitatea este mai buna.
{ Pentru un input din ce in ce mai mare numarul de iteratii nu creste la fel
de repede la Counting fata de celelalte deoarece scaleaza mai bine.
{ Se observa ca din acest punct de vedere cel mai bun algoritm este Shell
Sortul.
2. Din punctul de vedere al timpului de executie
{ Shell Sort are timpul cel mai mare
{ Counting Sort este cel mai bun din acest punct de vedere, din cauza com-
plexitatii

Nu pot spune ca unu algoritm este mai bun decat celalalt, depinde de ceea ce
avem de facut si de ceea ce vrem sa obtinem. Tipul de date ar reprezenta un alt
criteriu de alegere. Daca dorim un timp mai bun alegem Counting Sort, insa nu
il putem alege pentru inturi foarte mari caci va da crash in cazul implementarii
facute.
Shell Sort si Comb Sort, deoarece au la baza doi algoritmi esential in sortare
Insertion Sort si Bubble Sort, a caror complexitate ar putea  considerata la fel
in unele cazuri, se observa ca au o evolutie aproximativ la fel
In urma acestei lucrari, pot spune ca un pas important in alegerea unei sortari
este ceea ce vrem sa obtinem. Vrem un vector sortat intr-un numar de iteratii
mai mic sau vrem un timp mai bun?


# Referinte
1. Hackerearth, https://www.hackerearth.com/practice/algorithms/sorting/counting-
sort/tutorial/
2. Enhanced Shell Sorting Algorithm, https://waset.org/publications/4459/enhanced-
shell-sorting-algorithm-
3. Shell sort improvement, https://apps.dtic.mil/dtic/tr/fulltext/u2/740110.pdf?
4. Comb Sort, https://codereview.stackexchange.com/questions/105490/counting-
sort-in-python
5. Counting Sort, https://stackover
ow.com/questions/45489527/what-is-k-in-
counting-sort-onk-time-complexity
