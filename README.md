# CADSUS
#### Projeto confeccionado utilizando o software QT Creator, como pré-requisito para a conclusão da disciplina Técnicas de Programação. Período: 2019.2. 
#### CADSUS é um programa que cadastra e gerencia os domicílios atendidos pelo Sistema único de Saúde (SUS), desenvolvido para facilitar o trabalho do Agente Comunitário de Saúde (ACS), por meio de uma interface simplificada em relação ao prontuário utilizado atualmente, onde o cadastro ainda é realizado em um documento físico.

A aplicação possui três telas principais. Na primeira, o usuário tem a possibilidade de cadastrar o CEP e número do domicílio, o tipo do domicílio, a disponibilidade de serviços básicos e a quantidade de membros da família e a renda mensal.

![tela1](https://github.com/sustavos/Projeto_final_1_QT/blob/master/IMAGENS/tela_inicial_1.png)

Na segunda tela, há a tabela de domicílios cadastrados, que permite a visualização e edição de todos os cadastros realizados até o momento.

![tela2]()

Por último, há a tela das estatísticas, onde algumas informações são apresentadas, com o intuito de ajudar na realização de ações com a comunidade.

![tela3]()

## Manual do Usuário
#### Como começar?
Para começar a utilizar o **CADSUS** basta abrir a primeira aba, que abrirá a tela de Cadastros. Nela, o usuário deve informar inicialmente o CEP e o número do domicílio a ser cadastrado. 
Há um botão "Abrir GoogleMAPS", que quando clicado, redirecionará o usuário para o site https://www.google.com.br/maps/, no navegador, onde é possível adquirir esses dois dados. 

![abrir_maps]()

Bastar clicar e segurar por alguns segundos no ponto desejado da rua que é aberto uma janelinha na borda inferior da tela, que se clicado, é expandida, apresentando maiores informações. 

![maps_aberto]()
![maps_aberto_1]()
![maps_depois]()

Preenchido esses campos, preenche-se os campos com os dados solicitados e marca-se as opções condizentes com as condições do domicílio que se deseja cadastrar.

![condicoes_moradia]()

Por último, preenche-se os campos de número de membros da família e a renda mensal.
![familia]()

#### Como visualizar os domicílios cadastrados?
Basta clicar na segunda aba, "Tabela de dados", que todos os domicílios cadastrados estarão em uma tabela. Você pode ordená-los para uma melhor visualização segundo dois critérios: pelo CEP ou número do domicílio, apenas clicando em um dos botões presentes no canto superior da tela.

![ordenar_cep]()
![ordenar_num]()

#### Após o cadastro, como visualizar as estatísticas?
Basta clicar na terceira aba, "Estatísticas", que lá estarão presentes informações como: total de domicílios cadastrados até o momento, renda média dos domicílios cadastrados, entre outros.

![estatisticas]()

#### Como editar ou excluir os dados cadastrados?
Você pode alterar os dados do domicílio clicando duas vezes sobre a célula correspondente na tabela.

![tabela]()

Uma janela se abrirá, mostrando os dados cadastrados e duas informações geradas internamente pelo programa: o nível de densidade populacional e o nível de carência da família presente no domicílio. Para editar, bastar modificar as opções desejadas e clicar no botão "Salvar".

![salvar1]()

Para excluir, basta clicar duas vezes na célula correspondente na tabela, e clicar no botão "Excluir".

![tabela]()
![excluir1]()
![excluir2]()

#### Como salvar os domicílios cadastrados em um arquivo? E como carregar os domicílios cadastrados de um arquivo existente?

Basta selecionar a opção "Salvar Arquivo"(ou o atalho *Ctrl+S* do teclado) e todos os domicílios cadastrados serão salvos em arquivos separados por vírgula (.csv).

![salvar_arquivo1]()
![salvar_arquivo2]()

Para carregar basta selecionar a opção "Carregar Arquivo" (ou o atalho *Ctrl+A* do teclado) e escolher um arquivo que respeite o formato lido pelo programa (todas informações separadas por vírgulas). Assim o arquivo é lido e mostrado mostrado automaticamente na tabela e estará pronto para ser visualizado, modificado e salvo, posteriormente, se assim for desejado.

![carregar_Arquivo1]()
![carregar_Arquivo2]()
![carregar_Arquivo3]()

## Obrigado!

Este projeto é resultado do empenho do aluno **Gustavo Henrique Diniz Souza**, bacharelando em Engenharia Elétrica no IFPB - *campus* João Pessoa. Desenvolvido para a disciplina de Técnicas de Programação, ministrada pelo Dr. Patric Lacouth da Silva, com o objetivo de adquirição de nota parcial para a conclusão da disciplina em questão. Para quaisquer dúvidas ou *feedback*, o e-mail para contato é: gustavo.souza@academico.ifpb.edu.br. 
