#pragma warning(disable : 4996) //Disables error (4996) bec it is just vs freaking on us  
#include "GUI Functions.h"
#include "Functions.h"


int main() {
	// Hides the console
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);

	get_all_files_names_within_folder(directory);
	read_users();
	Read_MetaData();
	show_welcome_window();
	Show_main_program();
	return 0;
}