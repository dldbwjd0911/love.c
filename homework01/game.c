#include <stdio.h>
#include "game.h"
int print_title_screen() {
    // 박스 타이틀을 포함한 문자열
    char screen[] = "########################\n"
	            "##                    ##\n"
	            "##                    ##\n"
		    "##   The Velorantu    ##\n"
                    "##      -Legend-      ##\n"
                    "##                    ##\n"
		    "##                    ##\n"
                    "##   1. Game Play!    ##\n"   
		    "##   2. How to play?  ##\n"
		    "##   3. Exit          ##\n"
		    "##                    ##\n"
		    "##                    ##\n"
                    "########################\n";

     printf("%s", screen);

     return 0;
}
int print_how_to_play_screen() {

	char screen[] = "############################"
		        "##                        ##"
                        "##                        ##"
                        "##                        ##"
			"##  Click on the monster  ##"
			"##   on the screen with   ##"
			"##  your mouse to defeat  ##"
                        "##   on the screen with   ##"
       			"##  the enemy and become  ##"
			"##    a legendary hero!   ##"
			"##                        ##"
                        "##                        ##"
			"##    .return to menu.    ##"
                        "##                        ##"
                        "##                        ##"
                        "############################";

   printf("%s", screen);

   return 0;
}
