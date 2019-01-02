#  Deska RB3201-RBControl

RB3201 - RBControl (RBC) je univerzální deska pro stavbu hobby robotů. 

Jde v podstatě o shield k desce [ESP32-DevKitC](https://www.espressif.com/en/products/hardware/esp32-devkitc/overview), který má dva hlavní cíle: 

- umožnit snadné připojení velkého množství různých periférií (motory s enkodéry, serva, senzory...)
- rozšířit počet pinů desky ESP32 

## Hlavní vlastnosti

- současně ovládat až 8 DC motorů (1,5 A trvale, 2A špičkově každý) a obsluhovat 8 enkodérů pro tyto motory
- po osazení spínanými zdroji napájet a ovládat 4 serva nebo 8 mikroserv
- vyvedená I2C sběrnici - celkem 6x na 3,3 V a 2x na 5 V
- expandér pinů, který je připojený přes I2C a obsluhuje další dva porty A,B po 8 pinech (celkem dalších 16 pinů) 
- tři tlačítka, 4 LED a piezo
- připravena ochrana proti přepólování a podvybití 

## Rozšiřujicí moduly

### MotorEncoder 

- DPS jako enkodér na [upravené levné čínské motory s magnetem](https://mickoflus.cz/guide.html#motor-magnet)
