#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Autobuz {
private:
    //atributele clasei definite in zona privata
    static int nrAutobuze;
    const int idAutobuz;
    int capacitate;
    int nrPersoaneImbarcate;
    char* producator;

public:
    //constructor fara parametri
    Autobuz() : idAutobuz(++nrAutobuze) {
        this->capacitate = 0;
        this->nrPersoaneImbarcate = 0;
        this->producator = nullptr;
    }

    //constructor cu parametri
    Autobuz(int capacitate, int nrPersoaneImbarcate, const char* producator) : idAutobuz(++nrAutobuze) {
        if (capacitate > 0) {
            this->capacitate = capacitate;
        }
        else {
            this->capacitate = 0;
        }

        if (nrPersoaneImbarcate <= capacitate) {
            this->nrPersoaneImbarcate = nrPersoaneImbarcate;
        }
        else {
            this->nrPersoaneImbarcate = capacitate; 
        }

        if (producator != nullptr) {
            this->producator = new char[strlen(producator) + 1];
            strcpy(this->producator, producator);
        }
        else {
            this->producator = nullptr;
        }
    }

    //constructor de copiere
    Autobuz(const Autobuz& alt) : idAutobuz(++nrAutobuze) {
        this->capacitate = alt.capacitate;
        this->nrPersoaneImbarcate = alt.nrPersoaneImbarcate;

        if (alt.producator != nullptr) {
            this->producator = new char[strlen(alt.producator) + 1];
            strcpy(this->producator, alt.producator);
        }
        else {
            this->producator = nullptr;
        }
    }

    //destructor
    ~Autobuz() {
        if (this->producator != nullptr) {
            delete[] this->producator;
        }
    }

    //operatorul=
    Autobuz& operator=(const Autobuz& alt) {
        if (this != &alt) { 
            this->capacitate = alt.capacitate;
            this->nrPersoaneImbarcate = alt.nrPersoaneImbarcate;

            if (this->producator != nullptr) {
                delete[] this->producator;
            }
            if (alt.producator != nullptr) {
                this->producator = new char[strlen(alt.producator) + 1];
                strcpy(this->producator, alt.producator);
            }
            else {
                this->producator = nullptr;
            }
        }
        return *this;
    }

    //get si set pt 2 atribute: capacitate si producator
    int getCapacitate() const {
        return this->capacitate;
    }

    void setCapacitate(int capacitate) {
        if (capacitate > 0) {
            this->capacitate = capacitate;
        }
    }

    const char* getProducator() const {
        return this->producator;
    }

    void setProducator(const char* producator) {
        if (this->producator != nullptr) {
            delete[] this->producator;
        }
        if (producator != nullptr) {
            this->producator = new char[strlen(producator) + 1];
            strcpy(this->producator, producator);
        }
        else {
            this->producator = nullptr;
        }
    }

    //operatorr<<
    friend ostream& operator<<(ostream& out, const Autobuz& a) {
        out << a.idAutobuz << "; Capacitate: " << a.capacitate
            << "; Nr. persoane imbarcate: " << a.nrPersoaneImbarcate
            << "; Producator: " << (a.producator ? a.producator : "Necunoscut") << "; ";
        return out;
    }

    //metoda getNumarLocuriLibere()
    int getNumarLocuriLibere() const {
        return this->capacitate - this->nrPersoaneImbarcate;
    }

    //operator cast la int
    operator int() const {
        return this->nrPersoaneImbarcate;
    }

    //operator> 
    bool operator>(const Autobuz& alt) const {
        return this->capacitate > alt.capacitate;
    }
};

int Autobuz::nrAutobuze = 0;

int main() {
    //testam constructori
    Autobuz a1;
    Autobuz a2(50, 30, "Mercedes");
    Autobuz a3 = a2;

    //testam operator=
    a1 = a2;
    cout << "Autobuz 1: " << a1 << endl;
    cout << "Autobuz 2: " << a2 << endl;

    //testam set
    a1.setCapacitate(60);
    a1.setProducator("Volvo");
    cout << "Autobuz 1 dupa modificare: " << a1 << endl;

    //testam metoda getNumarLocuriLibere()
    cout << "Numar locuri libere Autobuz 1: " << a1.getNumarLocuriLibere() << endl;

    //testam operator cast la int
    int nrPersoane = static_cast<int>(a2);
    cout << "Numar persoane in Autobuz 2: " << nrPersoane << endl;

    //testam operator>
    if (a1 > a2) {
        cout << "Autobuz 1 are capacitate mai mare decat Autobuz 2." << endl;
    }
    else {
        cout << "Autobuz 2 are capacitate mai mare sau egala cu Autobuz 1." << endl;
    }

    return 0;
}

