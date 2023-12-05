#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


    struct Aktien {

        char isin;
        char name_aktien;
        int aktienkaeufe_verkaeufe;
        int aktienkurs_kauf_verkauf;
        float jahresdividende;
        char kaufdatum_verkaufdatum_aktien;
        char kaeufer_verkaeuefer_aktien;
   
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
void dividendenrendite(float akt_aktienkurs, float akt_dividende){

    float div_in_prozent = (akt_dividende / akt_aktienkurs) * 100;
    printf("Die Dividendenrendite betraegt in Prozent: %.2f", div_in_prozent);

}
//Aufgabe 3.) CSV-Datei zeilenweise einlesen mit verschiedenen Datentypen
//Vereint mehrere Datentypen in einem
union data{

    char isin;
    char name_aktien;
    int aktienkaeufe_verkaeufe;
    int aktienkurs_kauf_verkauf;
    float jahresdividende;
    char kaufdatum_verkaufdatum_aktien;
    char kaeufer_verkaeuefer_aktien;

};

void schreibeCSV(FILE* stocks, union data* data){
    for(int i = 0; i < sizeof(data); i++){
        fprintf(stocks, "%s, %s, %d, %d, %f, %s, %s", data[i].isin, data[i].name_aktien, 
            data[i].aktienkaeufe_verkaeufe, data[i].aktienkurs_kauf_verkauf, 
            data[i].jahresdividende, data[i].kaufdatum_verkaufdatum_aktien, 
            data[i].kaeufer_verkaeuefer_aktien);    
    }
    printf("\nGlückwunsch! Deine Daten wurden in Deine Datei geschrieben.");


}



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

    //Gibt die Größe des Arrays zurück
    int n = sizeof(Feld) / sizeof(Feld[0]); // Für Feld

    //Sortierung der im Feld stehenden Elemente
    bubblesort(Feld, n);

    //Aufgabe 3.) CSV-Datei zeilenweise einlesen
    FILE* stocks_pfeil = fopen("stocks.txt","w");

    //Prüfung ob stocks geöffnet wurde
    if(stocks_pfeil == NULL){
        printf("Konnte Datei nicht öffnen.");
        return 0;


    }


    int n_csv = sizeof(stocks) / sizeof(stocks[0]); //Für CSV
    char antwort;
    char erweitern;
    

    printf("Willst Du etwas in eine Datei schreiben: (J)a oder (N)ein?");
        if(antwort == "J"){
            schreibeCSV(stocks, n_csv);
            
        }else if(antwort == "N"){
            printf("\nOk.");

        }else
            printf("\nBitte nur gültige Werte eingeben!");

        printf("\nWillst Du Deine Datei erweitern: (J)a oder (N)ein?");
            if(erweitern == "J"){
                 FILE* stocks = fopen("stocks.txt","a");
            }else
                printf("\nOk.");


    printf("\nEXTRA:-----------------------------------\n");
    printf("------Berechnung Dividendenrendite------\n");
    
    float akt_aktienkurs, akt_jahresdividende;

    printf("\nBitte gib den Aktienkurs an: ");
    scanf("%f", &akt_aktienkurs);

    printf("\nBitte gib die Jahresdividende an: ");
    scanf("%f", &akt_jahresdividende);

    dividendenrendite(akt_aktienkurs, akt_jahresdividende);



    return 0;







}