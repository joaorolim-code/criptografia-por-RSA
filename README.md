-> OBJETIVO

Disponibilizar livremente um algoritmo simples de implementação da criptografia assimétrica RSA.

-> FUNCIONALIDADES:

- Geração de Chaves = Cálculo do Módulo e Validação de Primos.
- Função Totiente de Euler = Cálculo do φ(n).
- Algoritmo de Euclides = Validação de coprimos para geração da chave pública.
- Inverso Multiplicativo Modular = Cálculo da chave privada para reversão criptográfica. 
- Exponenciação Modular = Encriptação otimizada para evitar vazamentos de memória. 

-> INSTRUÇÕES PARA COMPILAÇÃO:

1. Clone o repositório em sua máquina:

git clone 

2. Navegue até a pasta do projeto e compile-o:

cd sla
gcc RSA.c -o RSA.exe

3. Execute o binário gerado:

.\RSA.exe

4. O programa está pronto para ser executado!

-> LIMITAÇÕES:

	O algoritmo foi desenvolvido para objetivos puramente educativos e para demonstrações triviais, então foram utilizados apenas o tipos nativos da linguagem C para a implementação ('int' e 'long long'). 
	Isso implica numa contradição à realidade do uso da criptografia RSA, onde são utilizados primos gigantescos de pelo menos 1024 bits, um tamanho não suportado nativamente pelo C. O programa consegue suportar primos de até 64 bits, um tamanho seguro para evitar estouros de memória e travamentos. 
	
-> AUTOR:

João Gabriel Rolim Veiga, Graduando em Engenharia de Software pela Universidade de Brasília (UnB)
