# Codificador de Satélite

**Linguagem:** C  
**Foco:** Manipulação de Bits (Bitwise), Structs, Gestão de Memória e Endianness.  

## O Desafio

Cria um programa que simula o envio de pacotes de telemetria de um satélite.

### Compactação

Define uma struct que guarda 3 informações num único `uint16_t` (2 bytes) para poupar memória:

- **Temperatura** (0-100): Usa 7 bits.
- **Nível de Bateria** (0-15): Usa 4 bits.
- **Erro de Sistema** (0 ou 1): Usa 1 bit.


### Serialização

Usa operadores Bitwise (`<<`, `>>`, `|`, `&`) para "empacotar" estes valores numa variável e depois guarda-a num ficheiro binário (`telemetria.bin`).

### Leitura

Cria um segundo pequeno programa que lê esse ficheiro binário e imprime os valores originais no ecrã.

