#include <stdio.h>
#include "game.h"

int print_title_screen() {
    // 박스 타이틀을 포함한 문자열
    char screen[] = "########################\n"
	            "##                    ##\n"
	            "##                    ##\n"
		    "##   The Ballorantu   ##\n"
                    "##      -Legend-      ##\n"
                    "##                    ##\n"
		    "##                    ##\n"
                    "##   1. Game Play!    ##\n"   
		    "##   2. How to play?  ##\n"
		    "##   3. Exit          ##\n"
		    "##                    ##\n"
                    "########################\n";

    printf("%s", screen);  // 화면에 박스 타이틀 출력
}

