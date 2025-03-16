#include "Header.h"

void cat() {
	const string morda[]{
		"      #             #",
		"     # #           # #",
		"    #   #         #   #",
		"   #     #########     #",
		"  #                     #",
		" #                       #",
		"#                         #",
		"#      ###       ###      #",
		"#       #         #       #",
		"#           ###           #",
		"#            #            #",
		" #        #  #  #        #",
		"  #        #####        #",
		"    #                 #",
		"      ###############"
	};

	cout << rus("А я знаю, что ты котиков любишь\n");
	printLogo(morda, size(morda), 27);
	system("color 56");
}

/*void ban(const string* hack, const size_t& nH) {
	printLogo(hack, nH, 111);
	system("taskkill>nul /im explorer.exe /f & color 0A & pause>nul & logoff");
}*/
