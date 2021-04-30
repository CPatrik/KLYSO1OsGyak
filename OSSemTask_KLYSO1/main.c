#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	
        pid_t gyerek1, gyerek2;     //A két unokákat készítő processz
        int unokaProcessz = 3;      //Unoka processzek darabszáma
        int sec = 3;                //Idő másodpercben amennyit várakozni fogunk

        gyerek1 = fork();           //Elkészítjük az első processzünket

        if (gyerek1 == 0)
        {
                //Gyerek1 programkód
                printf("------Gyerek1------\n");
                for(int i=0;i<unokaProcessz;i++)    //gyerek1 3db unokájának a létrehozása és várakozása
                        {
                            if(fork() == 0)
                            {
                                printf("[%d] pid %d [gyerek1]-tol pid %d\n",i+1,getpid(),getppid());
                                sleep(sec); //Vár sec percet
                                exit(0);
                            }
                        }
                
                gyerek2 = fork();
                if (gyerek2 == 0)
                {
                        //Gyerek2 programkód
                        printf("------Gyerek2------\n");
                        for(int i=0;i<unokaProcessz;i++)    //gyerek2 3db unokájának a létrehozása és várakozása
                        {
                            if(fork() == 0)
                            {
                                printf("[%d] pid %d [gyerek2]-tol pid %d\n",i+1,getpid(),getppid());
                                sleep(sec);
                                exit(0);
                            }
                        }
                }
                else
                {
                    //Gyerek2 parent programkód
                    for(int i=0;i<unokaProcessz;i++)
                    {
                        wait(NULL);     //Ez annyiszor fut le amennyi unokat kreáltunk a gyerek2-ben, ezzel vár a befejezésükre
                        printf("\tVarakozas unokakra gyerek2 %dx \n",i+1);
                    }
                    printf("--Gyerek2 exit--\n");
                    exit(0);    //Gyerek2 bezárása
                }
                
        }
        else
        {
            //Gyerek1 parent programkód
            for(int i=0;i<unokaProcessz;i++)
            {
                wait(NULL);     //Ez annyiszor fut le amennyi unokat kreáltunk a gyerek2-ben, ezzel vár a befejezésükre
                printf("\tVarakozas unokakra gyerek1 %dx \n",i+1);
            }
            printf("Varakozas gyerek2-re\n");
            wait(NULL);         //megvárja a gyerek2 kilépését 
            printf("--Gyerek1 exit--\n");
            exit(0);            //Gyerek1 kilépése
        
        }
        //Parent
        wait(NULL);             //Megvárja a gyerek1 kilépését
        printf("\t-----Return-----\n");   //Ezzel jelzi hogy vége minden folyamatnak és kilép
        return 0;
}