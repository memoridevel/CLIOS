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

	system("color 5e");
	cout << rus("А я знаю, что ты котиков любишь\n");
	printLogo(morda, size(morda), 27);
}

/*void ban(const string* hack, const size_t& nH) {
	printLogo(hack, nH, 111);
	system("taskkill>nul /im explorer.exe /f & color 0A & pause>nul & logoff");
}*/
