#include <stdio.h> 
// I grammi ayti "ensomatonei" ti vivliothiki eisodou/exodou (Standard Input Output).
// Xari se ayti boroume na xrisimopoioume synartiseis opos to printf,
// pou emfanizei minymata stin othoni.


// Kathe programma C xekinaei apo ti synartisi main().
// Einai to "simeio ekkinisis" tou programmatos.
int main()  
{
    // I printf() einai synartisi pou emfanizei (ektyponei) keimeno stin othoni.
    // To keimeno pou theloume na emfanisoume to grafoume mesa se " ".
    // To \n sto telos simainei "pigaine stin epomeni grammi" (newline).
    printf("Hello World\n");

    // Edo typonoume to onoma mas, me merikous eidikous xaraktires:
    // \n -> allazei grammi (newline)
    // \t -> vazei enan "orizodio" keno xoro (tab)
    // Parakato vlepoume pos xrisimopoioudai:
    printf("\n\n\nKonstantinos\t Gioldasis");

    // I edoli return 0 dilonei oti to programma teleiose epityxos.
    // O arithmos 0 einai "sima epityxias" pros to leitourgiko systima.
    return 0;
	
	// Ayti i printf() den tha ektelestei pote, giati vrisketai meta to return.
    // Otan to programma synadisei ti lexi return, stamataei i ektelesi.
    printf("Eimai meta to return...");
}
