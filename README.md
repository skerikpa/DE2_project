### Členové týmu

* Patrik Škeřík (responsible for ...)
* Mykyta Syskov (responsible for ...)
* Jakub Jureček (responsible for ...)
* Jakub Raimr (responsible for ...)

## Teoretický popis s vysvětlením
(Theoretical description and explanation)

Zadáním tohoto projektu bylo zprovnoznit xylofon s devití vstupy včetně GND, aby byl schopen hrát melodie písní, které mohou být naprogramovány uživatelem. Uživatel je schopen vytvořit pole s názvy not nebo pinů (např. Cn nebo PD2), na které jsou připojeny vstupy xylofonu. K vytvoření dojmu, že melodie má rytmus, je použita funkce delay za každou zahranou notou. 

## Popis hardwaru a demonstrační ukázka
(Hardware description of demo application)

V rámci tohoto projektu nám byl přidělen jednooktávový xylofon, který je uzpůsoben pro komunikaci s mikroprocesorem Arduino Uno. Místo paliček určené pro rozeznění kovových plátků jsou plátky rozezněny cívkami s magnetickým jádrem, které jsou spuštěny napětím pomocí kódu. Během spuštění not se rozsvítí u každé klapky LED dioda, která upozorní uživatele, jaká nota byla právě zahrána. Názvy not jsou také napsány na samotných plátcích na xylofonu. Budící napětí cívek je zajištěno zesilovačem, který je zapojen do zásuvky. Xylofon je připojen k mikroprocesoru pomocí pinů PD2 až PB1. Schéma obvodu se nachází zde:

![circuit](https://github.com/skerikpa/DE2_project/assets/124879295/cf64b977-f6de-433a-ad08-f0818a001814)

Na nepájivém poli je umístěn OLED displej, který zobrazuje právě hranou notu na xylofonu. Displej je zapojen na piny VCC, GND, SDA a CLK. 

Arduino Uno je připojeno k PC pomocí USB mikro, po kterém jsou odesílána všechna důlěžitá data do mikroprocesoru. 

## Popis softwaru

Zásádní soubory jsou pro tento projekt xylo.c a xylo.h, ve kterých je definice hraní not a vykreslování not na displej. Melodie písní jsou vytvořeny pomocí kombinací not a funkce delay. Následně jsou tyto informace zpracovány v main.c a zasílány na xylofon.

Použité knihovny jsou gpio.h a oled, což jsou knihovny ze cvičení DE2. Nekteré jsou upravené pro použití v tomto projektu. Všechny tyto soubory jsou vhodně použity v main.c. 

xylo.c a xylo.h - hraní not, vykreslování not na oled displej
oled - sd a vcc

Put flowchats of your algorithm(s) and direct links to source files in `src` or `lib` folders.

## Návod
(Instructions)

Použití tohoto zařízení je velmi jednoduché. Po zadání potřebných informací pro zahrání písničky (názvů not a delay) zkompiluje kód data a odešle je následně do mikroprocesoru, který následně hraje píseň tak, jak byla zadána. Bližší demonstrace je ukázána v přiloženém videu:
Write an instruction manual for your application, including photos and a link to a short app video.

## Reference

1. Write your text here.
2. ...

# DE2_project

