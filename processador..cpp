#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void arqOpen() {
    ifstream arquiv("entrada.txt");

    if (arquiv.is_open())
    {
        string linha;
        while (getline(arquiv, linha))
        {
            istringstream text(linha);
            string instr, valor1, valor2, valor3;
            
            text >> instr >> valor1 >> valor2 >> valor3;
            executar(instr, valor1, valor2, valor3);
        }
    } else {
        cout << "Erro ao abrir o arquivo de entrada" << endl;
    }
    
}

string unicadeC() 
{

}

int memoriaM()
{

}

int registradores() 
{

}

void executar(string instr, string valor1, string valor2, string valor3)
{
    if (instr == "LOAD")
    {
        
    }
    if else (instr == "STORE" )
    {

    }
    if else (instr == "MOVE" )
    {

    }
 
}

int main ()
{
    
}