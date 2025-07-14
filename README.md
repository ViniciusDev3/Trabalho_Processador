# Simulador de Processado 

Este projeto em C++ simula um sistema simples de registradores e memória RAM, com suporte a instruções do tipo assembly, como `LOAD`, `STORE`, `ADD`, `MOVE`, `BRANCH`, `HALT`, entre outras. Ele manipula arquivos como `banco_registradores.txt`, `memoria_ram.txt`, `entrada.txt` e `unicade_controle.txt`.

## 📁 Estrutura dos Arquivos

- **`banco_registradores.txt`**: Armazena o valor atual dos registradores (`R0` a `R3`).
- **`memoria_ram.txt`**: Representa a memória RAM do sistema.
- **`entrada.txt`**: Contém o programa com as instruções a serem executadas.
- **`unicade_controle.txt`**: Registra a execução do programa (PC, IR e operandos).

## 🚀 Instruções Suportadas

| Instrução | Descrição |
|----------|-----------|
| `LOAD Rx M` | Carrega da memória RAM (linha `M`) o valor e armazena no registrador `Rx`. |
| `STORE Rx M` | Armazena no endereço `M` da RAM o valor do registrador `Rx`. |
| `MOVE Rx Ry` | Move o valor do registrador `Ry` para o registrador `Rx`. |
| `ADD Rd Rs Rt` | Soma os valores de `Rs` e `Rt` e armazena em `Rd`. |
| `SUB Rd Rs Rt` | Subtrai `Rt` de `Rs` e armazena em `Rd`. |
| `AND Rd Rs Rt` | Aplica operação lógica AND entre `Rs` e `Rt` e armazena em `Rd`. |
| `OR Rd Rs Rt` | Aplica operação lógica OR entre `Rs` e `Rt` e armazena em `Rd`. |
| `BRANCH L` | Altera o PC (program counter) para a linha `L`. |
| `BNEG L` | Altera o PC para `L` se o último valor calculado (`ultimoValor`) for negativo. |
| `BZERO L` | Altera o PC para `L` se o último valor calculado for zero. |
| `HALT` | Encerra a execução do programa. |

## 📌 Estrutura do Programa

- `main()`:
  - Inicializa os registradores com valor `0`.
  - Limpa a `unicade_controle.txt`.
  - Chama `arqOpen()` para começar a executar as instruções do programa.

- `arqOpen()`:
  - Lê o arquivo `entrada.txt`.
  - Interpreta linha por linha.
  - Atualiza `PC`, registra os estados em `unicade_controle.txt`.
  - Chama funções apropriadas conforme a instrução.

- `executar(...)`: 
  - Encaminha a execução para as funções de instrução (LOAD, STORE, ADD etc).

- `unicadeC(...)`: 
  - Registra a instrução atual em `unicade_controle.txt`.

## 📥 Formato dos Arquivos

### entrada.txt

Exemplo:
```
LOAD R0 1
LOAD R1 2
ADD R2 R0 R1
STORE R2 5
HALT
```

### banco_registradores.txt (inicializado automaticamente)

```
R0: 0
R1: 0
R2: 0
R3: 0
```

### memoria_ram.txt

Representa a memória principal do sistema. Cada linha é uma posição de memória numerada implicitamente a partir de 1.

```
10
20
...
```

### unicade_controle.txt

Gerado automaticamente com o formato:
```
PC: 0 | IR: LOAD R0 1
PC: 1 | IR: LOAD R1 2
...
```

## 🧠 Observações

- Os arquivos `.txt` devem estar no mesmo diretório do executável.
- A simulação depende de I/O em arquivos, então garantir permissões adequadas.
- Os registradores são limitados a `R0` a `R3`.
- A RAM é manipulada como um vetor de strings.
