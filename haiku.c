#include <conio.h>
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <c64/charwin.h>
#include <c64/kernalio.h>
#include <c64/vic.h>
#include <gfx/vector3d.h>
#include <stdio.h>
#include "scanner.h"    /*needed for input*/
#include "parser.h"

#define Screen  ((byte * ) 0xc800)
int k;
int arraycols, arrayrows,sumhere;
int arraycolsb, arrayrowsb;

int i,j, xpos, ypos;
int listlength;
int z;
char c;
char inputstring[25];
char oneline[25];
char tmpstring[25];
char tempstring[25];

char charstring[25];
char spaces[41];
CharWin * win;

struct CharWin cwin;
struct CharWin inputwin;
struct CharWin msgwin;
struct CharWin outputwin;


int syl1[] = {35,105,109,110,111,116,122,124,126,162,163,164,165,175,177,179};
int syl2[] = {95,36,96,101,103,104,106,107,113,114,115,118,119,125,159,167,168,169,172,174,176,178};
int syl3[] = {33,39,62,63,97,98,102,112,161,170,171};
int syl4[] = {100,108,120,123,173};
int syl5[] = {99};

int n = 20;
int hcount = 17;
int hrand =  0; int lrand = 0;

int okrand; int okword = 0;


byte data[] = { 
#embed "apl.bin" 
}; 
char  oxpos = 0;
int isneg = 0;
char nl[3];  
char newl = 13;
int position = 0;


void checkScroll(CharWin * win)
{
        if (win->cy == win->wy)
        {
                win->cy--;
                cwin_scroll_up(win, 1);
                cwin_fill_rect(win, 0, win->wy - 1, win->wx, 1, ' ', 1);
        }
}

void printLn(CharWin * win)
{
        win->cy++;
        win->cx = 0;
        checkScroll(win);
}

void print(CharWin * win, const char * str, char color)
{
        char len = strlen(str);
        if (win->cx + len > 40)
                printLn(win);

        cwin_put_string(win, str, color);
        checkScroll(win);
}

void printline()
{
   int i; int n; int z;
   n = strlen(inputstring);
//   for (i=0; i<n; i++) {
//     printf("%d  ", inputstring[i]);
//     }
for (z=0; z< strlen(inputstring); z++) { 
///////for (z=0; z<18; z++) {
switch (inputstring[z]) {
    case 61: {
     printf("EQUALS  ",inputstring[1]);

       break;
    }

    case 91: {
     printf("SECOND ",inputstring[1]);

       break;
    }
    case 92: {
     printf("UNDETERMINED ",inputstring[1]);

       break;
    }

case 65:  {
     printf("A");
       break;
    }

case 66:  {
     printf("B");
       break;
    }

case 67:  {
     printf("C");
       break;
    }

case 68:  {
     printf("D");
       break;
    }

case 69:  {
     printf("E");
       break;
    }
case 70:  { printf("F"); break; }

case 71:  { printf("G"); break; }
case 72:  { printf("H"); break; }
case 73:  { printf("I"); break; }
case 74:  { printf("J"); break; }
case 75:  { printf("K"); break; }
case 76:  { printf("L"); break; }
case 77:  { printf("M"); break; }
case 78:  { printf("N"); break; }
case 79:  { printf("O"); break; }
case 80:  { printf("P"); break; }

case 81:  { printf("Q"); break; }
case 82:  { printf("R"); break; }
case 83:  { printf("S"); break; }
case 84:  { printf("T"); break; }
case 85:  { printf("U"); break; }
case 86:  { printf("V"); break; }
case 87:  { printf("W"); break; }
case 88:  { printf("X"); break; }
case 89:  { printf("Y"); break; }
case 90:  { printf("Z"); break; }
    case 93: {
     printf("YEAR ",inputstring[1]);

       break;
    }

    case 95: {
     printf("UNION ",inputstring[1]);

       break;
    }
case 32: {printf(" "); break;
    }

   case 33: {
     printf("NEGATION ",inputstring[1]);

       break;
    }
   case 35: {
     printf("MATH ",inputstring[1]);

       break;
    }

   case 36: {
     printf("DELTA ",inputstring[1]);

       break;
    }
   case 39: {
     printf("RADIUS ",inputstring[1]);

       break;
    }

   case 62: {
     printf("HYDROGEN ",inputstring[1]);
       break;

    }

   case 63: {
     printf("HELIUM ",inputstring[1]);
       break;

    }

   case 96: {
     printf("CARBON ",inputstring[1]);
       break;

    }


   case 97: {
     printf("NITROGEN ",inputstring[1]);
       break;
    }


   case 98: {
     printf("OXYGEN ",inputstring[1]);
       break;
    }

   case 99: {
     printf("ALUMINIUM ",inputstring[1]);
       break;
    }

   case 100: {
     printf("SILICIUM ",inputstring[1]);
       break;
    }

   case 101: {
     printf("IRON ",inputstring[1]);
       break;
    }

   case 102: {
     printf("SODIUM ",inputstring[1]);
       break;
    }

   case 103: {
     printf("CHLORINE ",inputstring[1]);
       break;
    }

   case 104: {
     printf("ARGON ",inputstring[1]);
       break;
    }
   case 105: {
     printf("GOLD ",inputstring[1]);
       break;
    }
   case 106: {
     printf("SILVER ",inputstring[1]);
       break;
    }
   case 107: {
     printf("SULFUR ",inputstring[1]);
       break;
    }
   case 108: {
     printf("URANIUM ",inputstring[1]);
       break;
    }
   case 109: {
     printf("ZINC ",inputstring[1]);
       break;
    }
   case 110: {
     printf("TIME ",inputstring[1]);
       break;
    }
   case 111: {
     printf("FORCE ",inputstring[1]);
       break;
    }
   case 112: {
     printf("ENERGY ",inputstring[1]);
       break;
    }
   case 113: {
     printf("PRESSURE ",inputstring[1]);
       break;
    }

   case 114: {
     printf("POWER ",inputstring[1]);
       break;
    }

   case 115: {
     printf("DISTANCE ",inputstring[1]);
       break;
    }
   case 116: {
     printf("CHARGE ",inputstring[1]);
       break;
    }
//   case 117: {
 //    printf("DISTANCE ",inputstring[1]);
  //     break;
   // }
   case 118: {
     printf("PHYSICS ",inputstring[1]);
       break;
    }
   case 119: {
     printf("PHOTON ",inputstring[1]);
       break;
    }
   case 120: {
     printf("TEMPERATURE ",inputstring[1]);
       break;
    }
   

   case 122: {
     printf("CELL ",inputstring[1]);
       break;
    }
   case 123: {
     printf("BIOLOGY ",inputstring[1]);
       break;
    }

   case 124: {
     printf("MALE ",inputstring[1]);
       break;
    }
  case 125: {
     printf("FEMALE ",inputstring[1]);
       break;
    }

  case 126: {
     printf("PI ",inputstring[1]);
       break;
    }



////done to here

  case 223: {
     printf("PEOPLE ",inputstring[1]);
       break;
    }
    case 159: {
     printf("PEOPLE ",inputstring[1]);

       break;
    }
    case 161: {
     printf("JUPITER ",inputstring[1]);

       break;
    }
    case 162: {
     printf("EARTH ",inputstring[1]);

       break;
    }
    case 163: {
     printf("MOON ",inputstring[1]);

       break;
    }

    case 164: {
     printf("SUN ",inputstring[1]);

       break;
    }
    case 165: {
     printf("MARS ",inputstring[1]);

       break;
    }
    case 166: {
     printf("MERCURY ",inputstring[1]);

       break;
    }
    case 167: {
     printf("NEPTUNE ",inputstring[1]);

       break;
    }
    case 168: {
     printf("PLUTO ",inputstring[1]);

       break;
    }
    case 169: {
     printf("SATURN ",inputstring[1]);

       break;
    }


    case 170: {
     printf("UNIVERSE ",inputstring[1]);

       break;
    }
///add others, planets, vars

    case 171: {
     printf("URANUS ",inputstring[1]);

       break;
    }
    case 172: {
     printf("VENUS ",inputstring[1]);

       break;
    }
    case 173: {
     printf("ETC ",inputstring[1]);

       break;
    }
    case 174: {
     printf("QUESTION ",inputstring[1]);

       break;
    }
    case 175: {
     printf("LAND ",inputstring[1]);

       break;
    }
    case 176: {
     printf("OCEAN ",inputstring[1]);

       break;
    }
    case 177: {
     printf("SKY ",inputstring[1]);

       break;
    }
    case 178: {
     printf("TARGET ",inputstring[1]);

       break;
    }
    case 179: {
     printf("AGE ",inputstring[1]);

       break;
    }
    case 180: {
     printf("VAR A ",inputstring[1]);

       break;
    }
    case 181: {
     printf("VAR B ",inputstring[1]);

       break;
    }
    case 182: {
     printf("VAR C  ",inputstring[1]);

       break;
    }


    default: {
        putchar(inputstring[i]);
        printf("%c",inputstring[i]);
     }
    } /////////switch
} //printline
}

void corral(){
  for (i = 0; i < 120; i++) Screen[i] = i;

//  for (i = 120; i < 160; i++) Screen[i] = 35;  //box character
  *(char *) 0xd021 = 0x06;  //border color
  for (i = 0; i < 120; i++) { ( * (char * )(0xd800 + i)) = 1; }
// color boxes for palette
  //for (i = 0; i < 40; i++) { ( * (char * )(0xd878 + i)) = i; } 
}

int main(void) {
struct VectorV *vec = (struct VectorV*) malloc(sizeof(struct VectorV));

//  char inputstring[25];
 // char tmpstring[25];
strcpy(spaces, "                                        ");
nl[0] = 13;
nl[1] = 10;
nl[2] = 0;
//int  r=srand(5);

  int notassignment = 0;
  struct node * foundLink;
  struct node * foundLink2;
  size_t size;
  int val,len;

  int storeindex = 0;
  int linenotdone = 1;
  char storechar = 0;
  xpos = 0;
  ypos = 0;
  memcpy((char * ) 0xe000, data, 1024); //APL charset loads into $e000
  *(char * ) 648 = 0xc8; // POKE 648,40;
  vic_setbank(3); // nice high-level way to move the sundry charset
  vic.memptr = 0x28; // settings into place in oscar64!
  for (i = 0; i < 1024; i++) Screen[i] = 32;
//create output charwin
//draw output bench  border on line 7
   cwin_init(&outputwin, (char *)0xc800, 0, 10, 40, 15);
   cwin_clear(&outputwin);
//   cwin_fill(&outputwin, 15, 5);

   cwin_init(&inputwin, (char *)0xc800, 0, 4, 40, 2);
   cwin_clear(&inputwin);
   cwin_fill(&inputwin, 32, 5);


   cwin_init(&msgwin, (char *)0xc800, 0, 7, 40, 2);
   cwin_clear(&msgwin);


///

///
//nope *(char*)0xcc = 0;
  while (1) {
    corral();

    linenotdone = 1;
    c = 1; //dummy not 0 value
    for (i=0; i<25; i++) {
    tmpstring[i] = 0;
    inputstring[i]=0;
    } //clean up for next run

    while (linenotdone) {
      while (c != 13) { ////exit chargetting loop if return key hit

        //cgetc
//
//;$00C6	Number of characters in keyboard buffer
//;$00CC	Flag	Flash cursor 0 = yes, otherwise no
//;$00CD	for cursor flashing, default 20, decreased every jiffy
//;$00CE        Character at cursor position
//;$00CF        Flag	Cursor flash phase 0 = visible, >0 invisible
        __asm {
          loc1ebd: LDA $C6      //Number of characters in keyboard buffer
          loc1ebf: BNE loc1ed8  //if  chars in buffer jump to charsinbuffer
          loc1ec1: LDA $CC      //Flash cursor 0 = yes, otherwise no
          PHA
          LDA #$01
          JSR loc1ede
          loc1eca: LDA $C6      //# of chars waiting in buffer
          loc1ecc: BEQ loc1eca
          LDX #$00
          PLA
          BNE loc1ed4
          INX
          loc1ed4: TXA
          JSR loc1ede
          loc1ed8: JSR $e5b4
          sta $c878           //stores to $c878   line 4 first car
          LDX #$00
//          RTS
          JMP done
          loc1ede: TAX
          BNE loc1eff
          LDA $CC                //Flash cursor 0 = yes, otherwise no
          BNE loc1efe            //its flashing go to RTS
          LDA #$01               // not flashing
          STA $CC                // turn off cursor
          LDA $CF                //get cursor phase
          BEQ loc1efa           
          LDY $D3
          LDA($D1), Y
          EOR #$80
          STA($D1), Y
          LDA $0287              //color under the cursor
          STA($F3), Y
          loc1efa: LDA #$00
          STA $CF                //0 into $cf makes cursor visible
          loc1efe: // RTS
          jmp done
          loc1eff: LDA #$00
          STA $CC
//          RTS
          done:
        }
        c = * (char * ) 0xc878;   // the magic location stored char into c
        * (char * ) 0xc878   = 32;  //then blank  magic location
        //printf("C IS %c %d ", c, c);
        if (c == 157) {
          xpos--;
          xpos--;
          if (xpos < 0) {
            xpos = 39;
          }

          gotoxy(xpos, ypos);
        } else if (c == 29) {
          xpos++;
          if (xpos > 39) {
            xpos = 0;
          }

          gotoxy(xpos, ypos);
        } else if (c == 17) {
          ypos++;
          if (ypos > 3) {
            ypos = 0;
          }
          gotoxy(xpos, ypos);


        } else if (c == 145) {
          ypos--;
          if (ypos < 0) {
            ypos = 2;
          }
          gotoxy(xpos, ypos);

        } else if (c == 35) {
              inputstring[storeindex] = 0;
              storeindex--;

        } else if ( ((c >= 48) && (c <= 57))  ||
                    ((c >= 65) && (c <= 90))  ||
                    ((c == 32)             )  ||
                    ((c>45)  )    //any key but some break it
                  )
          {
          inputstring[storeindex++] = c;
          //terminate it with null
          inputstring[storeindex + 1] = 0;
          gotoxy(0, 5);
          printf("%s", inputstring);
//   cwin_clear(&msgwin);
//   cwin_putat_string(&msgwin, 0, 0, inputstring,3);





        } else if (c == 13) {
          ypos = 0;
          xpos = 0;
          __asm {
            lda $ce
            sta $c8f3
          }
          storechar = * (char * ) 0xc8f3;
* (char * ) 0xc8f3 = 32;  //blank it
          if (storechar == 0) {
            linenotdone = 0;
            gotoxy(12, 12);
//            printf("GOT NULL PARSE THIS %s \n", inputstring);
  cwin_clear(&inputwin);
   cwin_fill(&inputwin, 32, 5);

  cwin_putat_string(&inputwin, 0, 0, inputstring,13);
    break;
          }

          *(char * )(1400 + storeindex) = storechar;
          if ((storechar >= 1) && (storechar <= 31)) //char, add 64
          {
            storechar += 64;
          } else if ((storechar >= 64) && (storechar <= 94)) //char, add 64
          {
            storechar += 32;
          } else if ((storechar >= 95) && (storechar <= 119)) //char, add 64
          {
            storechar += 64;
          }

          inputstring[storeindex++] = storechar;
          //terminate it with null
          inputstring[storeindex + 1] = 0;
          gotoxy(0, 5);
          printf("%s", inputstring);
          gotoxy(xpos, ypos);
        }
        c = 1; //reset from 13
      } 
    } 
    storeindex = 0;
 
//    __asm {
//      lda $ce
//      sta $c8f1
//        }


////
//printline();
cwin_clear(&outputwin);

//printf("OKOK\n");
for (z=0; z< strlen(inputstring); z++) { 
switch (inputstring[z]) {
    case 61: { printf("EQUALS  "); break; } 
    case 91: { printf("SECOND "); break; }
    case 92: { printf("UNDETERMINED "); break; }
case 65:  { printf("A"); break; } 
case 66:  { printf("B"); break; } 
case 67:  { printf("C"); break; } 
case 68:  { printf("D"); break; } 
case 69:  { printf("E"); break; }
case 70:  { printf("F"); break; }
case 71:  { printf("G"); break; }
case 72:  { printf("H"); break; }
case 73:  { printf("I"); break; }
case 74:  { printf("J"); break; }
case 75:  { printf("K"); break; }
case 76:  { printf("L"); break; }
case 77:  { printf("M"); break; }
case 78:  { printf("N"); break; }
case 79:  { printf("O"); break; }
case 80:  { printf("P"); break; }
case 81:  { printf("Q"); break; }
case 82:  { printf("R"); break; }
case 83:  { printf("S"); break; }
case 84:  { printf("T"); break; }
case 85:  { printf("U"); break; }
case 86:  { printf("V"); break; }
case 87:  { printf("W"); break; }
case 88:  { printf("X"); break; }
case 89:  { printf("Y"); break; }
case 90:  { printf("Z"); break; }
   case 93: { printf("YEAR "); break; }
   case 95: { printf("UNION "); break; }
   case 32: {printf(" "); break; }
   case 33: { printf("NEGATION "); break; }
   case 35: { printf("MATH "); break; }
   case 36: { printf("DELTA "); break; }
   case 39: { printf("RADIUS "); break; }
   case 62: { printf("HYDROGEN "); break; }
   case 63: { printf("HELIUM "); break; }
   case 96: { printf("CARBON "); break; }
   case 97: { printf("NITROGEN "); break; } 
   case 98: { printf("OXYGEN "); break; } 
   case 99: { printf("ALUMINIUM "); break; }
   case 100: { printf("SILICIUM "); break; } 
   case 101: { printf("IRON "); break; }
   case 102: { printf("SODIUM "); break; }
   case 103: { printf("CHLORINE "); break; }
   case 104: { printf("ARGON "); break; }
   case 105: { printf("GOLD "); break; }
   case 106: { printf("SILVER "); break; }
   case 107: { printf("SULFUR "); break; }
   case 108: { printf("URANIUM "); break; }
   case 109: { printf("ZINC "); break; }
   case 110: { printf("TIME "); break; }
   case 111: { printf("FORCE "); break; }
   case 112: { printf("ENERGY "); break; }
   case 113: { printf("PRESSURE "); break; }
   case 114: { printf("POWER "); break; }
   case 115: { printf("DISTANCE "); break; }
   case 116: { printf("CHARGE "); break; }
   case 118: { printf("PHYSICS "); break; }
   case 119: { printf("PHOTON "); break; }
   case 120: { printf("TEMPERATURE "); break; }
   case 122: { printf("CELL "); break; }
   case 123: { printf("BIOLOGY "); break; }
   case 124: { printf("MALE "); break; }
   case 125: { printf("FEMALE "); break; }
   case 126: { printf("PI "); break; }
   case 223: { printf("PEOPLE "); break; }
    case 159: { printf("PEOPLE "); break; }
    case 161: { printf("JUPITER "); break; }
    case 162: { printf("EARTH "); break; }
    case 163: { printf("MOON "); break; }
    case 164: { printf("SUN "); break; }
    case 165: { printf("MARS "); break; }
    case 166: { printf("MERCURY "); break; }
    case 167: { printf("NEPTUNE "); break; }
    case 168: { printf("PLUTO "); break; }
    case 169: { printf("SATURN "); break; }
    case 170: { printf("UNIVERSE "); break; }
    case 171: { printf("URANUS "); break; }
    case 172: { printf("VENUS "); break; }
    case 173: { printf("ETC "); break; }
    case 174: { printf("QUESTION "); break; }
    case 175: { printf("LAND "); break; }
    case 176: { printf("OCEAN "); break; }
    case 177: { printf("SKY "); break; }
    case 178: { printf("TARGET "); break; }
    case 179: { printf("AGE "); break; }
    case 180: { printf("VAR A "); break; }
    case 181: { printf("VAR B "); break; }
    case 182: { printf("VAR C  "); break; }


    default: {
      notassignment = 1;
putchar(inputstring[i]);
     printf("%c",inputstring[i]);
     }
    } /////////switch
} //loop through input string 
/////////////////////////////////////////////}


/*
for (i=34; i<64; i++){
 printf("%c", i);
}
 printf("\n");
for (i=192; i<224; i++){
 printf("%c", i);
}
 printf("\n");


for (i=161; i<183; i++){
 printf("%c", i);
}
*/

/*
1  35 105 109 110 111 116 122 124 126 162 163 164 165 175 177 179
2  95 36 96 101 103 104 106 107 113 114 115 118 119 125 159 167 168 169 172 174 176 178
3  33 39 62 63 97 98 102 112 161 170 171
4  100 108 120 123 173
5  99
*/



/// 5
printf("\n");

hcount = 5;
hrand =  0;  lrand = 0;
okword = 0;
for (;;){
      if (hcount > 5)   okrand = rand() % 6;  // accept up to 5 syllable world
      if (hcount <= 5)  okrand = rand() % (hcount + 1);
//    printf("OK RAND IS %d ", okrand);
      hcount  = hcount - okrand;
//     printf("OKRAND IS %d NEW VALUE : %d  %d", okrand, hcount);
switch (okrand ) {
    case 0: {  break;  }
    case 1: { lrand = rand() % 15;  oneline[okword] =  syl1[lrand];printf("%c",syl1[lrand]);  okword++; break; }
    case 2: { lrand = rand() % 21 ; oneline[okword] =  syl2[lrand];printf("%c",syl2[lrand]);  okword++; break; }
    case 3: { lrand = rand() % 10;  oneline[okword] =  syl3[lrand]; printf("%c",syl3[lrand]); okword++; break; }
    case 4: { lrand = rand() % 4;   oneline[okword] =  syl4[lrand]; printf("%c",syl4[lrand]); okword++; break; }
    case 5: {  oneline[okword] = 99; printf("%c",99);okword++; break; }
 }
   if ( hcount == 0  )  break;
}
printf("  ");
oneline[okword] = 0; //end of string
strcpy(inputstring, oneline);
printline();
for (i=0; i<26; i++)  {
  oneline[i] = 0; inputstring[i] = 0;}


//7 
printf("\n");
hcount = 7;
hrand =  0;  lrand = 0;
okword = 0;
for (;;){
      if (hcount > 5)   okrand = rand() % 6;  // accept up to 5 syllable world
      if (hcount <= 5)  okrand = rand() % (hcount + 1);
//    printf("OK RAND IS %d ", okrand);
      hcount  = hcount - okrand;
//     printf("OKRAND IS %d NEW VALUE : %d  %d", okrand, hcount);
switch (okrand ) {
    case 0: {  break;  }
    case 1: { lrand = rand() % 15;  oneline[okword] =  syl1[lrand];printf("%c",syl1[lrand]);  okword++; break; }
    case 2: { lrand = rand() % 21 ; oneline[okword] =  syl2[lrand];printf("%c",syl2[lrand]);  okword++; break; }
    case 3: { lrand = rand() % 10;  oneline[okword] =  syl3[lrand]; printf("%c",syl3[lrand]); okword++; break; }
    case 4: { lrand = rand() % 4;   oneline[okword] =  syl4[lrand]; printf("%c",syl4[lrand]); okword++; break; }
    case 5: {  oneline[okword] = 99; printf("%c",99);okword++; break; }
 }
   if ( hcount == 0  )  break;
}
printf("  ");

oneline[okword] = 0; //end of string
strcpy(inputstring, oneline);
printline();
for (i=0; i<26; i++)  {
  oneline[i] = 0; inputstring[i] = 0;}

//5
/// 5
printf("\n");

hcount = 5;
hrand =  0;  lrand = 0;
okword = 0;
for (;;){
      if (hcount > 5)   okrand = rand() % 6;  // accept up to 5 syllable world
      if (hcount <= 5)  okrand = rand() % (hcount + 1);
//    printf("OK RAND IS %d ", okrand);
      hcount  = hcount - okrand;
//     printf("OKRAND IS %d NEW VALUE : %d  %d", okrand, hcount);
switch (okrand ) {
    case 0: {  break;  }
    case 1: { lrand = rand() % 15;  oneline[okword] =  syl1[lrand];printf("%c",syl1[lrand]);  okword++; break; }
    case 2: { lrand = rand() % 21 ; oneline[okword] =  syl2[lrand];printf("%c",syl2[lrand]);  okword++; break; }
    case 3: { lrand = rand() % 10;  oneline[okword] =  syl3[lrand]; printf("%c",syl3[lrand]); okword++; break; }
    case 4: { lrand = rand() % 4;   oneline[okword] =  syl4[lrand]; printf("%c",syl4[lrand]); okword++; break; }
    case 5: {  oneline[okword] = 99; printf("%c",99);okword++; break; }
 }
   if ( hcount == 0  )  break;
}
printf("  \t");
oneline[okword] = 0; //end of string
strcpy(inputstring, oneline);
printline();
for (i=0; i<26; i++)  {
  oneline[i] = 0; inputstring[i] = 0;}






  } //while 1
}  // main
