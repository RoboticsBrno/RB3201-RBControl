# Vlastnosti desky RB3201-RBControl

## Určení a cíl

RB3201 - RBControl (RBC) je univerzální deska pro stavbu hobby robotů. Jde v podstatě o shield k desce 
 [ESP32 dev kit](https://www.espressif.com/en/products/hardware/esp32-devkitc/overview), který má dva hlavní cíle: rozšířit počet pinů desky ESP32 a umožnit snadné připojení velkého množství různých periférií. 

## Hlavní vlastnosti 

Deska RBC umožňuje současně ovládat až 8 DC motorů (1,5 	  A trvale, 2A špičkově každý). Dále umí po osazení spínanými zdroji napájet a ovládat 4 serva nebo 8 mikroserv. Má vyvedenou I2C sběrnici celkem 6x na 3,3 	  V a 2x na 5 	  V. Dále je na desce expandér pinů, který je připojený na I2C a obsluhuje další dva porty A,B po 8 pinech. Na desce jsou vyvedená tři tlačítka, 4 LED a piezo. 

## Další vlastnosti 

Po osazení tranzistorem Q3 je deska chráněná proti přepólování. Přímo na desce je možné měřit reálné hodnoty napětí 3,3 	  V a
5 	  V rozvedených po desce. 

Čip ESP32 má 26 použitelných pinů, z toho 4 pouze vstupní. Přitom na dvou pinech je připojena sériová linka (používá se pro programování čipu přes USB), na dvou pinech je I2C, 3 piny jsou použity pro komunikaci s drivery pro motory, 1 pin měří napětí na baterii. Pro uživatele tedy zbývá 14 pinů. 

K RBC s ESP32 je možné připojit další RBC bez ESP32 a rozšířit tak počet periférií a počet ovládaných motorů. U motorů na připojené ovládané RBC desce nelze použít enkodéry. Také je možné připojit k I2C místo 5 	  V libovolné externí napětí do cca 30 	  V  a provozovat I2C na tomto napětí. 

## Napájení

Napájení desky RBC je ideální ze dvou Li-On baterií, které dodávají asi 8 	  V a dostatečné proudy. K desce lze připojit napětí až do 10 	  V, připojení vyššího napětí neumožňují použité drivery pro motory. Do motorů je přiváděn signál PWM na napětí z baterie a 5 	  V napájení pro enkodéry.  

RBC si hlídá napětí na baterii a umí ho měřit do 10 	  V. 
V ESP32 je softwarově (v knihovně) nastavené napětí napájení 7,2 	  V, při kterém ESP32 vypne desku, aby nedošlo k podvybití baterie.  

Napětí 5 	  V pro desku může tvořit buď stabilizátor 7805 nebo spínaný zdroj.  
Z těchto 5 	  V se tvoří 3,3V na dalším stabilizátoru na desce ESP32 dev kit. Proto při napájení pouze z USB nebude fungovat rozvod 5 	  V na desce. 
Čip 7805 dává asi 1 	  A, většinu spotřebuje deska sama. Spínaný zdroj může dodávat 2 	  A. Celkem je možné na desku osadit 5 spínaných zdrojů.   


## Expandér

Expandér pinů pro ESP32 je k ESP32 připojen přes I2C. Funguje na 3,3 	  V, má dva porty A, B - každý má 8 pinů, port A je pro uživatele, port B je pro tlačítka, LED a vypínání desky, ale uživatel může port B také použít.


# Rozložení pinů na desce RBC a jejich vlastnosti

Pro snazší orientaci si otočte desku tak, aby oblouk na desce byl vpravo. 
Při popisu budeme postupovat zleva doprava a shora dolů. Poloha jednotlivých částí desky je vyznačena v souboru [RBC_image_description.png](https://github.com/RoboticsBrno/RB3201-RBControl/blob/master/docs/RBC_image_description.png).

1. Svorkovnice pro připojení DC motorů 

2. Piny pro připojení motorů s enkodéry. Protože ESP32 má málo pinů, je potřeba si zjistit, které piny jsou použité pro enkodéry a nepoužívat je na něco jiného. 

3. Výstupní piny, slouží signálovému propojení s další deskou RBC. 

4. Výstupní napájení. Použije se v případě připojení další RBC desky jako vstupní napájení pro připojenou desku. 
 Piny SCL, SDA, GND, 3V3 lze použít i samostatně jako další I2C port.
 
5. Drivery pro DC motory. Každý driver poskytuje PWM napájení pro dva motory. Každý driver má vyvedený pin 5A (FAULT), 
kde je možné měřit, jestli se nenachází v chybovém stavu. Každý driver má ochranu proti přetížení i přehřátí -> vypne se. 
Pod drivery jsou posuvné registry 5B, které generují signál pro motory podle pokynů z ESP32.

6. Vstupní piny, slouží signálovému propojení s řídící deskou RBC. 
  Piny SCL, SDA, GND, 3V3 lze použít i samostatně jako další I2C port.

7. Vstupní napájení z baterie nebo z řídící RBC desky. 

8. Jde o čtveřici jumperů, zleva doprava při propojení provedou následující: Reset RBC, zapnutí RBC, vypnutí RBC, vypnutí RBC v případě, že expandér není osazen nebo nefunguje.  

9. Stabilizátor 7805 (dodává cca 1 	  A, většinu z tohoto proudu spotřebuje RBC pro svůj provoz). Místo 7805 je možné osadit spínaný zdroj, který dodává cca 2 	  A.

10. Port B z expandéru. Zleva doprava jsou to piny: 5 	  V, GND, 2x signálový pin (ten stejný) na 3,3 	  V.
Na tomto portu jsou také připojená tlačítka, všechny LED a **vypínání desky (pin B7)**. Pozor, ve verzi 1.2 jsou popisy pinů posunuté o jeden pin dolů.

11. Tranzistor Q1 - zapíná desku. 

12.  Tranzistor Q3. Po osazení tranzistorem Q3 je deska chráněná proti přepólování.

13. Expandér pinů. 13A jsou piny pro sledování přerušení na portu A a portu B expandéru. 

14. Tlačítka S1, S2, S3. 

15. ESP32 dev kit 

16. Deska, která převádí signál I2C z 3,3 	  V na 5 	  V a signál pro připojení inteligentních LED a podobně - viz č. 17 a 23.

17. 2x I2C na 5 	  V

18. 3x I2C na 3,3 	  V

19. 4x LED 

20. Piny pro připojení periferií k ESP32. Součástí jsou piny portu A z expandéru (č. 20A). 
Zleva doprava: 3,3 	  V, GND, 2x signálový pin, 5 	  V, GND. Přitom piny 5 	  V jsou ve výchozím nastavení připojeny na spínané zdroje (č.21A-D, které samozřejmě musí být osazeny). Vyjímka je spodních 8 pinů, které jsou připojeny přímo ke stabilizátoru nebo spínanému zdroji (č. 9). Pokud chceme ostatní piny připojit na zdroj č. 9, musíme propojit jumpery 22A-D. 
Přitom piny tvoří kaskádu, tj. musím nedřív propojit jumper 22A, potom 22B atd. 

21. Místo pro osazení spínaných zdrojů (step-down): 21A, 21B, 21C, 1D. Každý zdroj má vyvedený tzv. enable-pin. 
Zdroje jsou ve výchozím stavu zapnuté a lze je  vypnout tak, že na enable-pin přivedu kabelem z jiného pinu potřebný signál. 

Na každý spínaný zdroj (step-down) je možné připojit jedno servo nebo dvě mikroserva. Piny jsou vyvedeny tak, aby bylo možné serva připojit přímo. Přitom zdroj 21D obsluhuje horní dva piny 5 	  V, zdroj 21C dva piny 5 	  V pod nimi, zdroj 21B opět dva piny 5 	  V pod nimi a zdroj 21A všechny zbývající piny 5 	  V kromě spodních osmi.


22. Jumpry pro připojení spínaných zdrojů z bodu 21, písmeno vždy odpovídá: 22A, 22B, 22C, 22D.

23. Signál pro inteligentní LED nebo podobné zařízení - piny na desce nejvíce vpravo (nejsou vyznačeny).

 
