#include <iostream>
#include <regex>
#include <string>
#include <cstring>
#include <thread> 
#include <chrono>
#include <locale.h>
using namespace std;

//13478ts13478ststsebastiansebastian - 34 - Valido
//13478tsts13478ststsebastiansebastian - Invalido - No cumple (w)^(n)
//13478tsts13478stststsebastiansebastian - Invalido - No cumple (w^(-1))^(2n)
//13478tsts13478ststststsebastiansebastian - Valido 
//13478tstststststststststs13478ststststststststststststststststststststsebastiansebastian - Valido

int main(){
    setlocale(LC_ALL, "");
    regex e("13478(ts)+13478(st)+sebastiansebastian"); //Validor
    int cont1 = 0, cont2 = 0, i = 0;
    std::string str, c;

    cout << "Tarea - 1" << endl;
    cout << "Miembros: " << endl;
    cout << "Jose Maria Flores San Martin\t\t -\t1859565" << endl;
    cout << "Miguel Eduardo Barragan Elizondo\t -\t1859404" << endl;
    cout << "Sebastian Terrazas Santillana\t\t -\t1847317" << endl;
    for (int i = 4; i > 0; --i) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    system("cls");
    fflush(stdin);

    do{
        system("cls");
        cout << "Nombre usado: Sebastian Terrazas Santillana \tMatricula: 1847317" << endl;
        cout << "i = 13478" << endl;
        cout << "j = sebastian" << endl;
        cout << "w = ts" << endl;
        cout << "w^(-1) = st" << endl << endl;

        cout << "L = { i(w)^(n)i(w^(-1))^(2n)(j)^(2) donde n>=1}" << endl;
        cout << "Ejemplo mas basico - 13478ts13478ststsebastiansebastian" << endl << endl;

        cout << "Ingrese una cadena de caracteres: ";
        fflush(stdin);
        getline(cin, str);
        fflush(stdin);
        bool match = regex_match(str, e); //Validacion 
    
        //Poner la string en un array char
        char *cstr = new char[str.size() + 1];
        str.copy(cstr, str.size() + 1);
        cstr[str.size()] = '\0';
        int j = str.size();

        if (match == true){
            for (i = 5; i < j; i=i+2) {
                if (cstr[i + 2] == '1') {
                    cont1++;
                    break;
                }else{
                    cont1++;
                }
            }
            for (i = (cont1*2) + 10; i < j; i = i + 2) {
                if (cstr[i + 3] == 'e') {
                    cont2++;
                    break;
                }else {
                    cont2++;
                }
            }
            if ((cont1 * 2) != cont2) 
                cout << "Caso Invalido" << endl << endl;
            else 
                cout << "Caso Valido" << endl << endl;
        }else{
            cout << "Caso Invalido" << endl << endl;
        }
        do {
            cout.flush();
            cout << "¿Desea introducir otra cadena? [S/N]" << endl;
            fflush(stdin);
            getline(cin, c);
            c[0] = toupper(c[0]);
            if (c != "S" && c != "N") {
                cout << "Por favor, ingrese una respuesta valida" << endl << endl;
            }
        }while (c != "S" && c != "N");
        cont1 = 0, cont2 = 0;
    } while (c == "S");
    
    return 0;
}
