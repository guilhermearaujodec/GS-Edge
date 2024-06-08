<p align='center' >
  <img width="250px" loading="lazy" src = "https://github.com/guilhermearaujodec/GS-Edge/assets/163536185/c3b7d051-3f01-4c6e-98e8-23770af4299b"/>
</p>
<h1 align="Center">Oceano Quiz: Desvendando os Mistérios Marinhos</h1>

# Índice
* [Descrição do Projeto](#descricao)
* [O problema](#Problema)
* [Solução proposta](#solucao)
* [Componentes utilizados](#componentes)
* [Funcionamento](#funcionamento)
* [Como usar](#como-usar)
* [Vídeo](#video)
* [Código](#codigo)
* [Acesso ao simulador](#simulador)
* [Autores](#autores)


<h2 id="Descricao">Descrição do projeto</h2>
<p>Este projeto foi desenvolvido como parte do Desafio de "Inovação Azul" 2024, que visa incentivar a criação de soluções para promover uma gestão sustentável dos oceanos. Nosso quiz desafia os jogadores a testarem seus conhecimentos sobre a vida marinha e a conservação do meio ambiente. Com perguntas envolventes, eles podem aprender sobre a importância de proteger os oceanos. Cada resposta certa os aproxima de entender como podem ajudar a preservar nossos preciosos ecossistemas marinhos.</p>

<h2 id="Problema">Problema</h2>
<p>Sentimos uma preocupação crescente com a alarmante falta de conhecimento sobre a saúde dos oceanos, especialmente entre as crianças. Muitos jovens não estão cientes dos graves desafios enfrentados pelos ecossistemas marinhos, como a poluição, a pesca predatória e as mudanças climáticas. Essa falta de compreensão impede a tomada de medidas eficazes para proteger nossos oceanos, perpetuando a degradação ambiental. Sentimos que é essencial despertar o interesse das novas gerações por esses temas cruciais, motivando-as a se tornarem defensoras ativas da preservação ambiental desde cedo.</p>

<h2 id="Solucao">Solução Proposta</h2>
<p>Para abordar essa preocupante falta de conhecimento, desenvolvemos um quiz educativo especialmente voltado para crianças. Nosso quiz apresenta perguntas simples e envolventes que despertam o interesse pelo mundo marinho e os desafios que ele enfrenta. Ao estimular a curiosidade e fornecer informações de forma acessível e divertida, estamos criando um ponto de partida para que as crianças compreendam a importância da preservação dos oceanos. Nosso objetivo é motivá-las a se tornarem defensoras ativas do meio ambiente, inspirando ações positivas desde cedo e promovendo uma conscientização duradoura sobre a necessidade de proteger nossos preciosos ecossistemas marinhos.</p>

<h2 id="Componentes">Componentes Utilizados📖</h2>
  <ul>
        <li>1 - Arduino Uno R3</li>
        <li>1 - LCD 16 x 2</li>
        <li>1 - 250 kΩ Potenciômetro</li>
        <li>2 - 330 Ω Resistores</li>
        <li>2 - kΩ Resistor</li>
        <li>5 - Botões</li>
        <li>1 - 3.3 kΩ Resistor</li>
        <li>1 - 620 Ω Resistor</li>
        <li>2 - 1 kΩ Resistores</li>
        <li>1 - Tensão Multímetro</li>
        <li>1 - LED Vermelho</li>
        <li>1 - LED Verde</li>
        <li>2 - 200 Ω Resistores</li>
        <li>1 - Piezo</li>
  </ul>

<h2 id="funcionamento">Funcionamento🔨</h2>

<ol>
    <li>
        <h3>Boas-vindas e Explicação:</h3>
        <ul>
            <li>O sistema inicia dando boas-vindas ao jogador.</li>
            <li>Explica as funções de cada botão:
                <ul>
                    <li>O botão de cima seleciona a opção "A".</li>
                    <li>O botão de baixo seleciona a opção "B".</li>
                    <li>O botão da esquerda repete a pergunta.</li>
                    <li>O botão da ponta esquerda é o botão de seleção (confirma as respostas).</li>
                    <li>O botão SELECT permite pular a pergunta.</li>
                </ul>
            </li>
        </ul>
    </li>
    <li>
        <h3>Feedback de Tecla Errada:</h3>
        <ul>
            <li>Se o jogador pressionar o botão na hora errada, o sistema exibe "Tecla Errada" no LCD.</li>
        </ul>
    </li>
    <li>
        <h3>Verificação de Respostas:</h3>
        <ul>
            <li>O Arduino verifica as respostas conforme o jogador as seleciona.</li>
            <li>Exibe o número de acertos no final do quiz.</li>
        </ul>
    </li>
</ol>

<p align = "center">
<img loading="lazy" width="500px" src = 'https://github.com/guilhermearaujodec/GS-Edge/assets/163536185/f53062cb-f22b-4958-b4d8-2fbb0b1c8be6'/>
</p>
<p align = "center">
Figura 1 - Imagem do prototipo
</p>

<h2 id="como usar">Como Usar📑</h2>

  `Primeiro`: Monte os componentes de acordo com o esquema de conexões fornecido.
  
  `Segundo`: Carregue o código Arduino no Arduino Uno.
  
  `Terceiro`: Conecte a alimentação e os sensores de acordo com as instruções.
  
  `Quarto`: O Quiz será inicializado.
  
  `Quinto`: Pressione SELECT para iniciar a partida.
  
  `Sexto`: Selecione a alternativa com o botão de cima (A) ou de baixo (B), ou pule a alternativa com o botão da esquerda.

  `Sétimo`: Responda todas as perguntas.

  `Oitavo`: Caso queira jogar novamente, pressione SELECT novamente.

<h2 id="video">Vídeo</h2>
https://www.youtube.com/watch?v=TGQaqu9PGBc

<h2 id="codigo">Codigo</h2>
https://github.com/guilhermearaujodec/GS-Edge/blob/main/codigo-QuizOceano.ino

<h2 id="Simulador">Acesso ao simulador</h2>
https://www.tinkercad.com/things/h7ZUgX5pQC8-quiz-oceano-gs-edge?sharecode=VMAIGw_flmgFNQZdFJFIOMy4vdX6PnUjLm06fUQ9BG0

<h2 id="Autores">Autores</h2>

<div align="center">
  
|  [<img loading="lazy" src="https://github.com/gvqsilva/CP2-Web/assets/110639916/1eb7df1a-c0e8-4170-aabf-444cfb3c64f9" width=115><br><sub>Guilherme Araujo</sub>](https://github.com/guilhermearaujodec)  |  [<img loading="lazy" src="https://github.com/gvqsilva/CP2-Edge/assets/110639916/86514492-2b1e-4422-bdc0-0ec3c8be3dcc" width=115><br><sub>Augusto Douglas</sub>](https://github.com/gutomend)  |
| :---: | :---: |

</div>
