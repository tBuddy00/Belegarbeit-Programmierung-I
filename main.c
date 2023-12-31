#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STOCKS 100

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
        printf("Die Dividendenrendite betraegt in Prozent: %.2f\n", div_in_prozent);

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

typedef struct {
    data stocks[MAX_STOCKS] //Maximal 100 Aktien können im Array gespeichert werden
}StockContainer;


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
    printf("\nGlueckwunsch! Deine Daten wurden in Deine Datei geschrieben.\n");


}


//Aufgabe 4.) Ermittlung durchschnittliche Stückzahl aller getätigten Käufe
//gesamtzahl_kaeufe_verkaeufe = n; summe_aus_kaeufe_verkaeufe = Summe aus x1 + x2 +..+ xn;
 
void durchschnStueckzahl(int gesamtzahl_kaeufe_verkaeufe, int summe_aus_kaeufe_verkaeufe){
    float arithm = (summe_aus_kaeufe_verkaeufe / gesamtzahl_kaeufe_verkaeufe);
    printf("\nDas arithmetische Mittel deiner Kaeufe/Verkaeufe betraegt: %.2f\n", arithm);
}

/*
//Aufgabe 5.) Auflistung der drei Aktien mit der größter Jahresdividende
void groeßte_Jahresdividende(){
    for(int i = 0; i < data.sizeof(stockContainer); i++){
        if(stockContainer.jahresdividende < 3.10){
            printf("Das Unternehmen hat eine geringere Jahresdividende: %c -> Jahresdividende: %.2f", stockContainer.name_aktien, stockContainer.jahresdividende);
        }else
            printf("Jahresdividende der drei groeßten Unternehmen: \n", stockContainer.jahresdividende);

    }

}
*/


//Man schreibt void in die Klammern von main, um anzugeben das die Funktion "main" keinen Wert und Argumente akzeptiert
int main(void){


    //Bezieht sich auf das union Aktien
    StockContainer stockContainer[] = {     
        
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
        printf("\nKonnte Datei nicht öffnen.\n");
        return 0;
        
    }    

while(1){

    printf("\n-----------------------------------Bitte auswaehlen-----------------------------------\n\n(1) Schreiben in Datei\t(2) nicht schreiben\t(3) Erweitern\t(4) Aktieninformationen auflisten\t(5) Dividendenrendite berechnen\t(6) Durchschnitt Aktienkaeufe/Verkaeufe berechnen\t(7) Ausgabe der groeßten Jahresdividende\t(8) Beenden");
    scanf(" %c", &antwort); //Das Leerzeichen bei " %c" überspringt Whitespaces

    if(antwort == '1'){
        //FUNKTIONIERT NOCH NICHT GANZ: FEHLERHAFTE WERTE
        schreibeCSV(stocks_file, stockContainer);
        fclose(stocks_file);

    }else if(antwort == '2'){
        printf("Ok.\n");
        
    }
    else if(antwort == '3'){
        FILE* stocks_file = fopen("stocks.txt","a");
        schreibeCSV(stocks_file, stockContainer);
        fclose(stocks_file);

    }else if(antwort == '4'){
        printf("\n------Aktieninformationen------\n");

                
         //Gibt die Größe des Arrays zurück
        int n = sizeof(stockContainer) / sizeof(stockContainer[0].stocks); // Für Feld

        //FUNKTIONIERT NOCH NICHT GANZ, GIBT MEHR ALS NÖTIG AUS UND FALSCHE INFORMATIONEN AN DER FALSCHER STELLE
        for(int i = 0; i < n; i++){

        printf("\nISIN: %s\n", stockContainer[i].stocks[i].isin);
        printf("\nUnternehmen: %s\n", stockContainer[i].stocks[i].name_aktien); 
        printf("\nAnteile im Besitz: %d\n", stockContainer[i].stocks[i].aktienkaeufe_verkaeufe);  
        printf("\nAktienkurs: %d\n", stockContainer[i].stocks[i].aktienkurs_kauf_verkauf); 
        printf("\nJahresdividende: %f\n", stockContainer[i].stocks[i].jahresdividende);
        printf("\nKaufdatum/Verkaufdatum: %s\n", stockContainer[i].stocks[i].kaufdatum_verkaufdatum_aktien);
        printf("\nKaeufer/Verkaeufer: %s\n", stockContainer[i].stocks[i].kaeufer_verkaeuefer_aktien);
    
        }

        printf("\n\n------Sortierte Aktienfolge nach Namen------\n");
        bubblesort(stockContainer, n);
    
    
    }else if(antwort == '5'){

        printf("------Berechnung Dividendenrendite------\n");

        float akt_aktienkurs, akt_jahresdividende;

        printf("\nBitte gib den Aktienkurs an: ");
        scanf("%f", &akt_aktienkurs);

        printf("\nBitte gib die Jahresdividende an: ");
        scanf("%f", &akt_jahresdividende);

        dividendenrendite(akt_aktienkurs, akt_jahresdividende);


    }else if(antwort == '6'){

        int gesamtzahlKaeufeVerkaeufe;
        int SummeKaeufeVerkaeufe;

        printf("------Hinweis------ \n");
        printf("Die Anzahl Deiner Gesamtkaeufe/Verkaeufe ist dein 'n'\nDie Summe aus Deinen vorher addierten Kaeufen/Verkaeufen ergibt sich aus: (x1 + x2 + ... + xn)/n");
        
        printf("\n\nBitte gib die Summe aus deinen Kaeufen und Verkaeufen an: ");
        scanf("%d", &SummeKaeufeVerkaeufe);
        
        printf("Bitte gib die Anzahl an Kaeufen/Verkaeufen an: ");
        scanf("%d", &gesamtzahlKaeufeVerkaeufe);

        durchschnStueckzahl(gesamtzahlKaeufeVerkaeufe, SummeKaeufeVerkaeufe);
        
    else if(antwort == '7'){
    
        groeßte_Jahresdividende();
    
    }else if(antwort == '8'){

        printf("Beendet.");
    }
    
    else

        printf("\nBitte nur gueltige Werte eingeben!");

}

    return 0;







}