# Breve descrição do problema de saúde abordado
  O desafio enfrentado nas filas é um dilema antigo; quem nunca achou que passaria por  um atendimento ágil e, no entanto, viu-se consumido por horas em uma agência bancária ou em um órgão público, lidando com uma variedade de questões tributárias e burocráticas?
  
  A recorrência desses eventos é tão comum que notícias semelhantes tornaram-se quase corriqueiras, como o caso de uma mulher de 62 anos que foi indenizada em R$8 mil após passar mais de cinco horas na fila do banco.
  
  Contudo, é notório que a compensação financeira, como observada nesse exemplo, nem sempre reflete de maneira justa o impacto causado pela espera. Em situações críticas, como filas em pronto-socorros, a demora no atendimento ou falhas na triagem não apenas comprometem o tempo do indivíduo, mas, em casos extremos, podem resultar na perda de vidas.
  
  Assim, o problema transcende a mera inconveniência e assume proporções mais graves, destacando a necessidade não apenas de ressarcimentos monetários, mas de medidas efetivas para otimizar os processos de atendimento com aplicação da tecnologia, especialmente em ambientes cruciais como os serviços de saúde.




# Visão geral da solução proposta
- Através da precisão e automação no gerenciamento das filas busca-se atingir uma redução do tempo de aguardo nas salas de espera simultânea a uma otimização da alocação dos funcionários. Desse modo, reduzindo, simultanemente, o tempo de fila, o estresse da espera em filas, a probabilidade de agravamentos e desistências e os gastos com funcionários.



# Instruções claras sobre como configurar e executar a aplicação
- Deve ser instalado um sensor ultrassônico em cima de cada cadeira (a uma distância máxima de 3 metros)
- A distância mínima(de onde está o sensor até a cadeira) padrão é de 250 cm(2 m) e deve ser aterada, caso necessário, na linha 5 do código fonte antes da execução do programa
- O tempo para mudança de estado(ocupado/livre) padrão é de 5 segundos e deve ser aterado, caso necessário, na linha 7 do código fonte antes da execução do programa
- Após estabelecidas as medidas, se um assento desocupado permanecer por 5 segundos(tempo padrão) ocupado ele alterará seu estado, o mesmo aplica-se ao contrário, evitando, assim, falsas trocas de ocupado para desocupado
- A cada segundo serão atualizados os dados, emitindo em tempo real o nínel de ocupação



# Link para a simulação do projeto no Tinkercad
- [Tinkercad](https://www.tinkercad.com/things/j8fB9hAidMW-copy-of-prototipo-fila-zero?sharecode=tAsmiBubC6UIdh47A9eoEdCNaOpWQvlZMAgWjoF1_18)
