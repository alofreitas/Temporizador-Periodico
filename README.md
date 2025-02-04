# Semáforo com Raspberry Pi Pico W

## Descrição
Este programa implementa um semáforo utilizando a placa Raspberry Pi Pico. O sistema alterna entre os estados do semáforo (vermelho, amarelo e verde) a cada 3 segundos, acionando os LEDs correspondentes.

## Requisitos
- Placa **Raspberry Pi Pico**
- LEDs de cores **vermelha, amarela e verde**
- **Resistores** apropriados (330Ω recomendados)
- **Cabos jumper** e protoboard
- **Ambiente de desenvolvimento para Raspberry Pi Pico**, como:
  - **SDK do Raspberry Pi Pico** instalado
  - **Compilador GCC ARM**
  - **CMake**
  - **Ferramenta de upload (picotool ou UF2 Bootloader)**

## Esquema de Ligação
Os LEDs devem ser conectados aos seguintes pinos da Raspberry Pi Pico:

| LED         | Pino GPIO|
|------------|----------|
| Vermelho   | 11       |
| Amarelo    | 12       |
| Verde      | 13       |

Cada LED deve estar conectado em série com um resistor de **330Ω** para limitar a corrente.

## Compilação e Upload
1. Clone ou baixe este repositório para sua máquina:
   ```sh
   git clone https://github.com/alofreitas/Temporizador-Periodico.git 

   cd Temporizador-Periodico
   ```
2. Compile o código usando **CMake**:
   ```sh
   mkdir build
   cd build
   cmake ..
   make
   ```
3. Conecte a Raspberry Pi Pico ao computador no **modo bootloader** (pressionando o botão **BOOTSEL** ao conectar o cabo USB).
4. Copie o arquivo `.uf2` gerado para a unidade montada pelo Pico.

## Execução
Após o upload, o código será executado automaticamente. O semáforo seguirá a seguinte lógica:
- **LED vermelho** acende por 3 segundos
- **LED amarelo** acende por 3 segundos
- **LED verde** acende por 3 segundos

Além disso, a cada segundo, a mensagem `1 segundo!` será impressa no monitor serial.

## Monitoramento Serial
Para visualizar as mensagens enviadas pelo programa, utilize um monitor serial como **Minicom, PuTTY ou screen**:
```sh
screen /dev/ttyUSB0 115200
```
Substitua `/dev/ttyUSB0` pelo dispositivo correspondente ao seu Raspberry Pi Pico.

## Autor
Ana Luiza Oliveira de Freitas


