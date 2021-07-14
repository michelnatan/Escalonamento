Implementação de um programa na linguagem C, onde executa as regras de escalonamento não-preemptivo. 
O programa executado apartir de uma entrada de um arquivo .txt conforme exemplo abaixo. O arquivo texto representará as N tarefas que serão computadas pelo
escalonador. A primeira linha representa a quantidade de tarefas N. As N linhas subsequentes são compostas por 4 valores numéricos separados pelo caractere #, onde
cada valor representa, respectivamente: PID, tempo de chegada, burst e prioridade.


Exemplo de entrada:
3
1#2#06#3
2#6#08#2
3#8#10#1

Exemplo de saída:
PROCESSO  TEMPO
   1    |  0
   2    |  2
   3    |  8
   
TME = 3.33

Após o processamento da entrada, o programa irá imprimir N linhas apontando o tempo de espera de cada tarefa. Após imprimir as N linhas, será apresentar o tempo médio de espera
(TME) calculado com base nas N tarefas computadas pelo escalonador.


COMANDO UTILIZADOS EM LINUX:

#COMPLIANDO ARQUIVOS
-> gcc escalonamento.c -o escalonamento

#REALIZANDO ENTRADA DE ARQUIVO TEXTO
-> ./escalonamento < entrada.txt

