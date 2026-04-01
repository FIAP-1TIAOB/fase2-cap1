# [Vinicius Seiti Adati]_RM[rm568948]_fase2_cap7

library(readxl)

arquivo <- "Fase2-decolando_ciencia_dados.xlsx"
dados_milho <- read_excel(arquivo, sheet = "Milho")
dados_soja  <- read_excel(arquivo, sheet = "Soja")

limpar_dados <- function(df) {
  df[[2]] <- as.numeric(gsub(",", ".", df[[2]]))
  return(df)
}

dados_milho <- limpar_dados(dados_milho)
dados_soja  <- limpar_dados(dados_soja)
dados_total <- rbind(dados_milho, dados_soja)

windows(width = 10, height = 5)

continuar <- TRUE

while(continuar) {
  cat("\n1-Milho | 2-Soja | 3-Total | 0-Sair \n")
  
  escolha <- as.integer(readline(prompt="Digite sua opção: "))
  
  if(is.na(escolha) || escolha == 0) {
    continuar <- FALSE
    dev.off() # Fecha o gráfico
    cat("Programa encerrado.\n")
  } else if(escolha %in% c(1, 2, 3)) {
    
    if(escolha == 1) { dados_plot <- dados_milho; titulo <- "Milho" }
    else if(escolha == 2) { dados_plot <- dados_soja; titulo <- "Soja" }
    else { dados_plot <- dados_total; titulo <- "Total (30 Linhas)" }
    
    par(mfrow=c(1,2)) 
    
    barplot(table(dados_plot[[4]]), 
            main=paste("Tendência:", titulo),
            col=c("red", "green", "gray"), 
            xlab="Categoria", ylab="Qtd")
    
    hist(dados_plot[[2]], 
         main=paste("Variação:", titulo),
         xlab="%", col="darkgreen", border="white")
    
    # Atualiza gráfico
    dev.flush() 
    
    cat("\n--- ESTATÍSTICAS:", titulo, "---\n")
    print(paste("Média:", round(mean(dados_plot[[2]], na.rm = TRUE), 2)))
    print(paste("Desvio Padrão:", round(sd(dados_plot[[2]], na.rm = TRUE), 2)))
  }
}