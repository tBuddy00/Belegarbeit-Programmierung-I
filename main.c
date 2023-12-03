#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


    struct Aktien {

        char isin[20];
        char name_aktien[20];
        int aktienkaeufe_verkaeufe[20];
        int aktienkurs_kauf_verkauf[20];
        float jahresdividende[20];
        char kaufdatum_verkaufdatum_aktien[20];
        char kaeufer_verkaeuefer_aktien[20];
   
    };

    
    //Erstellt ein Alias für das Struct um so nicht erneut das Struct auflisten zu müssen
    typedef struct Aktien aktien;

//Aufgabe 1
    void bubblesort(aktien Feld[], int n){
        int i, j;

        aktien temp;

        for(i = 0; i < n - 1; i++){
            for(j = i + 1; j < n; j++){
                if(strcmp(Feld[i].name_aktien, Feld[j].name_aktien) > 0){
                    temp = Feld[i];
                    Feld[i] = Feld[i];
                    Feld[j] = temp;

                }


            }

        }

    }

//Aufgabe 2.) Funktion-Dividendenrendite



//Aufgabe 3.) CSV-Datei zeilenweise einlesen



//Aufgabe 4.) Ermittlung durchschnittliche Stückzahl aller getätigten Käufe



//Aufgabe 5.) Auflistung Aktien mit größter Jahresdividende





//Man schreibt void in die Klammern von main, um anzugeben das die Funktion "main" keinen Wert und Argumente akzeptiert
int main(void){


    //Bezieht sich auf das Struct Aktien
    aktien Feld[] = {

        {"DE000BASF111", "BASF AG", 100, 42, 3.30, "20.10.2023", "Klaus"},
        {"DE000BASF111", "BASF AG", -20, 50, 3.30, "03.11.2023", "Klaus"},
        {"US1912161007", "Coca Cola Co.", 50, 44, 3.30, "05.11.2023", "Sonja"},
        {"US0378331005", "Apple Inc.", 10, 163, 0.91, "02.11.2023", "Benno"}

    };

    int n = sizeof(Feld) / sizeof(Feld[0]);



    bubblesort(Feld, n);



    return 0;







}