# Binary Telemetry Simulator 🛰️

Um simulador de telemetria de satélite que demonstra manipulação de bits em C, compactando dados de sensores num único `uint16_t` (2 bytes) para poupar memória.

## 📋 Descrição

Este projeto implementa um sistema de codificação e decodificação de dados de telemetria, simulando o envio de pacotes de satélite. Os dados são compactados utilizando operadores bitwise e armazenados em ficheiros binários.

### Dados Compactados

Cada pacote de telemetria contém 3 informações num único inteiro de 16 bits:

| Campo | Bits | Intervalo | Descrição |
|-------|------|-----------|-----------|
| **Temperatura** | 7 | 0-100°C | Temperatura do satélite |
| **Nível de Bateria** | 4 | 0-15 | Nível de carga da bateria |
| **Erro de Sistema** | 1 | 0-1 | Flag de erro (0=OK, 1=Erro) |

**Total: 12 bits usados em 16 bits disponíveis**


## 📖 Como Usar

O programa apresenta um menu interativo com as seguintes opções:

```
------------------------
1 - Guardar Dados
2 - Ler Dados Printar
9 - Quit
------------------------
```

### Opção 1: Guardar Dados
- Solicita os valores de entrada:
  - **Temperatura**: Valor entre 0 e 100
  - **Bateria**: Valor entre 0 e 15
  - **Erro**: Valor entre 0 e 1
- Compacta os dados num `uint16_t`
- Guarda no ficheiro binário `telemetria.bin`

### Opção 2: Ler Dados
- Lê o ficheiro binário `telemetria.bin`
- Extrai os valores originais utilizando operadores bitwise
- Imprime os dados descompactados no ecrã

### Opção 9: Sair
- Encerra o programa

## 🔧 Conceitos Técnicos

### Operadores Bitwise Utilizados

- **`<<` (Left Shift)**: Desloca bits para a esquerda, fazendo espaço para novos valores
- **`>>` (Right Shift)**: Desloca bits para a direita, para aceder aos valores
- **`|` (OR Bitwise)**: Combina bits de múltiplas variáveis
- **`&` (AND Bitwise)**: Extrai bits específicos utilizando máscaras

### Exemplo de Compactação

```c
// Entrada: Temp=25, Bateria=12, Erro=0

// Passo 1: Temperatura (7 bits no topo)
data->info = 25;           // 0000000011001

// Passo 2: Deslocar para a esquerda 4 bits (espaço para bateria)
data->info = data->info << 4;  // 0011001 0000

// Passo 3: Adicionar bateria (4 bits)
data->info = data->info | 12;  // 0011001 1100

// Passo 4: Deslocar para a esquerda 1 bit (espaço para erro)
data->info = data->info << 1;  // 0110011 1000

// Passo 5: Adicionar erro (1 bit)
data->info = data->info | 0;   // 0110011 1000

// Resultado final: 0000 0110 0111 1000 (0x0678)
```

### Exemplo de Descompactação

```c
// Extrair erro (1º bit)
erro = data->info & 0x01;      // 0

// Extrair bateria (4 bits, após o erro)
bateria = (data->info >> 1) & 0x0F;    // 12

// Extrair temperatura (7 bits, após erro + bateria)
temperatura = (data->info >> 5) & 0x7F;  // 25
```

## 📁 Estrutura de Ficheiros

```
C-BinaryTelemetrySimulator/
├── README.md                 # Este ficheiro
├── main.c                    # Código-fonte principal
├── ideiadeprojeto.md         # Especificação do projeto
├── telemetria.bin           # Ficheiro binário gerado (criado na execução)
└── output/                  # Diretório para outputs
```

## 🎓 Conceitos de Aprendizagem

Este projeto demonstra:

-**Manipulação de Bits**: Operações bitwise para compactar dados
-**Structs em C**: Organização de dados em estruturas
-**Gestão de Memória**: Otimização de espaço em memória
-**Operações de Ficheiros**: Leitura e escrita de dados binários
-**Máscaras de Bits**: Extração de campos específicos de dados compactados


## ⚠️ Notas Importantes

- O ficheiro `telemetria.bin` é criado automaticamente na primeira execução da opção 1
- Os valores de entrada são validados para garantir que estão dentro dos intervalos permitidos
- O programa usa tipos de dados `uint16_t` para portabilidade entre plataformas

## 👨‍💻 Autor

**Simão** - Desenvolvedor

Projeto desenvolvido como exercício prático de manipulação de bits e programação de sistemas em C.

## 📄 Licença

Este projeto é fornecido como material educacional.
