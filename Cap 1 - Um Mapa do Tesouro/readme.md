# 🚜 FarmTech Solutions - Sistema de Irrigação Inteligente (Fase 2)

Este repositório contém o projeto de automação agrícola desenvolvido para a Startup **FarmTech Solutions**. O objetivo é otimizar o uso de recursos hídricos através do monitoramento em tempo real de sensores e atuadores acoplados a um ESP32.

## 📋 Descrição do Projeto

O sistema monitora a umidade do solo, o pH da terra e a presença de nutrientes essenciais (NPK). Com base nesses dados, o dispositivo decide automaticamente se deve ativar a bomba de irrigação (Relé), garantindo a saúde da cultura escolhida (**Soja**) e a economia de água.

## 🛠️ Hardware Utilizado (Simulação Wokwi)

Para a simulação no ambiente [Wokwi](https://wokwi.com/), foram utilizados os seguintes componentes:

- **ESP32:** Microcontrolador principal.
- **DHT22:** Sensor de umidade (simulando a umidade do solo).
- **LDR (Resistor Dependente de Luz):** Utilizado para simular a variação de **pH** do solo (Escala de 0 a 14).
- **Botões de Pressão (Push Buttons):** Três botões simulando os sensores de nutrientes **Nitrogênio (N)**, **Fósforo (P)** e **Potássio (K)**.
- **Módulo Relé:** Representando o acionamento de uma bomba d'água real.

## ⚙️ Lógica de Funcionamento

A inteligência do sistema segue os critérios abaixo:

1. **Irrigação Automática:** A bomba é ligada sempre que a umidade do solo for **inferior a 40%**.
2. **Previsão do Tempo (Integração Serial):** O sistema recebe comandos via Monitor Serial (simulando uma API meteorológica em Python).
   - Se receber o caractere **'C'** (Chuva), a irrigação é suspensa preventivamente.
   - Se receber **'S'** (Seco), o sistema opera normalmente baseado nos sensores.
3. **Monitoramento NPK:** O sistema lê o status dos nutrientes e exibe no console se os níveis estão adequados para a cultura da soja.
4. **Monitoramento de pH:** O sensor LDR mapeia valores analógicos para a escala de pH, permitindo identificar solos ácidos ou alcalinos.

## 📁 Arquivos do Repositório

- `projeto_esp32.ino`: Código-fonte em C++/C para o ESP32.
- `diagram.json`: Arquivo de configuração das conexões do Wokwi.
- `circuito.png`: Imagem do esquema de montagem dos componentes.

## 🎥 Demonstração

Confira o funcionamento completo do projeto no vídeo abaixo:
[Link do seu vídeo no YouTube aqui - Lembre-se de colocar como Não Listado]

## 🚀 Como Rodar o Projeto

1. Acesse o [Wokwi.com](https://wokwi.com).
2. Crie um novo projeto ESP32.
3. Copie o conteúdo de `projeto_esp32.ino` para a aba de código.
4. Substitua o conteúdo da aba `diagram.json` pelo código JSON deste repositório.
5. Inicie a simulação.
