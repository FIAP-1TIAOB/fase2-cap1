# Análise Exploratória de Dados do Agronegócio 🚜📊

Este projeto foi desenvolvido como parte dos requisitos acadêmicos da disciplina de Ciência de Dados, focado na aplicação prática de estatística e linguagem R utilizando dados reais do agronegócio brasileiro.

## 📋 Descrição do Projeto
O objetivo deste trabalho é realizar uma análise estatística exploratória sobre a variação de preços e tendências de mercado de duas das principais commodities do Brasil: **Milho** e **Soja**. 

Foi construída uma base de dados estruturada com 30 observações, contemplando variáveis quantitativas (discretas e contínuas) e qualitativas (nominais e ordinais). A partir dessa base, o script em R executa cálculos de tendência central, dispersão, separatrizes e gera visualizações gráficas interativas.

## 🔗 Fonte de Dados
Os dados públicos utilizados nesta análise foram coletados oficialmente no portal da **CONAB (Companhia Nacional de Abastecimento)**.
* **Fonte:** [Portal de Informações CONAB - Produtos 360](https://portaldeinformacoes.conab.gov.br/produtos-360.html)

## 📁 Estrutura dos Arquivos
O projeto é composto pelos seguintes entregáveis:
* `Fase2-decolando_ciencia_dados.xlsx`: Base de dados contendo as 30 observações divididas em abas de Milho e Soja.
* `Cap7_Trabalho.R`: Script principal em linguagem R contendo a interface interativa e as análises estatísticas.
* `README.md`: Este arquivo de documentação.

## 💻 Tecnologias e Bibliotecas Utilizadas
* **Linguagem:** R
* **IDE:** Visual Studio Code / RStudio
* **Pacotes R:** `readxl` (para importação da base de dados)

## 🚀 Como Executar
1. Certifique-se de ter o **R** instalado em sua máquina.
2. Instale o pacote necessário executando no console do R: `install.packages("readxl")`.
3. Garanta que o arquivo Excel (`.xlsx`) e o script R (`.R`) estejam no mesmo diretório.
4. Execute o arquivo `Cap7_Trabalho.R`.
5. Uma janela gráfica pop-up será aberta, e o terminal exibirá um **Menu Interativo** permitindo alternar dinamicamente entre as análises de Milho, Soja e o cenário Total.

## 📈 Análises Realizadas
* **Medidas de Tendência Central:** Média e Mediana.
* **Medidas de Dispersão:** Desvio Padrão, Variância e Amplitude.
* **Medidas Separatrizes:** Quartis.
* **Análise Gráfica Quantitativa:** Histograma detalhando a distribuição da variação percentual de preços.
* **Análise Gráfica Qualitativa:** Gráfico de Barras mapeando a frequência da tendência de mercado (Alta, Baixa, Estável).