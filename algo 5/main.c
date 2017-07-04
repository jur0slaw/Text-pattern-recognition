#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generacja_tablicy(char * w, int * t, int len ){
    int i,j;
    i=1;
    j=0;
    t[0]=0;
    while(i>0 && i<len){
        if(w[i]==w[j]){
            t[i]=j+1;
            j++;
            i++;
        }
        if(w[i]!=w[j] && j==0){
                t[i]=0;
                i++;
        }
        if(w[i]!=w[j] && j>0){
            j=t[j-1];

        }
    }


}

int main()
{
    char wzorzec[] = "ABCDABG";
    int dlugosc_wzorca = strlen(wzorzec);
    int tps[8];
    generacja_tablicy(wzorzec,tps, dlugosc_wzorca);
    int i;
    printf("Oto Tablica prefikso-sufiksow:");
    for(i=0;i<dlugosc_wzorca;i++){
        printf("%i ",tps[i]);
    }

    char tekst[] = "ABCEABCDABCDABG";


    i=0;
    int j=0;


    while(i+j<strlen(tekst)){
        if(wzorzec[i]==tekst[i+j]){
            if(i==dlugosc_wzorca-1){

                printf("\nWzorzec zostal znaleziony na miejscu %i", j);
                break;
            }else{
                i++;
            }
        }
        if(wzorzec[i]!=tekst[i+j]){
            if(i>0){
                j = j+i - tps[i-1];
                i = tps[i-1];
            }else{
                i=0;
                j++;
            }
        }
    }

    return 0;
}
