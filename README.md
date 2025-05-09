# Este é meu primeiro repositório em c++.
#### A função do programa seria simular um jogo padrão RPG.
#### O estilo de combate é em turno, o nome "rpg5Hrs" vem do desafio inicial, o qual era: criar um rpg em 5 horas, porém me empolguei um pouco no projeto e decidi continuá-lo sem me importar com o tempo.
#### Minha meta é este ser um código o qual me gere conhecimento e desafio a partir da linguagem c++ para a criação de jogos.

## Relatório de funções e práticas que faltam ser aplicadas:

### Devo criar 2 novos inimigos além de Artorias, seus nomes serão Ornstein/Smough (1 chefe em conjunto) e o outro boss será Sif.
#### -> Sif será um chefe em formato de cachorro que terá 3 ataques principais e uma mecânica de passiva de sangramento.
- Mordida: Ataque de mordida padrão que gera sangramento.
- Raiva: Gerador de buff que aumenta seu dano em 30%.
- Morte: Sif dá uma sequência de até 3 ataques, gerando sangramento em cada um.
#### -> Ornstein e Smough serão chefes em conjunto, cada um terá 2 ataques, onde ornstein prioriza o dano e smough a defesa, respectivamente.
- Corte perfurante: Ataque de dano padrão.
- Lança de raio: Ataque com dano variado, podendoo chegar a ser nulo ou até hit kill.
- Martelada: Ataque de dano padrão.
- Resistência: Habilidade que aumenta a defesa.

### Devo criar uma função para a obtenção de ouro a cada chefe derrotado para ser utilizado na cidade posteriormente.

### Devo criar um sistema de cidade.
- Incluir um ferreiro para melhorar as armas.
- Incluir um vendedor de porções.
- Incluir uma arena para enfrentamento dos chefes designados.

### Devo ajustar o switchCombate, considerando itens de recuperação de mana e cura.
- Incluir a opção de usar itens.
- Incluir a opção de usar porções.
- Incluir a opção de atacar antes mesmo de selecionar um ataque.

Atualizações diárias:
26/04/2025 

Pontos melhorados:
- Configurei a recepção da resposta à escolha da classe do jogador.
  
Pontos a melhorar:
- Criar um loop para a resposta de escolha de classe.
- Configurar a reposta à classe para que a resposta se classifique "como classeRaca" sem que o jogador precise se preocupar com caracteres maiúsculos ou minúsculos. 
                                
27/04/2025 

Pontos melhorados:
- Criei um loop para escolha de classe.
- Criei um loop para escolha e confirmação de nome.
- Configurei alguns loops, utilizando métodos "cin.get()" e "system("cls")"
                                
Pontos a melhorar:
- Configurar o método "cin.get()" de uma forma que ele não gere erros ao console ou confusões no código.

28/04/2025

Pontos melhorados:
- Criei o método "entrada.empty()" para garantir que o jogador não bugue o console na tela de entrada
- Criei loops nos métodos de criação de personagem com o intuito do jogador não bugar o console

Pontos a melhorar:
- Preciso me certificar de que os loops operem de maneira funcional e com o mínimo de erros             

29/04/2025

Pontos melhorados:
- Consegui criar um switch para cada classe e raça utilizando funções enum
- Consegui criar passivas e atribuir elementos únicos às raças

Pontos a melhorar: 
- Criar um switch com cases respectivos a cada classe
- Considerar a possibilidade de adicionar passivas às classes (provavelmente não)

30/04/2025

Pontos melhorados:
- Consegui criar um switch para a parte de classes
- Criei algumas novas funcionalidades, como ouro e funções de combate
- Iniciei a modularização do código

Pontos a melhorar:
- Concluir a modularização do código
- Aprender a trabalhar encima de variáveis randomicas
- Organizar melhor minhas ideias

02/05/2025

Pontos melhorados:
- Modularização completa da criação de personagens

Pontos a melhorar: 
- Atribuição e impressão dos atributos dos personagens
- Realizar uma estratégia para atribuição de variáveis de combate

03/05/2025

Pontos melhorados:
- Começei a criar uma função para utilizar no combate

Pontos a melhorar:
- Concluir a função de combate

04/05/2025

Pontos melhorados:
- Finalizei a primeira parte da função de combate
- Criei uma função para impressão de atributos

Pontos a melhorar:
- Concluir a função de combate

06/05/2025

Pontos melhorados:
- Finalizei a criação de funções para o inimigo Artorias
- Conclui a primeira situação de combate para a classe guerreiro

Pontos a melhorar:
- Determinar os atributos de Artorias
- Concluir a função de combate

08/05/2025

Pontos melhorados:
- Criação de função para limpar o console
- Criação de if no combate para a cura da classe vampiro
- Criação de if na classe combate para bloqueio
- Atribuição do comando "endl" para melhorar a interface do executável

Pontos a melhorar:
- Melhorar a configuração geral do switchCombate
- Escrever um relatório geral para uma melhor orientação do projeto
- Concluir a função de combate
