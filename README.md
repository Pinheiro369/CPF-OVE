**CPF OVE** - **C**PF **O**timizado com **V**alidação **E**stendida  

**Acrônimo Explicado:**  
- **O**timizado: Interface aprimorada com recursos visuais e interatividade  
- **V**alidação: Sistema rigoroso de validação de dígitos  
- **E**stendido: Análise complementar de dados demográficos e curiosidades  

---

# **CPF OVE**  
**Validador Interativo de CPF com Análise Estendida**  

![](https://img.shields.io/badge/License-MIT-blue) 
![](https://img.shields.io/badge/Version-2.1-green)  
![](https://img.shields.io/badge/C++-17-orange)

## 📋 Descrição  
Ferramenta avançada para validação de CPF brasileiro com:  
✅ Verificação matemática rigorosa  
🎨 Interface colorida interativa  
🗺️ Detecção de possível região de emissão  
🎂 Simulação de dados demográficos (idade, geração, signo)  
🔍 Análise de padrões e curiosidades  

## ✨ Funcionalidades  
- **Validação Real-Time**  
  - Algoritmo oficial de dígitos verificadores  
  - Proteção contra CPFs inválidos ou sequências repetidas  
- **Inteligência Geográfica**  
  - Mapeamento do 9º dígito para estados brasileiros  
- **Perfil Demográfico Simulado***  
  - Idade aproximada  
  - Geração (Baby Boomer, Millennial, etc.)  
  - Signo zodiacal  
  - Data de nascimento teórica  
- **Design Moderno**  
  - Códigos ANSI para cores dinâmicas  
  - ASCII art e bordas estilizadas  
  - Menu interativo  

*Nota: Dados demográficos são exemplos ilustrativos baseados em padrões numéricos.*

## 🛠️ Como Usar  
```bash
# Compilar (requer C++11 ou superior)
g++ -o cpf_ove main.cpp -std=c++11

# Executar
./cpf_ove
```

## 🖥️ Demonstração  
```text
1. Validar CPF e mostrar detalhes  
2. Verificar região de origem  
3. Sobre este programa  
4. Sair  

Escolha: 1  

Digite o CPF: 123.456.789-09  

╔══════════════════════════════════════╗  
║           RESULTADO DA ANÁLISE         ║  
╠══════════════════════════════════════╣  
CPF: 1 2 3 . 4 5 6 . 7 8 9 - 0 9  
Status: Válido ✔  
Região: SP  
Data Nasc.: 12/34/1945 (exemplo)  
Geração: Silent Generation  
Signo: Leão  
╚══════════════════════════════════════╝  
```

## 📝 Notas Técnicas  
- **Precisão**: Validação matemática 100% precisa  
- **Limitações**:  
  - Dados demográficos são fictícios (fins educacionais)  
  - Não utiliza bases de dados reais  
- **Compatibilidade**: Testado em Linux/macOS/Windows (WSL)  

## 📜 Licença  
MIT License - Livre para uso e modificação, com menção ao autor original.  

--- 

**CPF OVE** - Para fins educacionais e técnicos. Não utilize para validações oficiais ou sensíveis.
