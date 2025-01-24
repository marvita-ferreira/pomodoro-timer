# pomodoro-timer

Este projeto implementa um **temporizador Pomodoro** simples em C++. Ele inclui:
- **Versão Original**: Um timer funcional com exibição no terminal.
- **Versão Melhorada**: Código modularizado com entradas personalizadas.

## Estrutura do Repositório
- `original/`: Contém o código original.
- `improved/`: Contém o código melhorado.
- `README.md`: Documentação do projeto.

## Melhorias Feitas
1. **Modularização**:
   - Funções separadas para contagem regressiva e configuração.
2. **Entrada Personalizada**:
   - O usuário pode configurar tempos de trabalho e pausas.
3. **Tratamento de Erros**:
   - Usa valores padrão caso a entrada seja inválida.

## Como Compilar e Executar
### Compilar:
No terminal, execute:
```bash
g++ -o pomodoro original/pomodoro_original.cpp
./pomodoro
