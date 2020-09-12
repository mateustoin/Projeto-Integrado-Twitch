# Projeto-Integrado-Twitch
Repositório com códigos e documentação de um projeto que envolve hardware e software desenvolvido nas lives da Twitch do canal do Bittoin.


# Ideias para estrutura do projeto

## Hardware

<figure class="image">
  <img src="https://github.com/mateustoin/Projeto-Integrado-Twitch/blob/master/img/fluxograma-projeto-hardware.png?raw=True">
  <figcaption>Esquema de funcionamento do projeto no hardware</figcaption>
</figure>
</br>

- Projeto vai ficar conectado 24/7
- Hardware vai coletar dados e enviar para a nuvem

- Tipo de coleta
  - Quantas vezes abriu a geladeira
  - Luminosidade do meu quarto com o passar do tempo

- Tipos de sensores
  - Sensor de distância IR
  - Sensor de Presença
  - Sensor de Luminosidade BH1750

- Tipos de placas
  - ESP8266
  - ESP32 (provavelmente será essa mesmo)

## Software

- API REST para receber dados e enviar para banco de dados na nuvem
- API REST exibe os dados quando solicitados

- Configuração de banco de dados na nuvem
  - Cloud Firestore (https://firebase.google.com/docs/firestore)

- Página Web exibindo os dados

- Previsão dos dados com IA?

## Conexão

- Hardware: (ESP32)[https://www.espressif.com/en/products/socs/esp32]
- API REST: (FastAPI)[https://fastapi.tiangolo.com/]
- Banco de dados Online: (Cloud Firestore)[https://firebase.google.com/docs/firestore]
- Web: Desconhecido (HTML + JS + CSSS ou React -- AntD ou MaterialUI --)