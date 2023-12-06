#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


    /* struct Aktien {

        char isin;
        char name_aktien;
        int aktienkaeufe_verkaeufe;
        int aktienkurs_kauf_verkauf;
        float jahresdividende;
        char kaufdatum_verkaufdatum_aktien;
        char kaeufer_verkaeuefer_aktien;
   
    };
    */
    
    //Erstellt ein Alias für das Struct um so nicht erneut das Struct auflisten zu müssen
    //typedef struct Aktien aktien;


//Aufgabe 2.) Funktion-Dividendenrendite
void dividendenrendite(float akt_aktienkurs, float akt_dividende){

    float div_in_prozent = (akt_dividende / akt_aktienkurs) * 100;
    printf("Die Dividendenrendite betraegt in Prozent: %.2f", div_in_prozent);

}
//Aufgabe 3.) CSV-Datei zeilenweise einlesen mit verschiedenen Datentypen
//Vereint mehrere Datentypen in einem
typedef union data{

    char isin[20];
    char name_aktien[20];
    int aktienkaeufe_verkaeufe;
    int aktienkurs_kauf_verkauf;
    float jahresdividende;
    char kaufdatum_verkaufdatum_aktien[20];
    char kaeufer_verkaeuefer_aktien[20];

}data;


//Aufgabe 1
    void bubblesort(data stocks[], int n){
        int i, j;

        data temp;

        for(i = 0; i < n - 1; i++){
            for(j = i + 1; j < n; j++){
                if(strcmp(stocks[i].name_aktien, stocks[j].name_aktien) > 0){
                    temp = stocks[j];
                    stocks[i] = stocks[i];
                    stocks[j] = temp;

                }


            }

        }

    }

//sizeof(data) gibt die größe des gesamten Union zurück

void schreibeCSV(FILE* datei, data* data){
    for(int i = 0; i < sizeof(data); i++){
        fprintf(datei, "%s, %s, %d, %d, %f, %s, %s\n", 
            data[i].isin, data[i].name_aktien, 
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


    //Bezieht sich auf das union data Aktien
    data stocks[] = {

        {"DE000BASF111", "BASF AG", 100, 42, 3.30, "20.10.2023", "Klaus"},
        {"DE000BASF111", "BASF AG", -20, 50, 3.30, "03.11.2023", "Klaus"},
        {"US1912161007", "Coca Cola Co.", 50, 44, 3.30, "05.11.2023", "Sonja"},
        {"US0378331005", "Apple Inc.", 10, 163, 0.91, "02.11.2023", "Benno"}

    };

    
    char antwort = toupper(antwort);

    
    //Aufgabe 3.) CSV-Datei zeilenweise einlesen
    FILE* stocks_file = fopen("stocks.txt","w");

    //Prüfung ob Datei leer
    if(stocks_file == NULL){
        printf("Konnte Datei nicht öffnen.");
        return 0;
        
    }    

while(1){

    printf("Bitte auswählen: (1) Schreiben in Datei\t(2) nicht schreiben\t(3) Erweitern\t(4) Aktieninformationen auflisten\t(5) EXTRA: Dividendenrendite berechnen\t(6) Beenden\n");
    scanf(" %c", &antwort); //Das Leerzeichen bei " %c" überspringt Whitespaces

    if(antwort == '1'){

        schreibeCSV(stocks_file, stocks);
        fclose(stocks_file);

    }else if(antwort == '2'){
        printf("Ok.\n");
        
    }
    else if(antwort == '3'){
        FILE* stocks_file = fopen("stocks.txt","a");
        schreibeCSV(stocks_file, stocks);
        fclose(stocks_file);

    }else if(antwort == '4'){
        printf("------Aktieninformationen------\n");

                
         //Gibt die Größe des Arrays zurück
        int n = sizeof(stocks) / sizeof(stocks[0]); // Für Feld

        for(int i = 0; i < n; i++){

        printf("ISIN: %s", stocks[i].isin);
        printf("Unternehmen: %s", stocks[i].name_aktien); 
        printf("Anteile im Besitz: %d", stocks[i].aktienkaeufe_verkaeufe);  
        printf("Aktienkurs: %d", stocks[i].aktienkurs_kauf_verkauf); 
        printf("Jahresdividende: %f", stocks[i].jahresdividende);
        printf("Kaufdatum/Verkaufdatum: %s", stocks[i].kaufdatum_verkaufdatum_aktien);
        printf("Kaeufer/Verkaeufer: %s", stocks[i].kaeufer_verkaeuefer_aktien);
    
        }

        printf("Sortierte Aktienfolge nach Namen:\n");
        bubblesort(stocks, n);


    }else if(antwort == '5'){

        printf("\nEXTRA:-----------------------------------\n");
        printf("------Berechnung Dividendenrendite------\n");

        float akt_aktienkurs, akt_jahresdividende;

        printf("\nBitte gib den Aktienkurs an: ");
        scanf("%f", &akt_aktienkurs);

        printf("\nBitte gib die Jahresdividende an: ");
        scanf("%f", &akt_jahresdividende);

        dividendenrendite(akt_aktienkurs, akt_jahresdividende);


    }else if(antwort == '6'){
        printf("Beendet.");
    }
    
    else

        printf("\nBitte nur gueltige Werte eingeben!");

}

    return 0;







}