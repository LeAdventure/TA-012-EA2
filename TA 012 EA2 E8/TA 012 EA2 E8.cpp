#include <iostream>
#include <regex>
#include <string>
#include <string_view>
#include <cstring>
#include <locale>

using namespace std;

//13478ts13478ststsebastiansebastian - 34 - Valido

string readString() {
    string str;
    cout << "Ingrese una cadena de caracteres: ";
    fflush(stdin);
    getline(cin, str);
    fflush(stdin);
    return str;
}

int countRange(const string_view substr, const string str, const int start, const int end) {
    int count = -1;
    int pos = start - 1;
    do {
        pos = str.find(substr, pos + 1);
        count++;
    } while (pos != -1 && pos < end);
    return count;
}

int main(){
    setlocale(LC_ALL, "");
    regex e("13478(ts)+13478(st)+sebastiansebastian");
    int count1 = 0, count2 = 0;
    std::string str, cont_exec;
    bool valid = false;
    do {
        valid = false;
        str = readString();
        bool match = regex_match(str, e);

        if ( match ) {
            int pos = 0;
            int end_1 = str.find("13478"sv, 5);
            int end_2 = str.find("sebastiansebastian"sv, 5);
            

            count1 = countRange("ts"sv, str, 0, end_1);
            count2 = countRange("st"sv, str, end_1, end_2);
           
            valid = 2 * count1 == count2;
        } 

        if ( valid ) {
            cout << "Caso Valido"sv << endl << endl;
        } else {
            cout << "Caso Invalido"sv << endl << endl;
        }

        do {
            cout.flush();
            cout << "¿Desea introducir otra cadena? [S/N]"sv << endl;
            fflush(stdin);
            getline(cin, cont_exec);
            cont_exec[0] = toupper(cont_exec[0]);
            if (cont_exec != "S" && cont_exec != "N") {
                cout << "Por favor, ingrese una respuesta valida"sv << endl << endl;
            }
        } while (cont_exec != "S" && cont_exec != "N");

    } while (cont_exec == "S");
    
    return 0;
}

