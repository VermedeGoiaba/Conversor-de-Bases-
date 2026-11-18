# Conversor de Bases Numéricas

Projeto desenvolvido em C++ para a disciplina de Arquitetura e Organização de Computadores.

O programa realiza conversões entre seis sistemas de numeração, utilizando operações matemáticas e estruturas de controle da linguagem C++.

## Bases disponíveis

- Binária (base 2)
- Decimal (base 10)
- Octal (base 8)
- Hexadecimal (base 16)
- Duodecimal (base 12)
- Vigesimal (base 20)

## Funcionamento

O usuário seleciona a base de origem, a base de destino e informa o número que deseja converter.

A conversão é realizada em duas etapas: primeiro, o número é convertido para decimal; depois, são utilizadas divisões sucessivas para obter o resultado na base escolhida. Assim, o processo de escrita do código é otimizado.

O programa permite realizar várias conversões sem precisar reiniciá-lo.

## Recursos utilizados

- Estruturas condicionais: `if/else` e `switch`
- Laços de repetição: `for`, `while` e `do while`
- Manipulação de strings
- Operações de divisão, multiplicação e resto
- Validação de entradas e caracteres
- Prevenção de overflow numérico

## Validações

Para evitar erros durante a execução, foram implementadas verificações de caracteres inválidos, limites numéricos e tamanho das entradas. O programa também impede que a base de origem seja igual à base de destino.

Observação: o conversor trabalha com números inteiros não negativos, respeitando os limites do tipo `unsigned long long`.

## Autoria

Laura Gomes Theodoro

Disciplina: Arquitetura e Organização de Computadores - FATEC Ribeirão Preto

Linguagem: C++
