# Simulador de um Processador
Este programa em C++ simula a execução de instruções básicas de um processador simples, manipulando registradores e memória RAM a partir de arquivos de texto.

## Estrutura dos Arquivos

- `entrada.txt`: Arquivo de entrada com as instruções a serem executadas.
- `banco_registradores.txt`: Contém os valores dos registradores (R0 a R3).
- `memoria_ram.txt`: Contém os valores da memória RAM simulada.
- `unicade_controle.txt`: Log dos ciclos de execução (ciclo de clock, PC, IR).

## Instruções Suportadas

- `LOAD Rn M`: Carrega o valor da posição M da memória RAM no registrador Rn.
- `STORE Rn M`: Armazena o valor do registrador Rn na posição M da memória RAM.
- `MOVE Rn Rm`: Move o valor do registrador Rm para o registrador Rn.
- `ADD Rn Rm Rp`: Soma os valores de Rm e Rp e armazena em Rn.
- `SUB Rn Rm Rp`: Subtrai Rp de Rm e armazena em Rn.
- `OR Rn Rm Rp`: Executa operação lógica OR entre Rm e Rp e armazena em Rn.
- `AND Rn Rm Rp`: Executa operação lógica AND entre Rm e Rp e armazena em Rn.
- `BRANCH PC`: Altera o contador de programa (PC) para a instrução da posição informada.
- `NOP`: Instrução nula (sem efeito).
- `HALT`: Finaliza a execução do programa.

## Fluxo de Execução

1. Inicializa o banco de registradores com valores zero.
2. Limpa o log da unidade de controle (`unicade_controle.txt`).
3. Lê as instruções de `entrada.txt` e executa uma a uma.
4. Atualiza o conteúdo de registradores e memória conforme as instruções.
5. Registra os ciclos de execução no arquivo `unicade_controle.txt`.

## Funções Principais

- `iniciarReg()`: Inicializa o banco de registradores (R0–R3) com zero.
- `arqOpen()`: Lê as instruções de entrada e gerencia a execução.
- `unicadeC()`: Escreve o ciclo de controle no arquivo de log.
- `executar()`: Encaminha cada instrução para a função apropriada.
- `add(), sub(), orReg(), andReg()`: Operações aritméticas/lógicas.
- `store(), registradores(), moveRegis()`: Manipulações de registradores e memória.
- `lerValorRegistrador()`: Retorna o valor de um registrador.

## Exemplo de `entrada.txt`

```
LOAD R0 1
LOAD R1 2
ADD R2 R0 R1
STORE R2 3
HALT
```

## Observações

- Os arquivos devem estar no mesmo diretório do executável.
- A posição da memória na instrução `LOAD`/`STORE` deve começar em 1 (não zero-indexada).
---

## 📂 Exemplos de Conteúdo dos Arquivos

### `entrada.txt`
Contém as instruções que o simulador irá executar. Cada linha representa uma instrução no formato:

```
INSTRUÇÃO OPERANDO1 OPERANDO2 OPERANDO3
```

**Exemplo:**
```
LOAD R0 1
LOAD R1 2
ADD R2 R0 R1
STORE R2 3
HALT
```

---

### `memoria_ram.txt`
Representa a memória principal do sistema. Cada linha é uma posição de memória numerada implicitamente a partir de 1.

**Exemplo:**
```
10
20
0
```

Neste exemplo:
- Posição 1 contém o valor `10`
- Posição 2 contém o valor `20`
- Posição 3 está vazia (poderá receber dados de um STORE, por exemplo)

---

### `banco_registradores.txt`
Armazena os valores atuais dos registradores. Cada linha tem o formato:

```
R#: VALOR
```

**Exemplo:**
```
R0: 10
R1: 20
R2: 30
R3: 0
```

---

### `unicade_controle.txt`
Arquivo de log que mostra o histórico das instruções executadas, com informações de ciclo, PC e IR.

**Exemplo:**
```
CICLO: 0 | PC: 0 | IR: LOAD R0 1 
CICLO: 1 | PC: 1 | IR: LOAD R1 2 
CICLO: 2 | PC: 2 | IR: ADD R2 R0 R1 
CICLO: 3 | PC: 3 | IR: STORE R2 3 
CICLO: 4 | PC: 4 | IR: HALT  
```