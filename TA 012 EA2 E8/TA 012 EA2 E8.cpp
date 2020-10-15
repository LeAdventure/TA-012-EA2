#include <iostream>
#include <regex>
#include <string>
#include <cstring>

using namespace std;

//13478ts13478ststsebastiansebastian - 34 - Valido

int main(){
    regex e("13478(ts)+13478(st)+sebastiansebastian");
    int cont1 = 0, cont2 = 0, i = 0;
    std::string str, c;
    do{
        cout << "Ingrese una cadena de caracteres: ";
        fflush(stdin);
        getline(cin, str);
        fflush(stdin);
        bool match = regex_match(str, e);
    
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
                cout << "i=" << i << endl;
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

    } while (c == "S");
    
    return 0;
}

/*
        cout << endl << j << endl;
        cout << endl << i << endl;
        cout << endl << cont1 << endl;
        cout << endl << cont2 << endl;
*/


