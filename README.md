# Raft Simulator

Trabalho final de **Laboratório de Programação III**: um simulador visual do algoritmo de consenso
**Raft**, feito em C++ com Qt.

O simulador mostra um cluster de servidores rodando o Raft e permite observar e provocar:

- **Eleição de líder**: timeouts aleatórios, pedidos de voto, termos;
- **Replicação de log**: `AppendEntries`, heartbeats, avanço do `commitIndex`;
- **Falhas**: queda e reinício de nós, partições de rede e perda de mensagens.

O estado persistente de cada nó (`currentTerm`, `votedFor` e `log`) é gravado em arquivo, como o
algoritmo exige, para que um nó reiniciado recupere esse estado.

> Projeto em desenvolvimento.

## Requisitos

- Qt 6 (desenvolvido com Qt 6.12), módulo Widgets
- CMake ≥ 3.16
- Compilador com suporte a C++20

## Como compilar

### Pelo Qt Creator

1. *File → Open File or Project* e selecione o `CMakeLists.txt`.
2. Escolha um kit Qt 6 (ex.: *Desktop Qt 6.12.0 GCC 64bit*).
3. *Build → Run* (`Ctrl+R`).

### Pela linha de comando

```bash
cmake -S . -B build -DCMAKE_PREFIX_PATH=<caminho-do-qt>/6.12.0/gcc_64
cmake --build build
./build/raft_simulator
```

## Estrutura

```
src/
  main.cpp
  gui/        # interface gráfica (janela principal, visualização do cluster)
```

## Referência

Diego Ongaro e John Ousterhout. *In Search of an Understandable Consensus Algorithm (Extended
Version)*, 2014. <https://raft.github.io/raft.pdf>
