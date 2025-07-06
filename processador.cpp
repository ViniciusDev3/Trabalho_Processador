#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void registradores( string x, string y) 
{
    string m;
    ofstream regist("banco_registradores.txt");
    if (regist.is_open())
    {
        // Ta puxando da memoria ram o valor para registra nos registradores R0, R1, R2 e R3
        ifstream memoriaR("memoria_ram.txt");
        if (memoriaR.is_open())
        {
            int cont = 0;
            string linhaR;
            while (getline(memoriaR, linhaR))
            {
                cont++;
                if (cont == stoi(y))
                {
                    istringstream textR(linhaR);
                    textR >> m;
                }
            }
            regist << x << ": " << m;
        } else {
            cout << "Erro ao abrir o arquivo de entrada" << endl;
        }
        memoriaR.close();
    } else {
        cout << "Erro ao abrir o arquivo de entrada" << endl;
    }
    regist.close();
    
}

void unicadeC(string instr, string valor1, string valor2, string valor3) 
{
    ofstream unicadeControle("unicade_controle.txt");
    if (unicadeControle.is_open())
    {
        unicadeControle << instr << " " <<  valor1 << " " <<  valor2 << " " <<  valor3;
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
        cout << "foi";
    }
    /*
    if else (instr == "STORE" )
    {

    }
    if else (instr == "MOVE" )
    {

    }
    */
}

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
            unicadeC(instr, valor1, valor2, valor3);
            executar(instr, valor1, valor2, valor3);

        }
    } else {
        cout << "Erro ao abrir o arquivo de entrada" << endl;
    }
    
}


/*
int memoriaM()
{

}
*/

int main ()
{
    arqOpen();
}