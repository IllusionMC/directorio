#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct DataName {
    string Nombre;
    string Telefono[10];
    string CorpInfo;
    int Index;
};

struct DataVerify {
    string Nombre;
    string Telefono[10];
    string CorpInfo;
    int Index;
};

vector<DataName> DataCreation() {
    vector<DataName> Data;
    for (int i = 0; i < 10; i++) {
        DataName Info;
        // Generar un nombre aleatorio
        string nombres[] = {"Juan", "Maria", "Pedro", "Ana", "Luis", "Laura", "Carlos", "Sofia", "Diego", "Valeria"};
        int randomIndex = rand() % 10;
        Info.Nombre = nombres[randomIndex];

        // Generar un número de teléfono aleatorio
        Info.Telefono[i] = "555-" + to_string(rand() % 10000);

        // Generar una compañía aleatoria
        string companias[] = {"Google", "Microsoft", "Apple", "Amazon", "Facebook", "Netflix", "Tesla", "Intel", "IBM", "Oracle"};
        randomIndex = rand() % 10;
        Info.CorpInfo = companias[randomIndex];

        Info.Index = i; // Asignar valor de índice
        Data.push_back(Info);
    }
    return Data;
}

void DataMV(vector<DataName>& Data, vector<DataVerify>& Verification) {
    int index;
    cout << "Ingrese el índice del contacto a modificar: ";
    cin >> index;
    cin.ignore();
    if (index >= 0 && index < Data.size()) {
        cout << "Ingrese el nuevo nombre del contacto " << index + 1 << ": ";
        getline(cin, Data[index].Nombre);
        cout << "Ingrese el nuevo número de teléfono del contacto " << index + 1 << ": ";
        getline(cin, Data[index].Telefono[index]);
        cout << "Ingrese el nuevo nombre de la compañía del contacto " << index + 1 << ": ";
        getline(cin, Data[index].CorpInfo);
        cout << "Contacto modificado exitosamente." << endl;
        cout << "Datos ingresados:" << endl;
        cout << "Nombre: " << Data[index].Nombre << endl;
        cout << "Teléfono: " << Data[index].Telefono[index] << endl;
        cout << "Compañía: " << Data[index].CorpInfo << endl;
        char choice;
        do {
            cout << "¿Los datos ingresados son correctos? (S/N): ";
            cin >> choice;
            cin.ignore();
        } while (choice != 'S' && choice != 's');
        Verification[index].Nombre = Data[index].Nombre;
        Verification[index].Telefono[index] = Data[index].Telefono[index];
        Verification[index].CorpInfo = Data[index].CorpInfo;
        Verification[index].Index = Data[index].Index;
    } else {
        cout << "El contacto no existe." << endl;
    }
}

void DataErase(vector<DataName>& Data, int index) {
    if (index >= 0 && index < Data.size()) {
        char choice;
        cout << "¿Está seguro que desea eliminar el contacto " << index + 1 << "? (S/N): ";
        cin >> choice;
        cin.ignore();
        if (choice == 'S' || choice == 's') {
            Data.erase(Data.begin() + index);
            cout << "Contacto eliminado exitosamente." << endl;
        } else {
            cout << "Operación cancelada." << endl;
        }
    } else {
        cout << "El contacto no existe." << endl;
    }
}

int main() {
    srand(time(0)); // Inicializar la semilla para generar números aleatorios
    char EndChoice;
    vector<DataName> Data = DataCreation();
    vector<DataVerify> Verification;
    
    // Imprimir lista de contactos al iniciar el programa
    cout << "Lista de contactos al iniciar el programa:" << endl;
    for (const auto& Info : Data) {
        cout << "Nombre: " << Info.Nombre << endl;
        cout << "Teléfono: " << Info.Telefono[Info.Index] << endl;
        cout << "Compañía: " << Info.CorpInfo << endl;
        cout << "-------------------------"<< endl;
    }
    
    do {
        for (const auto& Info : Data) {
            cout << "Nombre: " << Info.Nombre << endl;
            cout << "Teléfono: " << Info.Telefono[Info.Index] << endl;
            cout << "Compañía: " << Info.CorpInfo << endl;
            cout << "-------------------------"<< endl;
        }
        char choice;
        cout << "¿Desea ejecutar alguna acción adicional? (S/N): ";
        cin >> choice;
        cin.ignore();
        if (choice == 'S' || choice == 's') {
            cout << "¿Desea modificar los contactos? (S/N): ";
            cin >> choice;
            cin.ignore();
            if (choice == 'S' || choice == 's') {
                DataMV(Data, Verification);
            }
            cout << "¿Desea eliminar un contacto? (S/N): ";
            cin >> choice;
            cin.ignore();
            if (choice == 'S' || choice == 's') {
                int index;
                cout << "Ingrese el índice del contacto a eliminar: ";
                cin >> index;
                DataErase(Data, index);
            }
        }
        cout << "¿Desea terminar el programa? (S/N): ";
        cin >> EndChoice;
        cin.ignore();
    } while (EndChoice != 'S' && EndChoice != 's');
    
    // Imprimir lista de contactos al terminar el programa
    cout << "Lista de contactos al terminar el programa:" << endl;
    for (const auto& Info : Data) {
        cout << "Nombre: " << Info.Nombre << endl;
        cout << "Teléfono: " << Info.Telefono[Info.Index] << endl;
        cout << "Compañía: " << Info.CorpInfo << endl;
        cout << "-------------------------" << endl;
    }
    
    return 0;
}
