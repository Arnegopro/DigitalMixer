#include <stdio.h>
#include <stdlib.h>

double * readFilters(char path){
    //Deklarerer variabler
    FILE *filter;
    char *mode = "r";
    unsigned long fileLen;
    double falsevalue[1] = {-1};
    //Åpner fil
    filter = fopen(path, mode);
    //Sjekker om filen er åpen
    if (filter == NULL){
        printf("Error while reading file");
        return falsevalue;
    }
    //Finner lengden og leser filteret fra filen
    fseek(filter,0,SEEK_END);
    fileLen=ftell(filter);
    double buffer[fileLen];
    fseek(filter,0,SEEK_SET);
    fread(buffer, fileLen, 1, filter);
    fclose(filter);
    return buffer;
}

int main()
{
    double * HP1 = readFilters('C:/Users/Arneslaptop/Documents/DigitalMixer/HP1.bin');
    double * HP2 = readFilters('C:/Users/Arneslaptop/Documents/DigitalMixer/HP2.bin');
    double * HP3 = readFilters('C:/Users/Arneslaptop/Documents/DigitalMixer/HP3.bin');
    double * LP1 = readFilters('C:/Users/Arneslaptop/Documents/DigitalMixer/LP1.bin');
    double * LP2 = readFilters('C:/Users/Arneslaptop/Documents/DigitalMixer/LP2.bin');
    double * LP3 = readFilters('C:/Users/Arneslaptop/Documents/DigitalMixer/LP3.bin');

    return 0;
};
