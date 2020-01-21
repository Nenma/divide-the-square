#include <graphics.h>
#include <winbgim.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>

using namespace std;

int JOC = 0;
bool GATA = false;
bool MUSIC = true;
int numar3=8, stay=1, LANGUAGE=1;
char intChar[100][100];
void conNr();

void menu()
{
    int x, y;
    setcolor(YELLOW);             //dreptunghiuri mari meniu
    setcolor(8);
    rectangle(400,200-20,1000,600-50);
    rectangle(405,205-20,1005,605-50);
    rectangle(395,195-20,995,595-50);

    for(int p=0;p<=2;p++){
        rectangle(450,p*100+150+50+25,650,p*100+215+70);           //butoanele de easy, hard, create
        rectangle(450+5,p*100+155+75,650+5,p*100+215+75);
        rectangle(450-5,p*100+155-5+70,650-5,p*100+215-5+70);
    }

    for(int p=1;p<=2;p++){
        rectangle(750,p*100+150+50+25,950,p*100+215+70);           //butoanele de settings si quit
        rectangle(750+5,p*100+155+75,950+5,p*100+215+75);
        rectangle(750-5,p*100+155-5+70,950-5,p*100+215-5+70);
    }

    //textul butoanelor in fct de limba
    settextstyle(10, HORIZ_DIR, 4);
    if(LANGUAGE==1)
        outtextxy(506, 240, "Easy");
    else if(LANGUAGE==2)
        outtextxy(506, 240, "Usor");
    else
        outtextxy(490, 240, "Facile");

    settextstyle(10, HORIZ_DIR, 4);
    if(LANGUAGE==1)
        outtextxy(506, 340, "Hard");
    else if(LANGUAGE==2)
        outtextxy(506, 340, "Greu");
    else
        outtextxy(470, 340, "Difficile");

    settextstyle(10, HORIZ_DIR, 4);
    if(LANGUAGE==1)
        outtextxy(488, 440, "Create!");
    else if(LANGUAGE==2)
        outtextxy(480, 440, "Creeaza");
    else
        outtextxy(498, 440, "Créer!");

    settextstyle(10, HORIZ_DIR, 8);
    if(LANGUAGE==1 || LANGUAGE==3)
        outtextxy(750, 210, "MENU");
    else
        outtextxy(735, 210, "MENIU");

    settextstyle(10, HORIZ_DIR, 4);
    if(LANGUAGE==1)
        outtextxy(766, 440, "Quit Game");
    else if(LANGUAGE==2)
        outtextxy(780, 440, " Iesire");
    else
        outtextxy(766, 440, " Quitter");

    settextstyle(10, HORIZ_DIR, 4);
    if(LANGUAGE==1)
        outtextxy(773, 340, "Settings");
    else if(LANGUAGE==2)
        outtextxy(780, 340, " Setari");
    else
        outtextxy(773, 340, "Réglages");

    settextstyle(10, HORIZ_DIR, 6);
    if(LANGUAGE==1)
        outtextxy(440, 60, "DIVIDE THE SQUARE");
    else if(LANGUAGE==2)
        outtextxy(400, 60, "IMPARTIREA CAREULUI");
    else
        outtextxy(460, 60, "DIVISER LA CARRÉ");

    //var ce tin cont de animatia fiecaerui buton din meniu
    bool animationEasy = false;
    bool animationHard = false;
    bool animationCreate = false;
    bool animationSet = false;
    bool animationQuit = false;
    int p;
    do{
        x = mousex();
        y = mousey();

        bool EASY = x>=450 && x<=650 && y>=225 && y<=285;
        bool HARD = x>=450 && x<=650 && y>=325 && y<=385;
        bool QUIT_GAME = x>=750 && x<=950 && y>=425 && y<=485;
        bool CREATE = x>=450 && x<=650 && y>=425 && y<=485;
        bool SETTINGS = x>=750 && x<=950 && y>=325 && y<=385;

        //daca da hover pe EASY
        if(EASY){
            //text explicativ
            setcolor(YELLOW);
            settextstyle(10, HORIZ_DIR, 4);
            if(LANGUAGE==1){
                outtextxy(250, 600, "In this mode you will have to divide the square");
                outtextxy(240, 650, "in 8 equal areas that contain 1 of every type of");
                outtextxy(240, 700, "dot present on it.");
            }else if(LANGUAGE==2){
                outtextxy(250, 600, "In acest mod, careul trebuie impartit in 8 zone");
                outtextxy(240, 650, "egale ce contin cate un tip din fiecare bila.");
            }else{
                outtextxy(250, 600, "Dans ce mode, vous devrez diviser la carré en 8");
                outtextxy(240, 650, "zones égales qui continnent 1 de chaque type de");
                outtextxy(240, 700, "point présent dessus.");
            }
            //animatia
            if(!animationEasy){
                animationEasy = true;
                for(p=0; p<=5; p++){
                    setcolor(YELLOW);
                    rectangle(450, 225, 650, 285);
                    rectangle(455-p, 230-p, 655-p, 290-p);
                    rectangle(445+p, 220+p, 645+p, 280+p);
                    delay(70);
                    setcolor(BLACK);
                    rectangle(450, 225, 650, 285);
                    rectangle(455-p, 230-p, 655-p, 290-p);
                    rectangle(445+p, 220+p, 645+p, 280+p);
                }
                setcolor(DARKGRAY);
                rectangle(450, 225, 650, 285);
                rectangle(455, 230, 655, 290);
                rectangle(445, 220, 645, 280);
            }else{
                setcolor(YELLOW);
                rectangle(450, 225, 650, 285);
                setcolor(BLACK);
                rectangle(455, 230, 655, 290);
                rectangle(445, 220, 645, 280);
            }
        }else{
            animationEasy = false;
            setcolor(DARKGRAY);
            rectangle(450, 225, 650, 285);
            rectangle(455, 230, 655, 290);
            rectangle(445, 220, 645, 280);
            if(!HARD && !QUIT_GAME && !CREATE && !SETTINGS){
                outtextxy(250, 600, "                                               ");
                outtextxy(240, 650, "                                                ");
                outtextxy(240, 700, "                     ");
            }
        }
        //daca da hover pe HARD
        if(HARD){
            setcolor(YELLOW);
            settextstyle(10, HORIZ_DIR, 4);
            if(LANGUAGE==1){
                outtextxy(250, 600, "In this mode you will have to divide the square");
                outtextxy(240, 650, "in 4 equal areas that have the same shape and");
                outtextxy(240, 700, "contain 1 of every type of dot present on it.");
            }else if(LANGUAGE==2){
                outtextxy(250, 600, "In acest mod, careul trebuie impartit in 4 zone");
                outtextxy(240, 650, "atat de arii cat si de forme egale ce contin cate");
                outtextxy(240, 700, "un tip din fiecare bila.");
            }else{
                outtextxy(250, 600, "Dans ce mode, vous devrez diviser la carré en 4");
                outtextxy(240, 650, "zones égales et qui ont la meme forme, qui continnent");
                outtextxy(240, 700, "1 de chaque type de point présent dessus.");
            }

            if(!animationHard){
                animationHard = true;
                for(p=0; p<=5; p++){
                    setcolor(YELLOW);
                    rectangle(450, 325, 650, 385);
                    rectangle(455-p, 330-p, 655-p, 390-p);
                    rectangle(445+p, 320+p, 645+p, 380+p);
                    delay(70);
                    setcolor(BLACK);
                    rectangle(450, 325, 650, 385);
                    rectangle(455-p, 330-p, 655-p, 390-p);
                    rectangle(445+p, 320+p, 645+p, 380+p);
                }
                setcolor(DARKGRAY);
                rectangle(450, 325, 650, 385);
                rectangle(455, 330, 655, 390);
                rectangle(445, 320, 645, 380);
            }else{
                setcolor(YELLOW);
                rectangle(450, 325, 650, 385);
                setcolor(BLACK);
                rectangle(455, 330, 655, 390);
                rectangle(445, 320, 645, 380);
            }
        }else{
            animationHard = false;
            setcolor(DARKGRAY);
            rectangle(450, 325, 650, 385);
            rectangle(455, 330, 655, 390);
            rectangle(445, 320, 645, 380);
            if(!EASY && !QUIT_GAME && !CREATE && !SETTINGS){
            outtextxy(250, 600, "                                                   ");
            outtextxy(240, 650, "                                                         ");
            outtextxy(240, 700, "                                                  ");
            }
        }
        //daca da hover pe CREATE
        if(CREATE){
            setcolor(YELLOW);
            settextstyle(10, HORIZ_DIR, 4);
            if(LANGUAGE==1){
                outtextxy(250, 600, "In this mode, one player creates the level and");
                outtextxy(240, 650, "the other one tries to solve it.");
            }else if(LANGUAGE==2){
                outtextxy(250, 600, "In acest mod, un jucator creeaza nivelul si un");
                outtextxy(540, 650, "altul il rezolva.");
            }else{
                outtextxy(320, 600, "Dans ce mode, un joueur crée le niveau et");
                outtextxy(440, 650, "l'autre essaie de le résoudre.");
            }

            if(!animationCreate){
                animationCreate = true;
                for(p=0; p<=5; p++){
                    setcolor(YELLOW);
                    rectangle(450, 425, 650, 485);
                    rectangle(455-p, 430-p, 655-p, 490-p);
                    rectangle(445+p, 420+p, 645+p, 480+p);
                    delay(70);
                    setcolor(BLACK);
                    rectangle(450, 425, 650, 485);
                    rectangle(455-p, 430-p, 655-p, 490-p);
                    rectangle(445+p, 420+p, 645+p, 480+p);
                }
                setcolor(DARKGRAY);
                rectangle(450, 425, 650, 485);
                rectangle(455, 430, 655, 490);
                rectangle(445, 420, 645, 480);
            }else{
                setcolor(YELLOW);
                rectangle(450, 425, 650, 485);
                setcolor(BLACK);
                rectangle(455, 430, 655, 490);
                rectangle(445, 420, 645, 480);
            }
        }else{
            animationCreate = false;
            setcolor(DARKGRAY);
            rectangle(450, 425, 650, 485);
            rectangle(455, 430, 655, 490);
            rectangle(445, 420, 645, 480);
           if(!EASY && !HARD && !SETTINGS && !QUIT_GAME){
            outtextxy(250, 600, "                                                  ");
            outtextxy(240, 650, "                                     ");
           }
        }
        //daca da hover pe SETTINGS
        if(SETTINGS){
            setcolor(YELLOW);
            settextstyle(10, HORIZ_DIR, 4);
            if(LANGUAGE==1){
                outtextxy(370, 600, "Here you can personalize your game.");
            }else if(LANGUAGE==2){
                outtextxy(400, 600, "Aici va puteti personaliza jocul.");
            }else{
                outtextxy(350, 600, "Ici vous pouvez personnaliser votre jeu.");
            }

            if(!animationSet){
                animationSet = true;
                for(p=0; p<=5; p++){
                    setcolor(YELLOW);
                    rectangle(750, 325, 950, 385);
                    rectangle(755-p, 330-p, 955-p, 390-p);
                    rectangle(745+p, 320+p, 945+p, 380+p);
                    delay(70);
                    setcolor(BLACK);
                    rectangle(750, 325, 950, 385);
                    rectangle(755-p, 330-p, 955-p, 390-p);
                    rectangle(745+p, 320+p, 945+p, 380+p);
                }
                setcolor(DARKGRAY);
                rectangle(750, 325, 950, 385);
                rectangle(755, 330, 955, 390);
                rectangle(745, 320, 945, 380);
            }else{
                setcolor(YELLOW);
                rectangle(750, 325, 950, 385);
                setcolor(BLACK);
                rectangle(755, 330, 955, 390);
                rectangle(745, 320, 945, 380);
            }
        }else{
            animationSet = false;
            setcolor(DARKGRAY);
            rectangle(750, 325, 950, 385);
            rectangle(755, 330, 955, 390);
            rectangle(745, 320, 945, 380);
            if(!EASY && !HARD && !CREATE && !QUIT_GAME){
                outtextxy(250, 600, "                                        ");
            }
        }
        //daca da hover pe QUIT GAME
        if(QUIT_GAME){
            setcolor(YELLOW);
            settextstyle(10, HORIZ_DIR, 4);
            if(LANGUAGE==1){
                outtextxy(600, 600, "Close the game...");
            }else if(LANGUAGE==2){
                outtextxy(600, 600, "Inchide jocul...");
            }else{
                outtextxy(600, 600, "Quitter le jeu...");
            }

            if(!animationQuit){
                animationQuit = true;
                for(p=0; p<=5; p++){
                    setcolor(YELLOW);
                    rectangle(750, 425, 950, 485);
                    rectangle(755-p, 430-p, 955-p, 490-p);
                    rectangle(745+p, 420+p, 945+p, 480+p);
                    delay(70);
                    setcolor(BLACK);
                    rectangle(750, 425, 950, 485);
                    rectangle(755-p, 430-p, 955-p, 490-p);
                    rectangle(745+p, 420+p, 945+p, 480+p);
                }
                setcolor(DARKGRAY);
                rectangle(750, 425, 950, 485);
                rectangle(755, 430, 955, 490);
                rectangle(745, 420, 945, 480);
            }else{
                setcolor(YELLOW);
                rectangle(750, 425, 950, 485);
                setcolor(BLACK);
                rectangle(755, 430, 955, 490);
                rectangle(745, 420, 945, 480);
            }
        }else{
            animationQuit = false;
            setcolor(DARKGRAY);
            rectangle(750, 425, 950, 485);
            rectangle(755, 430, 955, 490);
            rectangle(745, 420, 945, 480);
            if(!EASY && !HARD && !CREATE && !SETTINGS){
                outtextxy(600, 600, "                 ");
            }
        }


    if(ismouseclick(WM_LBUTTONDOWN)){
        clearmouseclick(WM_LBUTTONDOWN);
        x = mousex();
        y = mousey();

        //daca apasa pe EASY
        if(x>=450 && x<=650 && y>=225 && y<=285){
            Beep(423,100);
            cleardevice();
            JOC = 1;
        }
        //daca apasa pe HARD
        else if(x>=450 && x<=650 && y>=325 && y<=385){
            Beep(423,100);
            cleardevice();
            JOC = 2;
        }
        //daca apasa pe CREATE
        else if(x>=450 && x<=650 && y>=425 && y<=485){
            Beep(423,100);
            cleardevice();
            JOC = 3;
        }
        //daca apasa SETARI
        else if(x>=750 && x<=950 && y>=325 && y<=385){
            Beep(423,100);
            cleardevice();
            JOC = 4;
        }
        //daca pasa pe QUIT GAME
        else if(x>=750 && x<=950 && y>=425 && y<=485){
            Beep(423,100);
            GATA = true;
        }
    }
    }while(JOC==0 && !GATA);

}

///PARTEA 1
ifstream fin("pro.in");

int stanga1,sus1,width1,height1,latura1, numar,a[10][10],k,s[10][10],nrNivel=1,copie[10][10];
char conversie[21][21];
bool gata1;
void desen1();
void joacaNivelul();
void nextLevel();
void nivelNou();
void resetLevel();
int backk=0;

void backToMenu() //pentru a reveni la menu
{
    cleardevice();
    JOC=0;
    gata1=true;
    nrNivel=1;
    k=0;
    backk=1;
}

void punerePiesa()//cand apas pentru a-mi imparti careul
{
    int linia,coloana,x,y;
    if(ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        x=mousex();
        y=mousey();
        if(k==63) gata1=true;

        if (x>=stanga1 && x<=stanga1+width1 && y>=sus1&&y<=sus1+height1) //daca sunt in careu
        {
            linia=(y-sus1)/latura1+1;
            coloana=(x-stanga1)/latura1+1;
            if(a[linia][coloana]==0 || a[linia][coloana]>=10) //daca nu este deja selectat
               {
                setcolor(k/8+1);
                // marchez ariile selectate
                circle(stanga1+latura1*(coloana-1)+latura1/2,sus1+latura1*(linia-1)+latura1/2,11);
                circle(stanga1+latura1*(coloana-1)+latura1/2,sus1+latura1*(linia-1)+latura1/2,12);
                circle(stanga1+latura1*(coloana-1)+latura1/2,sus1+latura1*(linia-1)+latura1/2,13);
                circle(stanga1+latura1*(coloana-1)+latura1/2,sus1+latura1*(linia-1)+latura1/2,14);
                circle(stanga1+latura1*(coloana-1)+latura1/2,sus1+latura1*(linia-1)+latura1/2,15);
                circle(stanga1+latura1*(coloana-1)+latura1/2,sus1+latura1*(linia-1)+latura1/2,16);
                circle(stanga1+latura1*(coloana-1)+latura1/2,sus1+latura1*(linia-1)+latura1/2,17);
                circle(stanga1+latura1*(coloana-1)+latura1/2,sus1+latura1*(linia-1)+latura1/2,18);
                circle(stanga1+latura1*(coloana-1)+latura1/2,sus1+latura1*(linia-1)+latura1/2,19);


                a[linia][coloana]=k/8+1; //scriu si in matrice ariile
                k++;
                }
        } // end daca apas in careu
    if(x>1195 && y>20 && x<1285 && y<60) Beep(423,100), nextLevel();//apas butonul Next
    if(x>20 && y>20 && x<110 && y<60) Beep(423,100), resetLevel();//apas butonul Reset
    if(x>20 && y>90 && x<110 && y<130) Beep(423,100), backToMenu(),k=0,gata1=true,backk=1;//apas menu
    } //end if mouse pressed
}

void conversieNr() //functie pentru a face conversia intre int si char, pentru a le afisa
{
    strcpy(conversie[1]," 1");
    strcpy(conversie[2]," 2");
    strcpy(conversie[3]," 3");
    strcpy(conversie[4]," 4");
    strcpy(conversie[5]," 5");
    strcpy(conversie[6]," 6");
    strcpy(conversie[7]," 7");
    strcpy(conversie[8]," 8");
    strcpy(conversie[9]," 9");
    strcpy(conversie[10]," 10");
    strcpy(conversie[11]," 11");
    strcpy(conversie[12]," 12");
}

///TODO: dupa next, back, reset nu mai functioneaza
void resetLevel() //functie pentru resetarea nivelului
{
    k=0;
    cleardevice();
    for(int i=1;i<=8;i++)
        for(int j=1;j<=8;j++)
            a[i][j]=copie[i][j];
    joacaNivelul();
}

///TODO: se poate da next la nesfarsit
void nextLevel()//functie pentru a trece la nivelul urmator
{
    cleardevice();
    nrNivel++;
    k=0;
    for(int i=1;i<=8;i++)
        for(int j=1;j<=8;j++)
            a[i][j]=0,s[i][j]=0;
    nivelNou();
}

void desen1()
{
    int i,j; //desenarea careului
    numar=8;
    width1=400;
    height1=400;
    setcolor(YELLOW);
    latura1=width1/numar;
    sus1=(getmaxy()-width1)/2;
    stanga1=(getmaxx()-height1)/2;
    setcolor(YELLOW);
    rectangle(stanga1-15,sus1-15,stanga1+405,sus1+405);//pentru a crea efectul vizual de relief
    rectangle(stanga1-5,sus1-5,stanga1+415,sus1+415);
    for(i=1; i<=numar; i++)
        for(j=1; j<=numar; j++) //desenam bilele in functie de datele din fisier
            {
            setcolor(YELLOW);
            rectangle(stanga1+latura1*(i-1),sus1+latura1*(j-1),stanga1+latura1*i,sus1+latura1*j);
            if(a[i][j]==10) setcolor(14),circle(stanga1+latura1*(j-1)+latura1/2,sus1+latura1*(i-1)+latura1/2,10),circle(stanga1+latura1*(j-1)+latura1/2,sus1+latura1*(i-1)+latura1/2,7),circle(stanga1+latura1*(j-1)+latura1/2,sus1+latura1*(i-1)+latura1/2,4);
            if(a[i][j]==11) setcolor(13),setfillstyle(SOLID_FILL,13),circle(stanga1+latura1*(j-1)+latura1/2,sus1+latura1*(i-1)+latura1/2,10), floodfill(stanga1+latura1*(j-1)+latura1/2,sus1+latura1*(i-1)+latura1/2,13);
            if(a[i][j]==12) setcolor(12),circle(stanga1+latura1*(j-1)+latura1/2,sus1+latura1*(i-1)+latura1/2,10),setfillstyle(SOLID_FILL,12),circle(stanga1+latura1*(j-1)+latura1/2,sus1+latura1*(i-1)+latura1/2,3), floodfill(stanga1+latura1*(j-1)+latura1/2,sus1+latura1*(i-1)+latura1/2,12);
            }
    //butoane
    setcolor(YELLOW);
    rectangle(20,20,110,60);
    rectangle(25,25,115,65);
    rectangle(15,15,95+10,55);
    moveto(30,30);
    settextstyle(10, HORIZ_DIR, 3);
    if(LANGUAGE==1)
        outtext("Reset");
    else if(LANGUAGE==2)
        outtextxy(36,30,"Reia");
    else
        outtextxy(24,30, "Remont");


    rectangle(20,90,110,130);
    rectangle(25,95,115,135);
    rectangle(15,85,105,125);
    moveto(37,100);
    settextstyle(10, HORIZ_DIR, 3);
    if(LANGUAGE==1)
        outtext("Menu");
    else if(LANGUAGE==2)
        outtextxy(30,100,"Meniu");
    else
        outtextxy(37,100, "Menu");




    rectangle(1195,20,1285,60);
    rectangle(1200,25,1290,65);
    rectangle(1190,15,1280,55);
    moveto(1211,30);
    settextstyle(10, HORIZ_DIR, 3);
    if(LANGUAGE==1)
        outtext("Next");
    else if(LANGUAGE==2)
        settextstyle(10, HORIZ_DIR, 1),outtextxy(1202,30,"Urmator");
    else
        settextstyle(10, HORIZ_DIR, 1),outtextxy(1202,30,"Suivant");


    // end butoane

    moveto(615,45);//afisez nivel x
    settextstyle(10, HORIZ_DIR, 4);
    if(LANGUAGE==1)
        outtext(" Level");
    else if(LANGUAGE==2)
        outtext("Nivelul");
    else
        outtext("Niveau");


    outtext(conversie[nrNivel]);

}




int solutie()//verific daca impartirea careului este solutie
 {

   int v[10];
   int i,j;
   for(i=1;i<10;i++)
        v[i]=0;

    for(i=1;i<=8;i++)
        for(j=1;j<=8;j++){
            if(!v[a[i][j]])
                v[a[i][j]]=s[i][j];
            else
                if(v[a[i][j]]!=s[i][j]) return 0;
            }


    return 1;

 }

void citesteMatricea() //citim datele de intrare din fisier
{
    int i,j;
    for(i=1;i<=8;i++)
        for(j=1;j<=8;j++) fin>>a[i][j],copie[i][j]=a[i][j];
    for(i=1;i<=8;i++)
        for(j=1;j<=8;j++) fin>>s[i][j];
}

void nivelNou() //trecerea la un nivel nou
{
    citesteMatricea();
    joacaNivelul();
}

void alegere()//functie pentru a alege ce fac dupa terminarea jocului:next,reset sau back
{   int x,y;
    if(ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        x=mousex();
        y=mousey();
        if(x>1195 && y>20 && x<1285 && y<60) Beep(423,100),nextLevel();

        if(x>20 && y>20 && x<110 && y<60) Beep(423,100),resetLevel();

        if(x>20 && y>90 && x<110 && y<130) Beep(423,100),backToMenu(),k=0,gata1=true,backk=1;
    }
}

void joacaNivelul()

{
    desen1();
    k=0;

    gata1=false;
    do
    {
        punerePiesa();
    }
    while (!gata1 );

    if(solutie()) //afisam mesaj, in functie de corectitudinea solutiei
        {
            moveto(390,650);
            settextstyle(10, HORIZ_DIR, 4);
              if(LANGUAGE==1)
                outtext("Level completed! Congrats!");
            else if(LANGUAGE==2)
                outtext("Nivel terminat! Felicitari!");
            else
                outtext("Niveau complet! Félicitations!");



        }
    else
        {
        if(k==64)
            {
            moveto(530,650);
            settextstyle(10, HORIZ_DIR, 4);
            if(LANGUAGE==1)
                outtext("Level not completed");
            else if(LANGUAGE==2)
                outtext(" Solutie incorecta");
            else
                outtext(" Solution incorrecte");
            }

        }

    if(backk!=1)
    {
        k=1;
        do
        {
            alegere();
        } while(k!=0);
    }

}











///PARTEA 2
//ifstream nivel;
//ifstream sol;
//ofstream output("output");

int stanga, sus, length, latura, numar2=8, schimbatorLogic;
int schimbatorCuloare;
float helpSchimbatorCuloare;
int culoriUtilizabile[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13, 14};
bool gata;
int hint;
bool nivelTerminat = false;
bool sfarsit = false;
int const MAX = 10;
int tabla[MAX][MAX];
int tablaLogica[MAX][MAX];
int const GOL = 0;
int const BILA_ALBA = -1;
int const BILA_NEAGRA = -2;
int const BILA_GRI = -3;
int const GRAY = -3;
int tablaSolutie[MAX][MAX];
int nivelActual = 1;
int solutieActuala = 1;

struct veciniSimetrici{
    int pozX;
    int pozY;
};

veciniSimetrici piesa[4];

struct detalii{
    int pozX;
    int pozY;
    int info;
};

struct stiva{
    int varf;
    detalii tab[65];
};

void initStiva(stiva &S)
{
    S.varf = 0;
}

bool esteStivaVida(stiva S)
{
    return S.varf == 0;
}

void push(stiva &S, int x, int y, int el)
{
    S.varf++;
    S.tab[S.varf].pozX = x;
    S.tab[S.varf].pozY = y;
    S.tab[S.varf].info = el;
}

void pop(stiva &S)
{
    S.varf--;
}

stiva stivaUndo;

void initTabla()  //initial, toata tabla e goala, deci cyan
{
    for(int i=1; i<=numar2; i++)
        for(int j=1; j<=numar2; j++)
            tabla[i][j] = LIGHTCYAN;
}

void initTabla(int matrix[MAX][MAX])
{
    for(int i=1; i<=numar2; i++)
        for(int j=1; j<=numar2; j++)
            matrix[i][j] = GOL;
}

void creeazaTabla(int lvl) //citeste din fisier si pune punctele pe tabla
{
    initTabla();
    initTabla(tablaLogica);
    int linie, coloana, culoare;

    length = 600;
    latura=length/numar2;
    sus=(getmaxy()-length)/2;
    stanga=(getmaxx()-length)/2;

    char sirNivel[10];
    itoa(lvl, sirNivel, 10);

    stringstream ss;
    ss<<lvl;
    string str = ss.str();
    ifstream nivel("nivel"+str);

    nivel>>hint;
    while(!nivel.eof()){
        nivel>>coloana>>linie>>culoare;
        tabla[coloana][linie] = culoare;
        if(culoare == WHITE)
            tablaLogica[coloana][linie] = BILA_ALBA;
        else if(culoare == BLACK)
            tablaLogica[coloana][linie] = BILA_NEAGRA;
        else
            tablaLogica[coloana][linie] = BILA_GRI;
    }
    setcolor(YELLOW);
    settextstyle(10, HORIZ_DIR, 4);
    if(LANGUAGE == 1)
        outtextxy(stanga+3*latura, 20, "Level");
    else if(LANGUAGE == 2)
        outtextxy(stanga+3*latura, 20, "Nivel");
    else
        outtextxy(stanga+3*latura-15, 20, "Niveau");
    outtextxy(stanga+3*latura+110, 20, "  ");
    outtextxy(stanga+3*latura+110, 20, sirNivel);
    nivel.close();
}

void creeazaTablaSolutie(int lvl)
{
    int i, j, elem;
    stringstream ss;
    ss<<lvl;
    string str = ss.str();
    ifstream sol("solutie"+str);
    for(i=1; i<=numar2, !sol.eof(); i++)
        for(j=1; j<=numar2; j++){
            sol>>elem;
            tablaSolutie[i][j] = elem;
        }
    sol.close();
}

void afisazaTabla(int matrix[MAX][MAX])
{
    for(int i=1; i<=numar2; i++){
        for(int j=1; j<=numar2; j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

bool nivelCastigat(int matrix[MAX][MAX])
{
    int i=1, j=1, k;
    int corespondent[5];
    bool flag, solutie = true;
    for(k=1; k<=4; k++){
        flag = true;
        for(i=1; i<=numar2, flag; i++)
            for(j=1; j<=numar2; j++)
                if(tablaSolutie[i][j] == k){
                    corespondent[k] = matrix[i][j];
                    flag = false;
                }
    }
    for(i=1; i<=4; i++)
        for(j=1; j<=4; j++)
            if(i != j && corespondent[i] == corespondent[j])
                solutie = false;
    for(i=1; i<=numar2; i++)
        for(j=1; j<=numar2; j++)
            if(corespondent[tablaSolutie[i][j]] != matrix[i][j])
                solutie = false;
   return solutie;
}

void desen()
{
    int i,j, linia, coloana;

    //buton pentru urmatorul nivel
    rectangle(stanga+3*latura, 720, stanga+5*latura, 780);
    rectangle(stanga+3*latura-5, 715, stanga+5*latura-5, 775);
    rectangle(stanga+3*latura+5, 725, stanga+5*latura+5, 785);
    settextstyle(10, HORIZ_DIR, 4);
    if(LANGUAGE == 1)
        outtextxy(stanga+3.25*latura+10, 730, "NEXT");
    else if(LANGUAGE == 2)
        settextstyle(10, HORIZ_DIR, 3), outtextxy(stanga+3.25*latura+10, 735, "URMATOR");
    else
        settextstyle(10, HORIZ_DIR, 3), outtextxy(stanga+3.25*latura+10, 735, "SUIVANT");

    //buton pentru verificarea solutiei bune
    rectangle(stanga+6*latura, 720, stanga+8*latura, 780);
    rectangle(stanga+6*latura-5, 715, stanga+8*latura-5, 775);
    rectangle(stanga+6*latura+5, 725, stanga+8*latura+5, 785);
    settextstyle(10, HORIZ_DIR, 4);
    if(LANGUAGE == 1)
        outtextxy(stanga+6.25*latura, 730, "CHECK");
    else if(LANGUAGE == 2)
        settextstyle(10,HORIZ_DIR,3), outtextxy(stanga+6.25*latura, 735, "VERIFICA");
    else
        settextstyle(10,HORIZ_DIR,3), outtextxy(stanga+6.25*latura, 735, "VÉRIFIER");

    //buton de undo
    rectangle(stanga, 720, stanga+2*latura, 780);
    rectangle(stanga-5, 715, stanga+2*latura-5, 775);
    rectangle(stanga+5, 725, stanga+2*latura+5, 785);
    settextstyle(10, HORIZ_DIR, 4);
    if(LANGUAGE == 1)
        outtextxy(stanga+.40*latura, 730, "UNDO");
    else if(LANGUAGE == 2)
        outtextxy(stanga+.40*latura, 730, "REFA");
    else
        settextstyle(10,HORIZ_DIR,3), outtextxy(stanga+.40*latura-5, 735, "DÉFAIRE");

    //buton de hint
    rectangle(stanga+10*latura, sus+latura, stanga+12*latura, sus+latura+60);
    rectangle(stanga+10*latura-5, sus+latura-5, stanga+12*latura-5, sus+latura+55);
    rectangle(stanga+10*latura+5, sus+latura+5, stanga+12*latura+5, sus+latura+65);
    settextstyle(10, HORIZ_DIR, 4);
    if(LANGUAGE == 1)
        outtextxy(stanga+10.40*latura, sus+latura+10, "HINT");
    else if(LANGUAGE == 2)
        settextstyle(10, HORIZ_DIR, 3), outtextxy(stanga+10.40*latura, sus+latura+15, "INDICIU");
    else
        outtextxy(stanga+10.40*latura, sus+latura+10, "TRACE");

    //buton de reset
    rectangle(stanga-2*latura, sus+latura, stanga-4*latura, sus+latura+60);
    rectangle(stanga-2*latura-5, sus+latura-5, stanga-4*latura-5, sus+latura+55);
    rectangle(stanga-2*latura+5, sus+latura+5, stanga-4*latura+5, sus+latura+65);
    settextstyle(10, HORIZ_DIR, 4);
    if(LANGUAGE == 1)
        outtextxy(stanga-3.70*latura, sus+latura+10, "RESET");
    else if(LANGUAGE == 2)
        settextstyle(10, HORIZ_DIR, 3), outtextxy(stanga-3.70*latura-10, sus+latura+15, "RESETEAZA");
    else
        settextstyle(10, HORIZ_DIR, 3), outtextxy(stanga-3.70*latura-5, sus+latura+15, "REMETTRE");

    //buton de back
    rectangle(stanga-2*latura, sus+latura+100, stanga-4*latura, sus+latura+160);
    rectangle(stanga-2*latura-5, sus+latura+95, stanga-4*latura-5, sus+latura+155);
    rectangle(stanga-2*latura+5, sus+latura+105, stanga-4*latura+5, sus+latura+165);
    settextstyle(10, HORIZ_DIR, 4);
    if(LANGUAGE == 1)
        outtextxy(stanga-3.60*latura, sus+latura+110, "BACK");
    else if(LANGUAGE == 2)
        settextstyle(10, HORIZ_DIR, 3), outtextxy(stanga-3.60*latura, sus+latura+115, "INAPOI");
    else
        settextstyle(10, HORIZ_DIR, 3), outtextxy(stanga-3.60*latura, sus+latura+115, "DERNIER");


    //highlight-urile
    rectangle(stanga-5, sus-5, stanga+8*latura-5, sus+8*latura-5);
    rectangle(stanga+5, sus+5, stanga+8*latura+5, sus+8*latura+5);

    //se deseneaza intai tabla
    for(i=1; i<=numar2; i++)
        for(j=1; j<=numar2; j++){
            setcolor(LIGHTCYAN);
            setfillstyle(SOLID_FILL, LIGHTCYAN);
            rectangle(stanga+latura*(i-1), sus+latura*(j-1), stanga+latura*i, sus+latura*j);
            floodfill(stanga+latura*(i-1)+latura/2, sus+latura*(j-1)+latura/2, LIGHTCYAN);
            setcolor(LIGHTGRAY);
            rectangle(stanga+latura*(i-1), sus+latura*(j-1), stanga+latura*i, sus+latura*j);
        }

    //se deseneaza apoi si punctele
    for(i=1; i<=numar2; i++)
        for(j=1; j<=numar2; j++){
            if(tabla[i][j] == WHITE || tabla[i][j] == BLACK){
                linia = i;//(i-1)+1.5;
                coloana = j;//(j-1)+1.5;
                setcolor(tabla[i][j]);
                setfillstyle(SOLID_FILL, tabla[i][j]);
                circle(stanga+latura*(coloana-1)+latura/2, sus+latura*(linia-1)+latura/2, 20);
                floodfill(stanga+latura*(coloana-1)+latura/2, sus+latura*(linia-1)+latura/2, tabla[i][j]);
                setcolor(LIGHTGRAY);
                circle(stanga+latura*(coloana-1)+latura/2, sus+latura*(linia-1)+latura/2, 20);
            }else if(tabla[i][j] == GRAY){
                linia = i;//(i-1)+1.5;
                coloana = j;//(j-1)+1.5;
                setcolor(WHITE);
                setfillstyle(SOLID_FILL, WHITE);
                circle(stanga+latura*(coloana-1)+latura/2, sus+latura*(linia-1)+latura/2, 20);
                floodfill(stanga+latura*(coloana-1)+latura/2, sus+latura*(linia-1)+latura/2, WHITE);
                setcolor(LIGHTGRAY);
                circle(stanga+latura*(coloana-1)+latura/2, sus+latura*(linia-1)+latura/2, 20);
                setcolor(BLACK);
                //setlinestyle(0, 0, 2);
                line(stanga+latura*(coloana-1)+latura/2, sus+latura*(linia-1)+latura/2-20, stanga+latura*(coloana-1)+latura/2, sus+latura*(linia-1)+latura/2+20);
                line(stanga+latura*(coloana-1)+latura/2-20, sus+latura*(linia-1)+latura/2, stanga+latura*(coloana-1)+latura/2+20, sus+latura*(linia-1)+latura/2);
            }
        }
}

void actiune()
{
    length = 600;
    latura = length/numar2;
    sus = (getmaxy()-length)/2;
    stanga = (getmaxx()-length)/2;

    int linia, coloana, x, y, culoare;

    if(ismouseclick(WM_LBUTTONDOWN)){
        clearmouseclick(WM_LBUTTONDOWN);
        x = mousex();
        y = mousey();


        //daca apasa pe butonul NEXT!
        if(x>=stanga+3*latura && x<=stanga+5*latura && y>=720 && y<=780){
            Beep(423,100);
            if(nivelTerminat){
                nivelTerminat = false;
                initStiva(stivaUndo);
                cleardevice();
                nivelActual++;
                solutieActuala++;
                creeazaTabla(nivelActual);
                creeazaTablaSolutie(solutieActuala);
                desen();
            }else{
                if(nivelActual<=10 && !sfarsit){
                    setcolor(YELLOW);
                    settextstyle(10, HORIZ_DIR, 4);
                    if(LANGUAGE == 1)
                        outtextxy(stanga, 50, "Solution must be checked first!");
                    else if(LANGUAGE == 2)
                        outtextxy(stanga-20, 50, "Solutia trebuie verificata mai intai!");
                    else
                        outtextxy(stanga-80, 50, "La solution doit être vérifiée en premier!");
                    delay(2000);
                    outtextxy(stanga-80, 50, "                                                    ");
                }
            }
        }
        //daca apasa pe butonul CHECK!
        else if(x>=stanga+6*latura && x<=stanga+8*latura && y>=720 && y<=780){
            Beep(423,100);
            if(nivelCastigat(tablaLogica)){
                setcolor(YELLOW);
                settextstyle(10, HORIZ_DIR, 4);
                if(LANGUAGE == 1)
                    outtextxy(stanga+2.5*latura, 50, "You found it!");
                else if(LANGUAGE == 2)
                    outtextxy(stanga+2.5*latura, 50, "Ai gasit-o!");
                else
                    outtextxy(stanga+2.5*latura-20, 50, "Tu l'a trouvé!");
                nivelTerminat = true;
                if(nivelActual == 10){
                    nivelTerminat = false;
                    sfarsit = true;
                    if(LANGUAGE == 1)
                        outtextxy(stanga+10, 50, "Congratulations! You finished!");
                    else if(LANGUAGE == 2)
                        outtextxy(stanga+1.5*latura, 50, "Felicitari! Ai terminat!");
                    else
                        outtextxy(stanga, 50,"Félicitations! Vous avez fini!");
                }
            }else{
                setcolor(YELLOW);
                settextstyle(10, HORIZ_DIR, 4);
                if(LANGUAGE == 1)
                    outtextxy(stanga+2.5*latura, 50, "Try again!");
                else if(LANGUAGE == 2)
                    outtextxy(stanga+2.5*latura-5, 50, "Mai incearca!");
                else
                    outtextxy(stanga+2.5*latura, 50, "Réessayer!");
                delay(2000);
                outtextxy(stanga+2.5*latura-5, 50, "               ");
            }
        }
        //daca apasa pe butonul UNDO!
        else if(x>=stanga && x<=stanga+2*latura && y>=720 && y<=780 && !nivelTerminat && !sfarsit){
            Beep(423,100);
            if(!esteStivaVida(stivaUndo)){
                for(int i=0; i<4; i++){
                    int X = stivaUndo.tab[stivaUndo.varf].pozX;
                    int Y = stivaUndo.tab[stivaUndo.varf].pozY;
                    //se redeseneaza patratelul
                    setcolor(LIGHTCYAN);
                    setfillstyle(SOLID_FILL, LIGHTCYAN);
                    rectangle(stanga+latura*(X-1), sus+latura*(Y-1), stanga+latura*X, sus+latura*Y);
                    floodfill(stanga+latura*(X-1)+latura/2, sus+latura*(Y-1)+latura/2, LIGHTCYAN);
                    setcolor(LIGHTGRAY);
                    rectangle(stanga+latura*(X-1), sus+latura*(Y-1), stanga+latura*X, sus+latura*Y);
                    //se redeseneaza punctele (daca e necesar)
                    if(tabla[Y][X] == WHITE){
                        linia = Y;
                        coloana = X;
                        setcolor(WHITE);
                        setfillstyle(SOLID_FILL, WHITE);
                        circle(stanga+latura*(coloana-1)+latura/2, sus+latura*(linia-1)+latura/2, 20);
                        floodfill(stanga+latura*(coloana-1)+latura/2, sus+latura*(linia-1)+latura/2, WHITE);
                        setcolor(LIGHTGRAY);
                        circle(stanga+latura*(coloana-1)+latura/2, sus+latura*(linia-1)+latura/2, 20);
                    }else if(tabla[Y][X] == BLACK){
                        linia = Y;
                        coloana = X;
                        setcolor(BLACK);
                        setfillstyle(SOLID_FILL, BLACK);
                        circle(stanga+latura*(coloana-1)+latura/2, sus+latura*(linia-1)+latura/2, 20);
                        floodfill(stanga+latura*(coloana-1)+latura/2, sus+latura*(linia-1)+latura/2, BLACK);
                        setcolor(LIGHTGRAY);
                        circle(stanga+latura*(coloana-1)+latura/2, sus+latura*(linia-1)+latura/2, 20);
                    }else if(tabla[Y][X] == GRAY){
                        linia = Y;
                        coloana = X;
                        setcolor(WHITE);
                        setfillstyle(SOLID_FILL, WHITE);
                        circle(stanga+latura*(coloana-1)+latura/2, sus+latura*(linia-1)+latura/2, 20);
                        floodfill(stanga+latura*(coloana-1)+latura/2, sus+latura*(linia-1)+latura/2, WHITE);
                        setcolor(LIGHTGRAY);
                        circle(stanga+latura*(coloana-1)+latura/2, sus+latura*(linia-1)+latura/2, 20);
                        setcolor(BLACK);
                        line(stanga+latura*(coloana-1)+latura/2, sus+latura*(linia-1)+latura/2-20, stanga+latura*(coloana-1)+latura/2, sus+latura*(linia-1)+latura/2+20);
                        line(stanga+latura*(coloana-1)+latura/2-20, sus+latura*(linia-1)+latura/2, stanga+latura*(coloana-1)+latura/2+20, sus+latura*(linia-1)+latura/2);
                    }
                    tablaLogica[Y][X] = stivaUndo.tab[stivaUndo.varf].info;
                    if(helpSchimbatorCuloare == 0 && schimbatorCuloare != 0){
                        helpSchimbatorCuloare = 16;
                        schimbatorCuloare--;
                    }
                    helpSchimbatorCuloare-=.25;
                    pop(stivaUndo);
                }
            }
        }
        //daca apasa pe butonul HINT!
        else if(x>=stanga+10*latura && x<=stanga+12*latura && y>=sus+latura && y<=sus+latura+60){
            Beep(423,100);
            setcolor(LIGHTGRAY);
            rectangle(stanga+9.5*latura, sus+2.5*latura, stanga+12.5*latura, sus+5.5*latura);

            ///DACA ARE UN PUNCT DE SIMETRIE
            if(hint == 0){
                //"linia" verticala
                arc(stanga+11*latura, sus+2.875*latura, 270, 90, .375*latura);
                arc(stanga+11*latura, sus+3.625*latura, 90, 270, .375*latura);
                arc(stanga+11*latura, sus+4.375*latura, 270, 90, .375*latura);
                arc(stanga+11*latura, sus+5.125*latura, 90, 270, .375*latura);
                //"linia" orizontala
                arc(stanga+9.875*latura, sus+4*latura, 0, 180, .375*latura);
                arc(stanga+10.625*latura, sus+4*latura, 180, 360, .375*latura);
                arc(stanga+11.375*latura, sus+4*latura, 0, 180, .375*latura);
                arc(stanga+12.125*latura, sus+4*latura, 180, 360, .375*latura);
            ///DACA ARE 2 PUNCTE DE SIMETRIE-CAZ 1
            }else if(hint == 1){
                //linia ce imparte in doua (orizontala)
                line(stanga+9.5*latura, sus+4*latura, stanga+12.5*latura, sus+4*latura);
                //"linia" din partea de sus
                arc(stanga+10.625*latura, sus+2.5*latura, 180, 270, .375*latura);
                arc(stanga+10.625*latura, sus+3.25*latura, 0, 90, .375*latura);
                arc(stanga+11.375*latura, sus+3.25*latura, 180, 270, .375*latura);
                arc(stanga+11.375*latura, sus+4*latura, 0, 90, .375*latura);
                //"linia" din partea de jos
                arc(stanga+10.625*latura, sus+4*latura, 180, 270, .375*latura);
                arc(stanga+10.625*latura, sus+4.75*latura, 0, 90, .375*latura);
                arc(stanga+11.375*latura, sus+4.75*latura, 180, 270, .375*latura);
                arc(stanga+11.375*latura, sus+5.5*latura, 0, 90, .375*latura);
            ///DACA ARE 2 PUNCTE DE SIMETRIE-CAZ 2
            }else if(hint == 2){
                //linia ce imparte in doua (verticala)
                line(stanga+11*latura, sus+2.5*latura, stanga+11*latura, sus+5.5*latura);
                //"linia" din partea stanga
                arc(stanga+9.5*latura, sus+4.375*latura, 270, 360, .375*latura);
                arc(stanga+10.250*latura, sus+4.375*latura, 90, 180, .375*latura);
                arc(stanga+10.250*latura, sus+3.625*latura, 270, 360, .375*latura);
                arc(stanga+11*latura, sus+3.625*latura, 90, 180, .375*latura);
                //"linia" din partea dreapta
                arc(stanga+11*latura, sus+4.375*latura, 270, 360, .375*latura);
                arc(stanga+11.750*latura, sus+4.375*latura, 90, 180, .375*latura);
                arc(stanga+11.750*latura, sus+3.625*latura, 270, 360, .375*latura);
                arc(stanga+12.5*latura, sus+3.625*latura, 90, 180, .375*latura);
            }
            settextstyle(10, HORIZ_DIR, 2);
            if(LANGUAGE == 1){
                outtextxy(stanga+9.85*latura, sus+6*latura, "It should look");
                outtextxy(stanga+9.25*latura, sus+6.25*latura, "something like this...");
            }else if(LANGUAGE == 2){
                outtextxy(stanga+9.85*latura, sus+6*latura, "Ar trebui sa arate");
                outtextxy(stanga+9.25*latura+10, sus+6.25*latura, "cam in felul asta...");
            }else{
                outtextxy(stanga+9.85*latura-20, sus+6*latura, "Ça devrait resembler a");
                outtextxy(stanga+9.25*latura, sus+6.25*latura, "quelque chose comme ça...");
            }
        }
        //daca apasa pe butonul RESET!
        else if(x>=stanga-4*latura && x<=stanga-2*latura && y>=sus+latura && y<=sus+latura+60){
            Beep(423,100);
            outtextxy(stanga, 50,"                               ");
            //gata = true;
            nivelActual = 1;
            solutieActuala = 1;
            initStiva(stivaUndo);
            sfarsit = false;
            schimbatorCuloare = 0;
            helpSchimbatorCuloare = 0;
            creeazaTabla(nivelActual);
            creeazaTablaSolutie(solutieActuala);
            desen();
        }
        //daca apasa pe butonul BACK!
        else if(x>=stanga-4*latura && x<=stanga-2*latura && y>=sus+latura+100 && y<=sus+latura+160){
            if(nivelActual == 10){
                nivelActual = 1;
                solutieActuala = 1;
                initStiva(stivaUndo);
            }
            schimbatorCuloare = 0;
            helpSchimbatorCuloare = 0;
            Beep(423,100);
            cleardevice();
            gata = true;
            JOC = 0;
        }
        //daca apasa pe tabla
        else if(x>=stanga && x<=stanga+8*latura && y>=sus && y<=sus+8*latura)
        {
            linia = (y-sus)/latura+1;
            coloana = (x-stanga)/latura+1;

            int stare = 1;

            //schimba "vecinii" piesei in functie de punctele de simetrie ale nivelului
            piesa[0].pozX = linia;
            piesa[0].pozY = coloana;
            if(hint == 0){
                piesa[1].pozX = 8-linia+1;
                piesa[1].pozY = 8-coloana+1;
                piesa[2].pozX = coloana;
                piesa[2].pozY = 8-linia+1;
                piesa[3].pozX = 8-coloana+1;
                piesa[3].pozY = linia;
            }else if(hint == 2){
                if(coloana<=4){
                    piesa[1].pozX = linia;
                    piesa[1].pozY = coloana+4;
                    piesa[2].pozX = 8-linia+1;
                    piesa[2].pozY = 4-coloana+1;
                    piesa[3].pozX = 8-linia+1;
                    piesa[3].pozY = 8-coloana+1;
                }else{
                    piesa[1].pozX = linia;
                    piesa[1].pozY = coloana-4;
                    piesa[2].pozX = 8-linia+1;
                    piesa[2].pozY = 12-coloana+1;
                    piesa[3].pozX = 8-linia+1;
                    piesa[3].pozY = 8-coloana+1;
                }
            }else if(hint == 1){
                if(linia<=4){
                    piesa[1].pozX = 4+linia;
                    piesa[1].pozY = coloana;
                    piesa[2].pozX = 4-linia+1;
                    piesa[2].pozY = 8-coloana+1;
                    piesa[3].pozX = 8-linia+1;
                    piesa[3].pozY = 8-coloana+1;
                }else{
                    piesa[1].pozX = linia-4;
                    piesa[1].pozY = coloana;
                    piesa[2].pozX = 12-linia+1;
                    piesa[2].pozY = 8-coloana+1;
                    piesa[3].pozX = 8-linia+1;
                    piesa[3].pozY = 8-coloana+1;
                }
            }

            for(int i=0; i<4; i++){
                culoare = culoriUtilizabile[(i+schimbatorCuloare)%13];

                stare = stare + i; //ajusteaza tabla logica pentru restul pieselor
                //daca apasa pe o patratica cu o bila
                if(tablaLogica[piesa[i].pozX][piesa[i].pozY] == BILA_ALBA || tablaLogica[piesa[i].pozX][piesa[i].pozY] == BILA_NEAGRA || tablaLogica[piesa[i].pozX][piesa[i].pozY] == BILA_GRI){
                    push(stivaUndo, piesa[i].pozY, piesa[i].pozX, tablaLogica[piesa[i].pozX][piesa[i].pozY]);

                    setcolor(culoare);
                    setfillstyle(SOLID_FILL, culoare);
                    rectangle(stanga+latura*(piesa[i].pozY-1), sus+latura*(piesa[i].pozX-1), stanga+latura*piesa[i].pozY, sus+latura*piesa[i].pozX);
                    circle(stanga+latura*(piesa[i].pozY-1)+latura/2, sus+latura*(piesa[i].pozX-1)+latura/2, 20);
                    floodfill(stanga+latura*(piesa[i].pozY-1)+1, sus+latura*(piesa[i].pozX-1)+1, culoare);

                    setcolor(LIGHTGRAY);
                    rectangle(stanga+latura*(piesa[i].pozY-1), sus+latura*(piesa[i].pozX-1), stanga+latura*piesa[i].pozY, sus+latura*piesa[i].pozX);
                    circle(stanga+latura*(piesa[i].pozY-1)+latura/2, sus+latura*(piesa[i].pozX-1)+latura/2, 20);

                    tablaLogica[piesa[i].pozX][piesa[i].pozY] = stare;

                    helpSchimbatorCuloare+=.25;
                    if(helpSchimbatorCuloare == 16){
                        helpSchimbatorCuloare = 0;
                        schimbatorCuloare++;
                    }
                //daca apasa pe o patratica goala
                }else if(tablaLogica[piesa[i].pozX][piesa[i].pozY] == GOL){
                    push(stivaUndo, piesa[i].pozY, piesa[i].pozX, tablaLogica[piesa[i].pozX][piesa[i].pozY]);

                    setcolor(culoare);
                    setfillstyle(SOLID_FILL, culoare);
                    rectangle(stanga+latura*(piesa[i].pozY-1), sus+latura*(piesa[i].pozX-1), stanga+latura*piesa[i].pozY, sus+latura*piesa[i].pozX);
                    floodfill(stanga+latura*(piesa[i].pozY-1)+1, sus+latura*(piesa[i].pozX-1)+1, culoare);

                    setcolor(LIGHTGRAY);
                    rectangle(stanga+latura*(piesa[i].pozY-1), sus+latura*(piesa[i].pozX-1), stanga+latura*piesa[i].pozY, sus+latura*piesa[i].pozX);

                    tablaLogica[piesa[i].pozX][piesa[i].pozY] = stare;

                    helpSchimbatorCuloare+=.25;
                    if(helpSchimbatorCuloare == 16){
                        helpSchimbatorCuloare = 0;
                        schimbatorCuloare++;
                    }
                }
                stare = 1;
            }
        }
    }
}













///JOCUL 3
int stanga3,sus3,width3,height3,latura3, typeB=0,mat3[100][100],PLAYER=1,k3,matPlayer3[100][100];
bool gata3;
void joc3();
int bileOptime3();

//flood
void backtr(int i,int j,int arie);
int valid(int i,int j,int arie);


void backtr(int i,int j,int arie)
{

            if(valid( i, j,arie))
             {

                    backtr(i-1,j,arie);
                    backtr(i+1,j,arie);
                    backtr(i,j+1,arie);
                    backtr(i,j-1,arie);
             }

}


int valid(int i,int j,int arie)
{
    if(matPlayer3[i][j]==arie) {matPlayer3[i][j]=88;  return 1; }
    return 0;
}


int numarAparitii(int arie)
{
    int aparitie=0;
    for(int c=1;c<=numar3;c++)
        for(int p=1;p<=numar3;p++)
            if(matPlayer3[c][p]==arie)
        {

            backtr(c,p,arie);
            aparitie++;
            //cout<<endl;
        }
        return aparitie;
}


int flood()
{


    for(int c=1;c<=numar3;c++)
        if(numarAparitii(c)!=1)
            return 0;
    return 1;

}//flood


void afisare3(int corect) //afisam la final rezultatul solutiei date de p2
{
    PLAYER=3;
    gata3=false;
    if(corect && flood())   //afisare corect / incorect
    {   setcolor(LIGHTGRAY);
        settextstyle(10, HORIZ_DIR, 3);
        moveto(540,50);
        if(LANGUAGE == 1)
            outtext("CONGRATULATIONS! YOU WON!");
        else if(LANGUAGE == 2)
            outtext("FELICITARI! ATI REUSIT!");
        else
            outtextxy(580, 50, "FÉLICITATIONS!");
    }
    else
    {
        setcolor(LIGHTGRAY);
        settextstyle(10, HORIZ_DIR, 3);
        moveto(520,50);
        if(LANGUAGE == 1)
            outtext("SORRY! TRY AGAIN!");
        else if(LANGUAGE == 2)
            outtext("NE PARE RAU! MAI INCEARCA");
        else
            outtext("DÉSOLÉ! ESSAYER ENCORE");    //afisare corect/incorect
    }

     rectangle(50,50,200,100);  //buton pt reluarea jocului
     moveto(55,65);
     if(LANGUAGE == 1)
        outtextxy(75, 65, "Replay");
     else if(LANGUAGE == 2)
        outtext("Reia jocul");
     else
        outtextxy(70, 65, "Rejouer");

    while(PLAYER==3) //functie astfel incat sa apasam pe buton
        if(ismouseclick(WM_LBUTTONDOWN) )
            {
                clearmouseclick(WM_LBUTTONDOWN);
                int x=mousex();
                int y=mousey();
                if(x>50 &&y>50&& x<200 &&y<100) PLAYER=1,joc3(); //reiau jocul
                if(x>1200 && y>650 && x<1300 && y<700) {JOC=0; cleardevice(); gata3=true; PLAYER=1;}//menu
            }

}

int solutie3() //verificam daca P2 a impartit in mod corect careul
{
    int i,j,aria;
    int unu[20],doi[20],trei[20],patru[20],cinci[20];
    for(i=1;i<=20;i++)
        unu[i]=0,doi[i]=0,trei[i]=0,patru[i]=0,cinci[i]=0;

    for(i=1;i<=numar3;i++)    //vectori de frect]venta pentru fiecare tip de bila in parte
        for(j=1;j<=numar3;j++)
            {
                aria=matPlayer3[i][j];
                if(mat3[i][j]==11) unu[aria]++;
                if(mat3[i][j]==12) doi[aria]++;
                if(mat3[i][j]==13) trei[aria]++;
                if(mat3[i][j]==14) patru[aria]++;
                if(mat3[i][j]==15) cinci[aria]++;
            }
    for(i=2;i<=numar3;i++) //verificam daca fiecare arie are cate o bila de fiecare fel
        if((unu[i-1]!=unu[i]) || (doi[i-1]!=doi[i]) || (trei[i-1]!=trei[i]) || (patru[i-1]!=patru[i]) || (cinci[i-1]!=cinci[i]) )
            {
                afisare3(0);
                PLAYER=3;
                return 0;
            }
    afisare3(1);
    PLAYER=3;

    return 1;

}


int bileOptime3() //verific daca P1 a pus un nr optim de bile
{
    int i,j,frecv[20],oki=0;
    for(i=0;i<=20;i++)
        frecv[i]=0;
    for(i=1;i<=numar3;i++)
        for(j=1;j<=numar3;j++)
            frecv[mat3[i][j]]++;
    for(i=10;i<=15;i++)
        {
            if(frecv[i]!=0 && frecv[i]!=numar3) return 0;
            if(frecv[i]!=0) oki=1;
        }
    return oki;
}

void TrecerePl2() //trecerea de la player 1 la player 2, daca e cazul
{
    if(bileOptime3())
    {PLAYER=2;
                                //acoperire text
    setcolor(17);
    setfillstyle(SOLID_FILL,17);
    rectangle(500,50,1000,100);
    floodfill(625,55,17);

    setcolor(0);
    setfillstyle(SOLID_FILL,0);
    rectangle(500,50,1000,100);
    floodfill(625,55,0);            //acoperire text

    setcolor(17);         //acoperire margina stanga
    setfillstyle(SOLID_FILL,17);
    rectangle(0,0,120,800);
    floodfill(23,123,17);

    setcolor(0);
    setfillstyle(SOLID_FILL,0);
    rectangle(0,0,120,800);
    floodfill(23,123,0);      // acoperire margina stanga

    setcolor(17);         //acoperire "Player 2"
    setfillstyle(SOLID_FILL,17);
    rectangle(1200,50,1350,100);
    floodfill(1223,73,17);

    setcolor(0);
    setfillstyle(SOLID_FILL,0);
    rectangle(1200,50,1350,100);
    floodfill(1223,73,0);  //acoperire "player 2"


    }
    else
    {   setcolor(LIGHTGRAY);
        settextstyle(10, HORIZ_DIR, 1);
        if(LANGUAGE == 1)
            outtextxy(500, 50, "You don't have the correct number of dots!");
        else if(LANGUAGE == 2)
            outtextxy(520, 50, "Nu aveti un numar optim de bile!");
        else
            outtextxy(440, 50, "Vous n'avez pas le nombre correct de points!");
    }
}

void puneBilaPlayer1() //functia pentru P1
{
    int linia3,coloana3,x,y;
    if(ismouseclick(WM_LBUTTONDOWN) )
    {
        clearmouseclick(WM_LBUTTONDOWN);
        x=mousex();
        y=mousey();

        if (x>=stanga3 && x<=stanga3+width3 && y>=sus3&&y<=sus3+height3 ) //daca apasam in tabel
            {
                linia3=(y-sus3)/latura3+1;
                coloana3=(x-stanga3)/latura3+1;
                mat3[linia3][coloana3]=typeB;

                if(typeB==11)  //tipuri de bile
                    {
                        setcolor(2);//erase
                        setfillstyle(SOLID_FILL,2);
                        circle(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,12);
                        floodfill(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,2);
                        setcolor(0);
                        setfillstyle(SOLID_FILL,0);
                        circle(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,12);
                        floodfill(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,0);//erase

                        setcolor(1);
                        setfillstyle(SOLID_FILL,1);
                        circle(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,10);
                        floodfill(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,1);
                    }
            if(typeB==12)
                    {
                        setcolor(2);//erase
                        setfillstyle(SOLID_FILL,2);
                        circle(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,12);
                        floodfill(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,2);
                        setcolor(0);
                        setfillstyle(SOLID_FILL,0);
                        circle(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,12);
                        floodfill(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,0);//erase

                        setcolor(5);
                        circle(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,10);
                        circle(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,7);
                        circle(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,4);
                    }
            if(typeB==13)
                    {
                        setcolor(2);//erase
                        setfillstyle(SOLID_FILL,2);
                        circle(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,12);
                        floodfill(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,2);
                        setcolor(0);
                        setfillstyle(SOLID_FILL,0);
                        circle(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,12);
                        floodfill(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,0);//erase

                        setcolor(12);
                        circle(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,10);
                        setfillstyle(SOLID_FILL,12);
                        circle(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,5);
                        floodfill(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,12);
                    }
            if(typeB==14)
                    {
                        setcolor(2);//erase
                        setfillstyle(SOLID_FILL,2);
                        circle(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,12);
                        floodfill(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,2);
                        setcolor(0);
                        setfillstyle(SOLID_FILL,0);
                        circle(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,12);
                        floodfill(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,0);//erase

                        setcolor(11);
                        circle(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,10);
                        setcolor(10);
                        circle(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,9);
                        setcolor(9);
                        circle(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,8);
                        setcolor(7);
                        circle(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,7);
                        setcolor(8);
                        circle(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,6);
                        setcolor(6);
                        circle(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,5);
                        setcolor(5);
                        circle(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,4);
                        setcolor(4);
                        circle(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,3);
                        setcolor(4);
                        circle(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,2);
                    }
            if(typeB==15)
                    {
                        setcolor(2);//erase
                        setfillstyle(SOLID_FILL,2);
                        circle(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,12);
                        floodfill(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,2);
                        setcolor(0);
                        setfillstyle(SOLID_FILL,0);
                        circle(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,12);
                        floodfill(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,0);//erase

                        setcolor(10);
                        circle(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,10);
                        circle(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,11);
                        line(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2-10,stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2+10);
                        line(stanga3+latura3*(coloana3-1)+latura3/2-1,sus3+latura3*(linia3-1)+latura3/2-10,stanga3+latura3*(coloana3-1)+latura3/2-1,sus3+latura3*(linia3-1)+latura3/2+10);
                        line(stanga3+latura3*(coloana3-1)+latura3/2+1,sus3+latura3*(linia3-1)+latura3/2-10,stanga3+latura3*(coloana3-1)+latura3/2+1,sus3+latura3*(linia3-1)+latura3/2+10);
                        line(stanga3+latura3*(coloana3-1)+latura3/2-10,sus3+latura3*(linia3-1)+latura3/2+1,stanga3+latura3*(coloana3-1)+latura3/2+10,sus3+latura3*(linia3-1)+latura3/2 +1);
                        line(stanga3+latura3*(coloana3-1)+latura3/2-10,sus3+latura3*(linia3-1)+latura3/2,stanga3+latura3*(coloana3-1)+latura3/2+10,sus3+latura3*(linia3-1)+latura3/2 );
                        line(stanga3+latura3*(coloana3-1)+latura3/2-10,sus3+latura3*(linia3-1)+latura3/2-1,stanga3+latura3*(coloana3-1)+latura3/2+10,sus3+latura3*(linia3-1)+latura3/2 -1);

                    }//tipuri de bile
            if(typeB==0)//radiera
                    {
                        setcolor(2);
                        setfillstyle(SOLID_FILL,2);
                        circle(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,12);
                        floodfill(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,2);
                        setcolor(0);
                        setfillstyle(SOLID_FILL,0);
                        circle(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,12);
                        floodfill(stanga3+latura3*(coloana3-1)+latura3/2,sus3+latura3*(linia3-1)+latura3/2,0);
                    }

            Beep(523,200);

        }   // DACA APAS IN CAREU

        //schimbam tipul de bila apasand pe buton
        if(x>50 && y>50 && x< 100 && y<100) typeB=11;
        if(x>50 && y>150 && x< 100 && y<200) typeB=12;
        if(x>50 && y>250 && x< 100 && y<300) typeB=13;
        if(x>50 && y>350 && x< 100 && y<400) typeB=14;
        if(x>50 && y>450 && x< 100 && y<500) typeB=15;
        if(x>50 && y>650 && x<100 && y<700) typeB=0;
        if(x>1200 && y>50 && x<1300 && y<100) {TrecerePl2(); Beep(500,300);Beep(450,300);Beep(550,300);Beep(600,300);}//apas pe player 2
        if(x>1200 && y>650 && x<1300 && y<700) {JOC=0; cleardevice(); gata3=true;}
    } // PLAYER 1
}


void puneBilaPlayer2() //functia pentru P2
{
    int linia,coloana,x,y;
    if(ismouseclick(WM_LBUTTONDOWN))
        {
        clearmouseclick(WM_LBUTTONDOWN);
        x=mousex();
        y=mousey();
        if(k3==numar3*numar3-1) PLAYER=0;
        if (x>=stanga3 && x<=stanga3+width3 && y>=sus3&&y<=sus3+height3 ) //daca apasam in careu
        {
            linia=(y-sus3)/latura3+1;
            coloana=(x-stanga3)/latura3+1;

            if(matPlayer3[linia][coloana]==0 || matPlayer3[linia][coloana]>=10) //desenam ariile selectate
            {
                setcolor(k3/numar3+1);
                circle(stanga3+latura3*(coloana-1)+latura3/2,sus3+latura3*(linia-1)+latura3/2,11);
                circle(stanga3+latura3*(coloana-1)+latura3/2,sus3+latura3*(linia-1)+latura3/2,12);
                circle(stanga3+latura3*(coloana-1)+latura3/2,sus3+latura3*(linia-1)+latura3/2,13);
                circle(stanga3+latura3*(coloana-1)+latura3/2,sus3+latura3*(linia-1)+latura3/2,14);
                circle(stanga3+latura3*(coloana-1)+latura3/2,sus3+latura3*(linia-1)+latura3/2,15);
                circle(stanga3+latura3*(coloana-1)+latura3/2,sus3+latura3*(linia-1)+latura3/2,16);
                circle(stanga3+latura3*(coloana-1)+latura3/2,sus3+latura3*(linia-1)+latura3/2,17);
                circle(stanga3+latura3*(coloana-1)+latura3/2,sus3+latura3*(linia-1)+latura3/2,18);
                circle(stanga3+latura3*(coloana-1)+latura3/2,sus3+latura3*(linia-1)+latura3/2,19); //desenam ariile selectate

                matPlayer3[linia][coloana]=k3/numar3+1;//creem matricea playerului cu ariile stabilite de el
                k3++;
            }
        }
        if(x>1200 && y>650 && x<1300 && y<700) {JOC=0; cleardevice(); gata3=true;}//menu
         Beep(500+k3*10,200);
}
}

void desen3()
{
    int i,j;
   //desenam careul
    width3=400;
    height3=400;
    setcolor(LIGHTGRAY);
    latura3=width3/numar3;
    sus3=(getmaxy()-width3)/2;
    stanga3=(getmaxx()-height3)/2;
    rectangle(stanga3-5,sus3-5,stanga3-5+400,sus3-5+400); //efect visual +-5
    rectangle(stanga3+5,sus3+5,stanga3+5+400,sus3+5+400);
    for(i=1; i<=numar3; i++)
        for(j=1; j<=numar3; j++)
            rectangle(stanga3+latura3*(i-1),sus3+latura3*(j-1),stanga3+latura3*i,sus3+latura3*j);
    setcolor(LIGHTGRAY);
    rectangle(50,50,100,100);//prima bila
    setcolor(1);

    circle(75,75,10);
    floodfill(75,75,1); //

    setcolor(LIGHTGRAY);  //a doua bila
    rectangle(50,150,100,200);
    setcolor(5);
    circle(75,175,10);
    circle(75,175,7);
    circle(75,175,4); //

    setcolor(LIGHTGRAY); // a treia bila
    rectangle(50,250,100,300);
    setcolor(12);
    circle(75,275,10);
    setfillstyle(SOLID_FILL,12);
    circle(75,275,5);
    floodfill(75,275,12); //

    setcolor(LIGHTGRAY); // a patra bila
    rectangle(50,350,100,400);
    setcolor(11);
    circle(75,375,10);
    setcolor(10);
    circle(75,375,9);
    setcolor(9);
    circle(75,375,8);
    setcolor(7);
    circle(75,375,7);
    setcolor(8);
    circle(75,375,6);
    setcolor(6);
    circle(75,375,5);
    setcolor(5);
    circle(75,375,4);
    setcolor(4);
    circle(75,375,3);
    setcolor(4);
    circle(75,375,2);
                 //

    setcolor(LIGHTGRAY); // a cincea bila
    rectangle(50,450,100,500);
    setcolor(10);
    circle(75,475,10);
    circle(75,475,11);
    line(75,465,75,485);
    line(74,465,74,485);
    line(76,465,76,485);
    line(65,474,85,474);
    line(65,475,85,475);
    line(65,476,85,476);
        //                    //
    setcolor(LIGHTGRAY);
    moveto(46,625);// eraser
    settextstyle(10, HORIZ_DIR, 1);
    if(LANGUAGE == 1)
        outtext("Eraser");
    else if(LANGUAGE == 2)
        outtext("Radiera");
    else
        outtext("Gomme");

    rectangle(50,650,100,700);
    setcolor(12);
    line(68,659,83,659);
    line(68,658,83,658);
    line(68,657,83,657);
    setfillstyle(SOLID_FILL,12);
    rectangle(65,660,85,675);
    floodfill(66,661,12);
    setcolor(1);
    line(68,691,83,691);
    line(68,692,83,692);
    line(68,691,83,691);
    line(68,693,83,693);
    setfillstyle(SOLID_FILL,1);
    rectangle(65,675,85,690);
    floodfill(66,676,1);
    setcolor(11);
    line(70,657,70,693);  //eraser

    setcolor(LIGHTGRAY);   //player 2
    rectangle(1200,50,1300,100);
    moveto(1207,65);
    settextstyle(10, HORIZ_DIR, 1);
    outtext("Player 2");


    rectangle(1200,650,1300,700);
    if(LANGUAGE == 1)
        outtextxy(1226,666,"Back");
    else if(LANGUAGE == 2)
        outtextxy(1220, 666, "Inapoi");
    else
        outtextxy(1205, 666, "Derniere");
}


void joc3()
{   k3=0;
    PLAYER=1;
    int f,g;
    for(f=0;f<=numar3;f++)
    for(g=0;g<=numar3;g++)
       mat3[f][g]=0,matPlayer3[f][g]=0; //initializam cu valoarea 0

    cleardevice();
    desen3();

    gata3=false;
    do
        {
            if(PLAYER==1)
                puneBilaPlayer1();

            if(PLAYER==2)
                puneBilaPlayer2();

            if(PLAYER==0) //verificarea solutiei
                cout<<solutie3();

        }
    while (!gata3);



}












///JOCUL 4
void desenSet()
{
    conNr();


    setcolor(YELLOW);//buton back
    rectangle(200,600,300,650);
    rectangle(205,605,305,655);
    rectangle(195,595,295,645);
    moveto(228,615);
    settextstyle(10, HORIZ_DIR, 2);
    if(LANGUAGE==1) outtext("Menu ");
            if(LANGUAGE==2)  outtextxy(223,615,"Meniu");
            if(LANGUAGE==3)  outtext("Menu ");



      moveto(200,60);
 settextstyle(10, HORIZ_DIR, 6);
 if(LANGUAGE==1) outtext("SETTINGS    ");
            if(LANGUAGE==2)  outtext("SETARI     ");
            if(LANGUAGE==3)  outtext("RÉGLAGE          ");


          moveto(200,160);
 settextstyle(10, HORIZ_DIR, 2);
 if(LANGUAGE==1) outtext("The size of the third game's square              ");
            if(LANGUAGE==2)  outtext("Dimensiunea tablei de la jocul 3      ");
            if(LANGUAGE==3)  outtext("La taille de la troisième jeue carré  ");


       moveto(250,200);

       outtext(intChar[numar3]);

      line(240,200,240,220); //sageata stg
        line(240,200,220,210);
        line(240,220,220,210);
//rectangle(280,200,300,220);
//rectangle(220,200,240,220);

       line(280,200,280,220); // sageata drp
        line(280,200,300,210);
        line(280,220,300,210);




         moveto(200,260);
 settextstyle(10, HORIZ_DIR, 2);
 if(LANGUAGE==1) outtext("Language");
            if(LANGUAGE==2)  outtext("Limba      ");
            if(LANGUAGE==3)  outtext("Langue     ");


       moveto(250,300);
       if(LANGUAGE==1) outtext(" English");
       if(LANGUAGE==2)  outtext("  Romana");
       if(LANGUAGE==3)  outtext("Français");



        line(240,300,240,320); //sageata stg
        line(240,300,220,310);
        line(240,320,220,310);

      // rectangle(350,300,370,320); dr
      // rectangle(220,300,240,320); st

        line(350,300,350,320); //sageata drp
        line(350,300,370,310);
        line(350,320,370,310);

        if(LANGUAGE == 1)
            outtextxy(200, 360, "Music:");
        else if(LANGUAGE == 2)
            outtextxy(200, 360, "Muzica:");
        else
            outtextxy(200, 360, "Musique:");
        if(MUSIC)
            outtextxy(250, 400, " ON");
        else
            outtextxy(250, 400, "OFF"),PlaySound(NULL,0,0);

        line(300,400,300,420); //sageata drp
        line(300,400,320,410);
        line(300,420,320,410);

        line(240,400,240,420); //sageata stg
        line(240,400,220,410);
        line(240,420,220,410);
}

void conNr()
{
     strcpy(intChar[1],"1 ");
    strcpy(intChar[2],"2 ");
    strcpy(intChar[3],"3 ");
    strcpy(intChar[4],"4 ");
    strcpy(intChar[5],"5 ");
    strcpy(intChar[6],"6 ");
    strcpy(intChar[7],"7 ");
    strcpy(intChar[8],"8 ");
    strcpy(intChar[9],"9 ");
    strcpy(intChar[10],"10");
    strcpy(intChar[11],"11");
    strcpy(intChar[12],"12");
    strcpy(intChar[13],"13");
    strcpy(intChar[14],"14");
    strcpy(intChar[15],"15");
}

void mouseSet()
{
    if(ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
       int x=mousex();
        int y=mousey();
        if(x>220 && y>200&& x<240 && y<220)
            {   if(numar3==1) numar3=16;
                numar3--;
            moveto(250,200);
            outtext(intChar[numar3]);}
        if(x>280&& y>200 && x<300 && y<220)
            {  if(numar3==15) numar3=0;
                numar3++;
            moveto(250,200);
            outtext(intChar[numar3]);}
         if(x>350 &&y>300 && x<370 && y<320)
         {  if(LANGUAGE==3) LANGUAGE=0;

             LANGUAGE++;
              moveto(250,300);
            if(LANGUAGE==1) outtext(" English");
            if(LANGUAGE==2)  outtext("  Romana");
            if(LANGUAGE==3)  outtext("Français");
         }
         if(x>220 && y> 300 && x<240 && y<320)
         {
             if(LANGUAGE==1) LANGUAGE=4;
             LANGUAGE--;

              moveto(250,300);
              if(LANGUAGE==1) outtext(" English");
            if(LANGUAGE==2)  outtext("  Romana");
            if(LANGUAGE==3)  outtext("Français");

         }
         if(x>200 && y>600 && x<300 && y<650) //buton back
         {   cleardevice();
             JOC=0;
             stay=0;

         }
         if((x >300 && y>400 && x< 320&& y<420) || (x>220&& y>400 && x<240 &&y<420)){
            MUSIC = !MUSIC;
            if(MUSIC)
                outtextxy(250, 400, " ON"),PlaySound("Darude_Sandstorm_by_Darude.wav", NULL, SND_LOOP | SND_ASYNC);
            else
                outtextxy(250, 400, "OFF"),PlaySound(NULL,0,0);
         }







    }
}

void setari()
{
    desenSet();
    stay=0;
    do
     {
         mouseSet();
     }
    while(stay);
}








int main()
{
    initwindow(1400,800);

    while(!GATA){
        if(JOC==0){
            if(MUSIC)
                PlaySound("Darude_Sandstorm_by_Darude.wav", NULL, SND_LOOP | SND_ASYNC);
            else
                PlaySound(NULL, 0, 0);
            menu();
        }
        if(JOC==1){
            int q,w;
            for(q=1;q<=8;q++)
                for(w=1;w<=8;w++)
                    a[q][w]=copie[q][w];
            backk=0;
            gata1=false;
            conversieNr();
            nivelNou();
        }
        if(JOC==2){
            initStiva(stivaUndo);
            creeazaTabla(nivelActual);
            creeazaTablaSolutie(solutieActuala);
            desen();
            gata=false;
            do{
                actiune();
            }while (!gata);
        }
        if(JOC==3){
            joc3();
        }
        if(JOC==4){
            setari();
        }
    }

    //getch();
    closegraph();
    return 0;
}
