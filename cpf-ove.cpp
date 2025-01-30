
#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <sstream>

using namespace std;

// Códigos ANSI para cores
const string RED = "\033[1;31m";
const string GREEN = "\033[1;32m";
const string YELLOW = "\033[1;33m";
const string BLUE = "\033[1;34m";
const string MAGENTA = "\033[1;35m";
const string CYAN = "\033[1;36m";
const string RESET = "\033[0m";

// Estrutura para dados derivados
struct CPFData {
    string raw;
    string formatted;
    bool isValid;
    string region;
    string birthDate;
    int age;
    string generation;
    string zodiac;
};

void printBanner() {
    system("clear || cls");
    cout << BLUE << R"(
    ██████╗ ██████╗ ███████╗       ██████╗ ██╗   ██╗███████╗
    ██╔════╝ ██╔══██╗██╔════╝      ██╔═══██╗██║   ██║██╔════╝
    ██║  ███╗██████╔╝█████╗█████╗ ██║   ██║██║   ██║█████╗  
    ██║   ██║██╔═══╝ ██╔══╝╚════╝ ██║   ██║╚██╗ ██╔╝██╔══╝  
    ╚██████╔╝██║     ██║          ╚██████╔╝ ╚████╔╝ ███████╗
     ╚═════╝ ╚═╝     ╚═╝           ╚═════╝   ╚═══╝  ╚══════╝
    )" << RESET << "\n\n";
}

string getColor(char c) {
    vector<string> colors = {RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN};
    return colors[rand() % colors.size()];
}

void printColoredCPF(const string& cpf) {
    for(char c : cpf) {
        cout << getColor(c) << c << RESET;
    }
    cout << "\n";
}

string cleanCPF(string cpf) {
    string cleaned;
    for(char c : cpf) {
        if(isdigit(c)) cleaned += c;
    }
    return cleaned;
}

bool allSameDigits(const string& cpf) {
    for(size_t i = 1; i < cpf.length(); i++) {
        if(cpf[i] != cpf[0]) return false;
    }
    return true;
}

bool validateCPF(string cpf) {
    cpf = cleanCPF(cpf);
    if(cpf.length() != 11 || allSameDigits(cpf)) return false;
    
    int sum = 0;
    for(int i = 0; i < 9; i++) sum += (cpf[i] - '0') * (10 - i);
    int firstDigit = (sum * 10) % 11;
    if(firstDigit == 10) firstDigit = 0;
    
    sum = 0;
    for(int i = 0; i < 10; i++) sum += (cpf[i] - '0') * (11 - i);
    int secondDigit = (sum * 10) % 11;
    if(secondDigit == 10) secondDigit = 0;
    
    return (firstDigit == cpf[9] - '0') && (secondDigit == cpf[10] - '0');
}

string getCPFRegion(const string& cpf) {
    map<int, string> states = {
        {0, "RS"}, {1, "DF/GO/MS/MT/TO"}, {2, "AC/AM/AP/PA/RO/RR"},
        {3, "CE/MA/PI"}, {4, "AL/PB/PE/RN"}, {5, "BA/SE"},
        {6, "MG"}, {7, "ES/RJ"}, {8, "SP"}, {9, "PR/SC"}
    };
    return states[cpf[8] - '0'];
}

string calculateZodiac(int day, int month) {
    vector<string> zodiac = {
        "Capricórnio", "Aquário", "Peixes", "Áries", "Touro", "Gêmeos",
        "Câncer", "Leão", "Virgem", "Libra", "Escorpião", "Sagitário"
    };
    
    if((month == 1 && day >= 20) || (month == 2 && day <= 18)) return zodiac[1];
    if((month == 2 && day >= 19) || (month == 3 && day <= 20)) return zodiac[2];
    if((month == 3 && day >= 21) || (month == 4 && day <= 19)) return zodiac[3];
    if((month == 4 && day >= 20) || (month == 5 && day <= 20)) return zodiac[4];
    if((month == 5 && day >= 21) || (month == 6 && day <= 20)) return zodiac[5];
    if((month == 6 && day >= 21) || (month == 7 && day <= 22)) return zodiac[6];
    if((month == 7 && day >= 23) || (month == 8 && day <= 22)) return zodiac[7];
    if((month == 8 && day >= 23) || (month == 9 && day <= 22)) return zodiac[8];
    if((month == 9 && day >= 23) || (month == 10 && day <= 22)) return zodiac[9];
    if((month == 10 && day >= 23) || (month == 11 && day <= 21)) return zodiac[10];
    if((month == 11 && day >= 22) || (month == 12 && day <= 21)) return zodiac[11];
    return zodiac[0];
}

CPFData analyzeCPF(string cpf) {
    CPFData data;
    data.raw = cleanCPF(cpf);
    data.isValid = validateCPF(cpf);
    
    // Formatação do CPF
    data.formatted = data.raw.substr(0, 3) + "." + data.raw.substr(3, 3) + "." +
                    data.raw.substr(6, 3) + "-" + data.raw.substr(9, 2);
    
    // Região
    data.region = getCPFRegion(data.raw);
    
    // Data de nascimento simulada (nota: isto é fictício)
    int day = stoi(data.raw.substr(0, 2));
    int month = stoi(data.raw.substr(2, 2));
    int year = 1900 + stoi(data.raw.substr(4, 2));
    
    // Ajuste de datas inválidas
    day = max(1, min(day, 31));
    month = max(1, min(month, 12));
    
    // Cálculo da idade
    time_t now = time(0);
    tm *ltm = localtime(&now);
    data.age = (1900 + ltm->tm_year) - year;
    
    // Geração
    if(year >= 1946 && year <= 1964) data.generation = "Baby Boomer";
    else if(year >= 1965 && year <= 1980) data.generation = "Geração X";
    else if(year >= 1981 && year <= 1996) data.generation = "Millennial";
    else if(year >= 1997 && year <= 2012) data.generation = "Geração Z";
    else data.generation = "Outra Geração";
    
    // Signo
    data.zodiac = calculateZodiac(day, month);
    
    // Formata data
    stringstream birth;
    birth << setw(2) << setfill('0') << day << "/"
         << setw(2) << setfill('0') << month << "/" << year;
    data.birthDate = birth.str();
    
    return data;
}

void printResult(const CPFData& data) {
    cout << YELLOW << "\n╔══════════════════════════════════════╗\n";
    cout << "║           RESULTADO DA ANÁLISE         ║\n";
    cout << "╠══════════════════════════════════════╣\n" << RESET;
    
    cout << MAGENTA << "║ CPF:   " << RESET;
    printColoredCPF(data.formatted);
    
    cout << (data.isValid ? GREEN : RED) << "║ Status: " << setw(29) << left 
         << (data.isValid ? "Válido" : "Inválido") << RESET << "║\n";
    
    cout << CYAN << "╠══════════════════════════════════════╣\n" << RESET;
    cout << BLUE << "║ Região:        " << setw(21) << left << data.region << "║\n";
    cout << "║ Data Nasc.:    " << setw(21) << left << data.birthDate << "║\n";
    cout << "║ Idade:         " << setw(21) << left << to_string(data.age) + " anos" << "║\n";
    cout << "║ Geração:       " << setw(21) << left << data.generation << "║\n";
    cout << "║ Signo:         " << setw(21) << left << data.zodiac << "║\n";
    cout << YELLOW << "╚══════════════════════════════════════╝\n\n" << RESET;
}

void printMenu() {
    cout << CYAN << "Menu Principal:\n";
    cout << YELLOW << "1. " << GREEN << "Validar CPF e mostrar detalhes\n";
    cout << YELLOW << "2. " << GREEN << "Verificar região de origem\n";
    cout << YELLOW << "3. " << GREEN << "Sobre este programa\n";
    cout << YELLOW << "4. " << RED << "Sair\n" << RESET;
    cout << MAGENTA << "Escolha uma opção: " << RESET;
}

void aboutProgram() {
    printBanner();
    cout << GREEN << "╔══════════════════════════════════════╗\n";
    cout << "║             SOBRE O PROGRAMA          ║\n";
    cout << "╠══════════════════════════════════════╣\n";
    cout << "║ Versão: 2.1                         ║\n";
    cout << "║ Autor: Seu Nome                     ║\n";
    cout << "║ Funcionalidades:                    ║\n";
    cout << "║ • Validação de CPF real             ║\n";
    cout << "║ • Análise de dados simulados*       ║\n";
    cout << "║ • Detecção de região                ║\n";
    cout << "║ • Informações demográficas          ║\n";
    cout << "║ * Nota: Datas são exemplos fictícios║\n";
    cout << "╚══════════════════════════════════════╝\n\n" << RESET;
}

int main() {
    srand(time(0));
    int choice;
    string cpf;

    do {
        printBanner();
        printMenu();
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1: {
                cout << "\nDigite o CPF (com ou sem formatação): ";
                getline(cin, cpf);
                CPFData data = analyzeCPF(cpf);
                printResult(data);
                break;
            }
            case 2: {
                cout << "\nDigite os 9 primeiros dígitos: ";
                getline(cin, cpf);
                string cleaned = cleanCPF(cpf);
                if(cleaned.length() >= 9) {
                    cout << "\n" << MAGENTA << "Região de origem: " 
                         << getCPFRegion(cleaned.substr(0, 9)) << RESET << "\n\n";
                } else {
                    cout << RED << "Entrada inválida!\n" << RESET;
                }
                break;
            }
            case 3:
                aboutProgram();
                break;
            case 4:
                cout << GREEN << "\nObrigado por usar!\n" << RESET;
                break;
            default:
                cout << RED << "Opção inválida!\n" << RESET;
        }
        
        if(choice != 4) {
            cout << YELLOW << "\nPressione Enter para continuar..." << RESET;
            cin.ignore();
        }
    } while(choice != 4);

    return 0;
}