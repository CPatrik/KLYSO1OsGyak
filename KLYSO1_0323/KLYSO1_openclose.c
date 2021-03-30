#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main()
{
    char buffer[25];
    int bLength;
    int descriptor;
    int dwrite;
    int dseek;
    int dread;

    descriptor = open("KLYSO1.txt",O_RDWR);
    if (descriptor == -1){
        perror("Hiba a megnyitásnál:");
        exit(descriptor);
    }
    printf("Descrpitor: %d\n", descriptor);

    dseek = lseek(descriptor, 0, SEEK_SET);
    if (dseek == -1){
        perror("Hiba a kurzor pozícionálásnál:");
        exit(dseek);
    }
    printf("Pozíció: %d\n", dseek);

    dread = read(descriptor, buffer, 15);
    if (dread == -1){
        perror("Hiba az olvasásánál:");
        exit(dseek);
    }
    printf("Read: %d\n", dread);
    printf("Ertek: %s", buffer);

    strcpy(buffer, "KLYSO1");
    bLength = strlen(buffer);
    dwrite = write(descriptor, buffer, bLength);
    if (dwrite == -1){
        perror("Hiba az írásnál:");
        exit(dwrite);
    }
    printf("Hossz(byte): %d", dwrite);

    return 0;
}