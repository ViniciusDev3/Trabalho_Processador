#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

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

int contPC = 0;
void unicadeC(string instr, string valor1, string valor2, string valor3) 
{
    ofstream unicadeControle("unicade_controle.txt", ios::app);
    if (unicadeControle.is_open())
    {
        unicadeControle << "PC: " << contPC << " | IR: " << instr << " " <<  valor1 << " " <<  valor2 << " " <<  valor3 << endl;
        contPC++;
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
    bool operando = true;
    while ( operando && PC < (int)programa.size())
    {
        istringstream text(programa[PC]);
        string instr = "", valor1, valor2, valor3;
        text >> instr >> valor1 >> valor2 >> valor3;
        
        if (instr == "HALT")
        {
            unicadeC(instr, valor1, valor2, valor3);
            operando = false;
            cout << "HALT" << endl;
            break;
        }
        if (instr == "BRANCH")
        {   
            contPC = stoi(valor1);
            unicadeC(instr, valor1, valor2, valor3);
            PC = stoi(valor1);
            cout << "BRANCH" << endl;
        } 
        if (instr != "HALT" && instr != "BRANCH" && operando != false)
        {
            unicadeC(instr, valor1, valor2, valor3);
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