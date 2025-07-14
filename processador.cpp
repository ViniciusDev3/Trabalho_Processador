#include <cstddef>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int ultimoValor = 0;
void moveRegis(string regist1, string regist2)
{
    //Vai ler todos os dados do arquivo e colocar em um vetor
    ifstream registV("banco_registradores.txt");
    vector<string> linhas;
    string linha;
    if (registV.is_open())
    {
        while (getline(registV, linha))
        {
            linhas.push_back(linha);
        }
        registV.close();
    } else {
        cout << "Erro ao abrir o arquivo para leitura!!!" << endl;
    }

    string reg;
    string valor;
    for (size_t i = 0; i < linhas.size(); i++)
    {
        istringstream iss(linhas[i]);
        
        getline(iss, reg, ':');
        iss >> valor;

        if (reg == regist2)
        {
            break;
        }
    }

    for (size_t i = 0; i < linhas.size(); i++)
    {
        istringstream iss(linhas[i]);
        getline(iss, reg, ':');

        if (reg == regist1)
        {
            linhas[i] = regist1 + ": " + valor;
        }
    }
    ultimoValor = stoi(valor);

    //Registra nos registradores R0, R1, R3, R4 nos novos valores
    ofstream regist("banco_registradores.txt");
    if (regist.is_open())
    {
        for (size_t i = 0; i < linhas.size(); i++)
        {
            regist << linhas[i] << endl;
        }
    } else {
        cout << "Erro ao abrir o arquivo!!!" << endl;
    }
    
}

void registradores(string registrador, string M) 
{
    //Vai ler todos os dados do arquivo e colocar em um vetor
    ifstream registV("banco_registradores.txt");
    vector<string> linhas;
    string linha;
    if (registV.is_open())
    {
        while (getline(registV, linha))
        {
            linhas.push_back(linha);
        }
        registV.close();
    } else {
        cout << "Erro ao abrir o arquivo para leitura!!!" << endl;
    }
    
    int i = 0;
    ifstream memoriaR("memoria_ram.txt");
    if (memoriaR.is_open())
    {
        for ( i; i < linhas.size(); i++)
        {
            string reg;
            istringstream iss(linhas[i]);
            getline(iss, reg, ':');

            if (reg == registrador)
            {
                break;
            }
        }
        
        int cont = 0;
        string linhaR, valorM;
        while (getline(memoriaR, linhaR))
        {
            cont++;
            if (cont == stoi(M))
            {
                istringstream textR(linhaR);
                textR >> valorM;
            }
        }
        linhas[i] = registrador + ": " + valorM;
        ultimoValor = stoi(valorM);
        memoriaR.close();
    } else {
        cout << "Erro ao abrir o arquivo de entrada" << endl;
    }

    //Registra nos registradores R0, R1, R3, R4 nos novos valores
    ofstream regist("banco_registradores.txt");
    if (regist.is_open())
    {
        for (size_t i = 0; i < linhas.size(); i++)
        {
            regist << linhas[i] << endl;
        }
    } else {
        cout << "Erro ao abrir o arquivo!!!" << endl;
    }
}

string lerValorRegistrador(const string& registrador)
{
    ifstream file("banco_registradores.txt");
    string linha;
    string reg, valor;

    while(getline(file, linha))
    {
        istringstream iss(linha);
        getline(iss, reg, ':');
        iss >> valor;

        if(reg == registrador)
        {
            return valor;
        }
    }

    return "";
}

void add(string destino, string origem1, string origem2)
{
    string v1 = lerValorRegistrador(origem1);
    string v2 = lerValorRegistrador(origem2);

    int val1 = stoi(v1);
    int val2 = stoi(v2);

    int soma = val1 + val2;
    ultimoValor = soma; 
    ifstream registR("banco_registradores.txt");
    vector <string> linhas;
    string linha;

    while(getline(registR, linha))
    {
        linhas.push_back(linha);
    }

    registR.close();

    for(size_t i = 0; i < linhas.size(); i++)
    {
        istringstream iss(linhas[i]);
        string reg;
        getline(iss, reg, ':');

        if (reg == destino) 
        {
            linhas[i] = destino + ": " + to_string(soma);
        }
    }

    ofstream registW("banco_registradores.txt");
    for (const auto& l : linhas) 
    {
        registW << l << endl;
    }
    registW.close();
    
    cout << "ADD" << endl;    
}

void sub(string destino, string origem1, string origem2)
{
    string v1 = lerValorRegistrador(origem1);
    string v2 = lerValorRegistrador(origem2);

    int val1 = stoi(v1);
    int val2 = stoi(v2);

    int subtracao = val1 - val2;
    ultimoValor = subtracao; 

    ifstream registR("banco_registradores.txt");
    vector <string> linhas;
    string linha;

    while(getline(registR, linha))
    {
        linhas.push_back(linha);
    }

    registR.close();

    for(size_t i = 0; i < linhas.size(); i++)
    {
        istringstream iss(linhas[i]);
        string reg;
        getline(iss, reg, ':');

        if (reg == destino) 
        {
            linhas[i] = destino + ": " + to_string(subtracao);
        }
    }

    ofstream registW("banco_registradores.txt");
    for (const auto& l : linhas) 
    {
        registW << l << endl;
    }
    registW.close();

    cout << "SUB" << endl;    
}

void orReg(string destino, string origem1, string origem2)
{
    string v1 = lerValorRegistrador(origem1);
    string v2 = lerValorRegistrador(origem2);

    int val1 = stoi(v1);
    int val2 = stoi(v2);

    int resultado = val1 | val2;
    ultimoValor = resultado; 

    ifstream registR("banco_registradores.txt");
    vector <string> linhas;
    string linha;

    while(getline(registR, linha))
    {
        linhas.push_back(linha);
    }

    registR.close();

    for(size_t i = 0; i < linhas.size(); i++)
    {
        istringstream iss(linhas[i]);
        string reg;
        getline(iss, reg, ':');

        if (reg == destino) 
        {
            linhas[i] = destino + ": " + to_string(resultado);
        }
    }

    ofstream registW("banco_registradores.txt");
    for (const auto& l : linhas) 
    {
        registW << l << endl;
    }
    registW.close();

    cout << "OR" << endl;    
}

void andReg(string destino, string origem1, string origem2)
{
    string v1 = lerValorRegistrador(origem1);
    string v2 = lerValorRegistrador(origem2);

    int val1 = stoi(v1);
    int val2 = stoi(v2);

    int resultado = val1 & val2;
    ultimoValor = resultado; 

    ifstream registR("banco_registradores.txt");
    vector <string> linhas;
    string linha;

    while(getline(registR, linha))
    {
        linhas.push_back(linha);
    }

    registR.close();

    for(size_t i = 0; i < linhas.size(); i++)
    {
        istringstream iss(linhas[i]);
        string reg;
        getline(iss, reg, ':');

        if (reg == destino) 
        {
            linhas[i] = destino + ": " + to_string(resultado);
        }
    }

    ofstream registW("banco_registradores.txt");
    for (const auto& l : linhas) 
    {
        registW << l << endl;
    }
    registW.close();

    cout << "AND" << endl;    
}

void unicadeC(int PC, string instr, string valor1, string valor2, string valor3) 
{
    ofstream unicadeControle("unicade_controle.txt", ios::app);
    if (unicadeControle.is_open())
    {
        unicadeControle << "PC: " << PC << " | IR: " << instr << " " <<  valor1 << " " <<  valor2 << " " <<  valor3 << endl;
    } else {
        cout << "Erro ao abrir o arquivo de entrada" << endl;
    }
    unicadeControle.close();
    
}

void executar(string instr, string valor1, string valor2, string valor3)
{
    
    if (instr == "LOAD")
    {
        registradores(valor1, valor2);
        cout << "LOAD" << endl;
    }
    if (instr == "STORE")
    {
        string valor = lerValorRegistrador(valor1);
        
        ifstream memoriaR("memoria_ram.txt");
        vector <string> linhas;
        string linha;

        while(getline(memoriaR, linha))
        {
            linhas.push_back(linha);
        }

        memoriaR.close();

        int pos = stoi(valor2);
        if(pos > 0 && pos <= (int)linhas.size())
        {
            linhas[pos - 1] = valor;
        }
        else if(pos > (int)linhas.size())
        {
            linhas.resize(pos, "");
            linhas[pos - 1] = valor;
        }

        ofstream memoriaW("memoria_ram.txt");
        for(const auto& line : linhas)
        {
            memoriaW << line << endl;
        }

        cout << "STORE" << endl;
    }
    if  (instr == "MOVE" )
    {
        moveRegis(valor1, valor2);
        cout << "MOVE" << endl;
    }
    if (instr == "ADD")
    {
        add(valor1, valor2, valor3);
    }
    if (instr == "SUB")
    {
        sub(valor1, valor2, valor3);
    }
    if (instr == "OR")
    {
        orReg(valor1, valor2, valor3);
    }
    if (instr == "AND")
    {
        andReg(valor1, valor2, valor3);
    }
}



void arqOpen() {
    ifstream arqEntrada("entrada.txt");
    vector<string> programa;
    string linha;
    if (arqEntrada.is_open())
    {
        while (getline(arqEntrada, linha))
        {
            programa.push_back(linha);
        }
        arqEntrada.close();
    } else {
        cout << "Erro ao abrir o arquivo para leitura!!!" << endl;
    }

    int PC = 0;
    while (PC < (int)programa.size())
    {
        istringstream text(programa[PC]);
        string instr , valor1, valor2, valor3;
        text >> instr >> valor1 >> valor2 >> valor3;
        unicadeC(PC, instr, valor1, valor2, valor3);

        if (instr == "HALT")
        {
            cout << "HALT" << endl;
            break;
        }
        else if (instr == "BRANCH")
        {   
            PC = stoi(valor1);
            cout << "BRANCH" << endl;
            continue;
        }
        else if (instr == "BNEG") 
        {
            if (ultimoValor < 0) {
                PC = stoi(valor1);
                cout << "BNEG" << endl;
                continue;
            }
            else
            {
                cout << "BNEG" << endl;
                PC++;
            }
            continue;
        }
        else if (instr == "BZERO") 
        {
            if (ultimoValor == 0) {
                PC = stoi(valor1);
                cout << "BZERO" << endl;
                continue;
            }
            else
            {
                PC++;
                cout << "BZERO" << endl;
            }
            continue;
        }
        else
        {
            executar(instr, valor1, valor2, valor3);
            PC++;
        }
    }
}

void iniciarReg()
{
    ofstream initR("banco_registradores.txt");
    if (initR.is_open())
    {
        for (int i = 0; i <=3; i++)
        {
            initR << "R" << i << ": " << 0 << endl;

        }
    }
    else
    {
        cout << "Erro ao abrir o arquivo!!!" << endl;
    }
    
    initR.close();
}

int main ()
{
    iniciarReg();

    ofstream arquivo("unicade_controle.txt");
    arquivo.close();
    
    arqOpen();
}